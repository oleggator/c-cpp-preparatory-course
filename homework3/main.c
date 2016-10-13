#include <stdio.h>
#include <string.h>

#include "BinarySearchTree.h"

#define MAX_STRING_LENGTH 128

int handleFile(FILE *file);
int printWord(BinarySearchTree * binarySearchTree, char *string);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("homework4 [filename]\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("File \"%s\" is not found\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (!handleFile(file)) {
        
        return EXIT_FAILURE;
    }

    fclose(file);

    return EXIT_SUCCESS;
}

int handleFile(FILE *file) {
    BinarySearchTree *binarySearchTree = createBinarySearchTree( sizeof(char[MAX_STRING_LENGTH]), sizeof(char[MAX_STRING_LENGTH]) );

    while(1) {
        char operator = NULL;
        char word[MAX_STRING_LENGTH];

        if (fscanf(file, "%c %127s\n", &operator, word) != 2) {
            if (feof(file)) {
                break;
            } else {
                freeBinarySearchTree(binarySearchTree);
                return NULL;
            }
        }

        char emptyString[] = "\0";

        switch (operator) {
            case '+': 
                if ( addElement(binarySearchTree, (void *)word, (void *)emptyString) ) {
                    //printf("Element add\n");
                    break;
                } else {
                    printf("Element insertion error\n");
                    freeBinarySearchTree(binarySearchTree);
                    return NULL;
                }

            case '-':
                if ( removeElement(binarySearchTree, (void *)word) ) {
                    //printf("Element remove\n");
                    break;
                } else {
                    printf("Element removing error\n");
                    freeBinarySearchTree(binarySearchTree);
                    return NULL;
                }

            case '?':
                if (printWord(binarySearchTree, (void *)word)){

                    break;
                } else {
                    printf("Element checking error\n");
                    freeBinarySearchTree(binarySearchTree);
                    return NULL;
                }

            default:
                printf("Wrong operator\n");
                freeBinarySearchTree(binarySearchTree);
                return NULL;
        }
    }

    return 1;
}

int printWord(BinarySearchTree *binarySearchTree, char *string) {
    if ( isExist(binarySearchTree, (void *)string) ) {
        printf("YES %s\n", string);
        return 1;
    } else {
        printf("NO %s\n", string);
        return 1;
    }
}
