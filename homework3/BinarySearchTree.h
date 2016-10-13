#ifndef _BINARYSEARCHTREE_H_
#define _BINARYSEARCHTREE_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node;
typedef struct Node Node;

struct BinarySearchTree;
typedef struct BinarySearchTree BinarySearchTree;

typedef int (*CompareFunction)(void *, void *);

BinarySearchTree *createBinarySearchTree(size_t keySize, size_t valueSize);
void freeBinarySearchTree(BinarySearchTree *binarySearchTree);

int addElement(BinarySearchTree *binarySearchTree, void *key, void *value, CompareFunction compareFunction);
int setElement(BinarySearchTree *binarySearchTree, void *key, void *value);
int removeElement(BinarySearchTree *binarySearchTree, void *key);
void *getElementValue(BinarySearchTree *binarySearchTree, void *key);

int isExist(BinarySearchTree *binarySearchTree, void *key);
int isExistNode(Node *node, void *key, size_t keySize);

size_t getKeySize(BinarySearchTree * binarySearchTree);
size_t getValueSize(BinarySearchTree * binarySearchTree);

#endif //_BINARYSEARCHTREE_H_
