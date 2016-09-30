/*
Вариант 14

Написать программу, которая в качестве аргументов командной строки принимает целое число N (первый аргумент) и имена текстовых файлов (документов).
Необходимо вывести все слова, которые встречаются более чем в N документах (с указанием количества вхождений каждого слова).
Слова во входных файлах разделяются символами, для которых библиотечные функции isspace() или ispunct() возвращают ненулевое значение.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS_COUNT 124
#define MAX_WORDS_COUNT 2048

struct word {
    unsigned int existingCount;
    char string[MAX_CHARS_COUNT];
};

void getWordsFromFile(FILE *const file, struct word words[], unsigned int *const wordsCount);
struct word *getWordStruct(struct word words[], const char *word, unsigned int wordsCount);
int getWordFromFile(FILE *const file, char *const word);
void wordsOutput(struct word words[], unsigned int wordsCount, const unsigned int N);

int main(int argc, char *argv[]) {
    if (argc <= 3) {
        printf("homework [N] [file1 file2 ...]\n");
        return 1;
    }

    struct word words[MAX_WORDS_COUNT] = {};
    unsigned int wordsCount = 0;

    const unsigned int N = (unsigned int)atoi(argv[1]);
    const unsigned int filesCount = (unsigned int)(argc - 2);
    if (!N) {
        printf("homework [N] [file1 file2 ...]\n");
        return 1;
    }

    for (int i = 0; i < filesCount; ++i) {
        FILE *file = fopen(argv[i + 2], "r");
        if (file == NULL) {
            printf("File \"%s\" is not found\n", argv[i + 2]);
            return 2;
        }

        getWordsFromFile(file, words, &wordsCount);

        fclose(file);
    }

    wordsOutput(words, wordsCount, N);
    return 0;
}


// Заполняет структуры word из файла, заданного в качестве параметра
void getWordsFromFile(FILE *const file, struct word words[], unsigned int *const wordsCount) {
    char word[MAX_CHARS_COUNT];
    struct word *wordStruct;
    struct word *currentFileWords[MAX_WORDS_COUNT];
    unsigned int currentFileWordsCount = 0;

    int i = 0;
    while (getWordFromFile(file, word) != EOF) {

        wordStruct = getWordStruct(words, word, *wordsCount);
        int isInCurrentFile = (int)getWordStruct(currentFileWords, word, currentFileWordsCount);

        if (wordStruct) {
            if (!isInCurrentFile) {
                wordStruct->existingCount++;
            }
        } else {
            wordStruct = &(currentFileWords[currentFileWordsCount++]);
            wordStruct->existingCount = 1;
            strcpy(wordStruct->string, word);

            wordStruct = &words[(*wordsCount)++];
            wordStruct->existingCount = 1;
            strcpy(wordStruct->string, word);
        }

        ++i;
    }
}




// Возвращает структуру, содержащее слово, заданное в качестве папраметра
struct word *getWordStruct(struct word words[], const char *word, unsigned int wordsCount) {
    for (int i = 0; i < (int)wordsCount; ++i) {

        if (!strcmp(&(words[i].string), word)) {
            return &words[i];
        }
    }

    return 0;
}

// Аналог fscanf
// Возвращает размер слова без '\0'
int getWordFromFile(FILE *const file, char *const word) {
    int character = 0;
    char currentWord[MAX_CHARS_COUNT];
    unsigned int i = 0;

    for (unsigned int j = 0; j < MAX_CHARS_COUNT - 1; ++j) {
        character = fgetc(file);

        if (character == EOF || isspace(character) || ispunct(character)) {

            if (i == 0) {

                if (character == EOF) {
                    return EOF;
                } else {
                    continue;
                }
            }
            currentWord[i] = '\0';
            strcpy(word, currentWord);
            return (int)i;
        } else {
            currentWord[i++] = (char)character;
        }
    }

    currentWord[i] = '\0';
    strcpy(word, currentWord);
    return (int)i;
}

// Выводит в консоль слова, количество вхлждений которых >= N
void wordsOutput(struct word words[], unsigned int wordsCount, const unsigned int N) {
    struct word *wordStruct;
    for (unsigned int i = 0; i < wordsCount; ++i) {
        wordStruct = &words[i];
        if (wordStruct->existingCount >= N) {
            printf("%s: %d\n", wordStruct->string, wordStruct->existingCount);
        }
    }
}
