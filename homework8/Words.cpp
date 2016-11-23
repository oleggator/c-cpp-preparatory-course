#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <fstream>
#include <iostream>
#include <cctype>
#include "Words.hpp"

struct isDelimiter {
    bool operator()(char ch) const {
        return std::ispunct(ch) || std::isspace(ch);
    }
};

Words::Words(std::initializer_list<std::string> initializerList) {
    for (const std::string &path: initializerList) {
        std::ifstream file(path);
        std::string fileString;
        file >> std::noskipws >> fileString;

        std::vector<std::string> strings;
        boost::split(strings, fileString, isDelimiter());

        bool isWordInFile = 0;
        for (const std::string& word: strings) {
            if (words.count(word)) {
                
                if (!isWordInFile) {
                    ++words[word];
                } else {
                    isWordInFile = 1;
                }

            } else {
                words.insert(std::pair<std::string, size_t>(path, 1));
            }
        }
    }
}
