/******************************************************************************************************************************************
    Класс "Поисковый класс" - SearchServer. Класс, реализующий поиск во всех классах, где стоит такая задача
    Поля класса:
    //NOTE -  v 1.0

    Методы класса:
z    //NOTE -  v 1.0

*******************************************************************************************************************************************/
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iterator>

#include "../lib.h"
#include "string_processing.h"

using namespace std;

const int MAX_RESULT_DOCUMENT_COUNT = 5;
const double EPSILON = 1e-6;

struct Document
{
    int index;
    vector<string> comparable_words;
    double relevance; /** -1 - означает, что в запросе было одно слово
                           0 - слово из запроса не присутствует в документе ни в каком виде
                          >0 - стандартный поиск*/
};


class SearchServer
{
private:
    
    std::set<std::string> stop_words_;//TODO - подумать что может брать в качестве стоп-слов и как их добавлять

    //обработанные слова документов - слово из документа и соответствующий ему словарь 
    //индексов документов, где встречается, и TF - как часто встречается
    std::map<std::string, std::map<int, double>> word_to_document_freqs_;
    
    //множество индексов документов, присутствующих в сервере
    std::set<int> document_indexes;

    struct QueryWord
    {
        std::string data;
        bool is_minus;
        bool is_stop;
    };

    struct Query
    {
        std::set<std::string> plus_words;
        std::set<std::string> minus_words;
    };

public:
    SearchServer() = default;

    template <typename StringContainer>
    explicit SearchServer(const StringContainer &stop_words);

    SearchServer(const std::string &stop_words_text)
        : SearchServer(SplitIntoWords(stop_words_text))
    {
        if (!IsValidWord(stop_words_text))
            throw std::invalid_argument("Ошибка инициализации");
    }

    void AddDocument(const vector<string>& documents);

    /*! @brief Найти лучшие документы */
    std::vector<Document> FindTopDocuments(const std::string &raw_query) const;


private:
    bool IsStopWord(const std::string &word) const;

    static bool IsValidWord(const std::string &word);

    // Разделить на слова без стоп-слов
    std::vector<std::string> SplitIntoWordsNoStop(const string& documents) const;

    // Разобрать слово запроса
    QueryWord ParseQueryWord(std::string text) const ;

    // разобрать запрос
    Query ParseQuery(const std::string &text) const;

    // Вычислить Word Inverse DocumentFreq
    double ComputeWordInverseDocumentFreq(const std::string &word) const;

    // найти все документы
    std::vector<Document> FindAllDocuments(const Query &query) const;
};


template <typename StringContainer>
SearchServer::SearchServer(const StringContainer &stop_words)
{
    std::set<std::string> non_empty_strings;
    for (const std::string &str : stop_words)
    {
        if (!IsValidWord(str))
            throw std::invalid_argument("Ошибка инициализации");

        if (!str.empty())
        {
            non_empty_strings.insert(str);
        }
    }
    stop_words_ = non_empty_strings;
}

std::ostream &operator<<(std::ostream &os, const Document &document);

