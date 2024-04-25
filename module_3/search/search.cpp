#include <cmath>
#include <algorithm>

#include "search.h"
#include "string_processing.h"

void SearchServer::AddDocument(const vector<string> &documents)
{
    if (documents.size() == 0)
    {
        throw std::invalid_argument{"Невозможно добавить документ"};
    }

    for (size_t i = 0; i < documents.size(); i++)
    {
        const std::vector<std::string> words = SplitIntoWordsNoStop(documents[i]);
        const double inv_word_count = 1.0 / words.size();

        for (const std::string &word : words)
        {
            word_to_document_freqs_[word][i] += inv_word_count;
        }

        document_indexes.insert(i);
    }
}

std::vector<std::string> SearchServer::SplitIntoWordsNoStop(const string &documents) const
{
    std::vector<std::string> words;
    for (const std::string &word : SplitIntoWords(documents))
    {
        if (!IsStopWord(word))
        {
            words.push_back(word);
        }
    }

    return words;
}

bool SearchServer::IsStopWord(const std::string &word) const
{
    return stop_words_.count(word) > 0;
}

std::vector<Document> SearchServer::FindTopDocuments(const std::string &raw_query) const
{
    const Query query = ParseQuery(raw_query);
    auto matched_documents = FindAllDocuments(query);

    sort(matched_documents.begin(), matched_documents.end(),
         [](const Document &lhs, const Document &rhs)
         {  
            if (lhs.relevance <= 0 )
            {
                return lhs.index < rhs.index;;
            }
            else
                return lhs.relevance > rhs.relevance || (abs(lhs.relevance - rhs.relevance) < EPSILON);
         });

    if (matched_documents.size() > MAX_RESULT_DOCUMENT_COUNT)
    {
        matched_documents.resize(MAX_RESULT_DOCUMENT_COUNT);
    }
    return matched_documents;
}

SearchServer::Query SearchServer::ParseQuery(const std::string &text) const
{
    Query query;
    std::vector<std::string> words = SplitIntoWords(text);

    for (const std::string &word : words)
    {
        const QueryWord query_word = ParseQueryWord(word);
        if (!query_word.is_stop)
        {
            if (query_word.is_minus)
            {
                query.minus_words.insert(query_word.data);
            }
            else
            {
                query.plus_words.insert(query_word.data);
            }
        }
    }
    return query;
}

SearchServer::QueryWord SearchServer::ParseQueryWord(std::string text) const
{
    bool is_minus = false;
    // Word shouldn't be empty
    if (text[0] == '-')
    {
        if ((text[1] == '-') || (text == "-") || !IsValidWord(text))
        {
            throw std::invalid_argument("Ошибка в запросе");
        }

        is_minus = true;
        text = text.substr(1);
    }
    if (!IsValidWord(text))
    {
        throw std::invalid_argument("Ошибка в запросе");
    }
    return {
        text,
        is_minus,
        IsStopWord(text)};
}

bool SearchServer::IsValidWord(const std::string &word)
{
    // A valid word must not contain special characters
    return none_of(word.begin(), word.end(), [](char c)
                   { return c >= '\0' && c < ' '; });
}

std::vector<Document> SearchServer::FindAllDocuments(const Query &query) const
{
    std::vector<Document> matched_documents;
    std::map<int, double> document_to_relevance;
    std::map<int, vector<string>> document_to_comparable_words;

    if (query.plus_words.size() == 1)
    {
        const string &str_query = *(query.plus_words.begin());

        for (const auto &[str, index_and_TF] : word_to_document_freqs_)
        {
            if (str.find(str_query) != string::npos)
            {
                for (const auto &[index, TF] : index_and_TF)
                    document_to_comparable_words[index].push_back(str);
            }
        }

        for (const auto [document_id, comparable_words] : document_to_comparable_words)
        {
            matched_documents.push_back({document_id, comparable_words, -1});
        }
    }
    else
    {
        for (const std::string &word : query.plus_words)
        {
            if (word_to_document_freqs_.count(word) == 0)
            {
                continue;
            }

            const double inverse_document_freq = ComputeWordInverseDocumentFreq(word);
            for (const auto [document_id, term_freq] : word_to_document_freqs_.at(word))
            {
                document_to_relevance[document_id] += term_freq * inverse_document_freq;
            }
        }

        for (const std::string &word : query.minus_words)
        {
            if (word_to_document_freqs_.count(word) == 0)
            {
                continue;
            }
            for (const auto [document_id, _] : word_to_document_freqs_.at(word))
            {
                document_to_relevance.erase(document_id);
            }
        }
    }

    for (const auto [document_id, relevance] : document_to_relevance)
    {
        matched_documents.push_back({document_id, {}, relevance});
    }

    return matched_documents;
}

double SearchServer::ComputeWordInverseDocumentFreq(const std::string &word) const
{
    return log(document_indexes.size() * 1.0 / word_to_document_freqs_.at(word).size());
}


std::ostream &operator<<(std::ostream &os, const Document &document)
{
    using namespace std;
    os << "{ "s
       << "document_id = "s << document.index << ", "s
       << "relevance = "s << document.relevance << ", "s
       << "comparable words = "s << document.comparable_words << " }"s;
    return os;
}