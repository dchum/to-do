#include <iostream>

#include "search.h"

using namespace std;

int main()
{
    vector<string> date = 
    {
        "Маша пошла гулять в парк",

        "fsdfsd sdfsdf sdf sdsdf Маша было много  деревьев деревьев",

        "Деревья были зелёными",

        "Зелёный цвет листьев радовал глаз глаз",

        "Солнце светило ярко",

        "Ярко светило солнце",

        " Маша Машаcdscsdcsdc было много  деревьев деревьев",

        "Природа была прекрасна. Была хорошая пора",

        "Прекрасен мир вокруг нас глаз",

        " аповапвапрвлаопрвМы должны беречь нашу планету",
    };

    SearchServer search;

    search.AddDocument(date);

    for (const auto tmp : search.FindTopDocuments("Маш"))
    {
        cout << "index: " << tmp.index 
        << " comparable_words: " << tmp.comparable_words 
        << " relevance: " << tmp.relevance 
        << endl; 
    }

}