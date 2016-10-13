#include "BinarySearchTree.h"

struct BinarySearchTree {
    size_t valueSize;
    size_t keySize;

    Node *root;

    unsigned int elementsCount;
};

struct Node {
    void *key;
    void *value;

    Node *parent;
    Node *left;
    Node *right;
};

Node *findParentElement(Node *node, void *key, size_t keySize);
Node *findNode(Node *parentNode, void *key, size_t keySize);
void freeNodes(Node *node);

BinarySearchTree *createBinarySearchTree(size_t keySize, size_t valueSize) {
    
    BinarySearchTree *binarySearchTree = NULL;
    if( !(binarySearchTree = malloc( sizeof(BinarySearchTree) )) ) {
        printf("Memory allocaton error\n");
        return NULL;
    }

    binarySearchTree->keySize = keySize;
    binarySearchTree->valueSize = valueSize;
    binarySearchTree->root = NULL;
    binarySearchTree->elementsCount = 0;

    return binarySearchTree;
}

void freeBinarySearchTree(BinarySearchTree *binarySearchTree) {
    freeNodes(binarySearchTree->root);

    free(binarySearchTree);
}

int addElement(BinarySearchTree *binarySearchTree, void *key, void *value) {
    if (binarySearchTree->elementsCount == 0) {
        Node *node = NULL;
        if (!( node = malloc(sizeof(Node)) )) {
            printf("Memory allocation error\n");
            return NULL;
        }
        binarySearchTree->root = node;
        node->parent = NULL;
        node->left = NULL;
        node->right = NULL;

        if ( !( node->key = malloc( getKeySize(binarySearchTree) ) ) ) {
            printf("Memory allocation error\n");
            return NULL;
        }

        if ( !( node->value = malloc( getValueSize(binarySearchTree) ) ) ) {
            printf("Memory allocation error\n");
            return NULL;
        }

        memcpy(node->key, key, getKeySize(binarySearchTree));
        memcpy(node->value, value, getValueSize(binarySearchTree));
        binarySearchTree->elementsCount++;
        return 1;
    }

    if (binarySearchTree->elementsCount > 0) {
        Node *parentNode = findParentElement(binarySearchTree->root, key, binarySearchTree->keySize);

        if (memcmp(key, parentNode->key, binarySearchTree->keySize) == 0) {
            printf("Element is exist\n");
            return NULL;
        }

        Node *node = malloc(sizeof(Node));
        if (!node) {
            printf("Memory allocation error");
            return NULL;
        }
        if ( memcmp(key, parentNode->key, binarySearchTree->keySize) > 0) {

            if (!( parentNode->right = malloc(sizeof(Node)) )){
                printf("Memory allocation error\n");
                return NULL;
            }

            parentNode->right = node;
        }

        if ( memcmp(key, parentNode->key, binarySearchTree->keySize) < 0) {

            if (!( parentNode->left = malloc(sizeof(Node)) )){
                printf("Memory allocation error\n");
                return NULL;
            }

            parentNode->left = node;
        }

        if ( !( node->key = malloc( getKeySize(binarySearchTree) ) ) ) {
            printf("Memory allocation error\n");
            return NULL;
        }

        if ( !( node->value = malloc( getValueSize(binarySearchTree) ) ) ) {
            printf("Memory allocation error\n");
            return NULL;
        }

        node->parent = parentNode;
        node->left = node->right = NULL;
        memcpy(node->key, key, binarySearchTree->keySize);
        memcpy(node->value, value, binarySearchTree->valueSize);

        binarySearchTree->elementsCount++;
        return 1;
    }

    return 0;
}

int removeElement(BinarySearchTree *binarySearchTree, void *key) {
    Node *node = findNode(binarySearchTree->root, key, binarySearchTree->keySize);
    if (!node) {
        return NULL;
    }

    Node *left = node->left;
    Node *right = node->right;

    if (!left && !right) {
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = NULL;
                freeNodes(node);
                return 1;
            }

            if (node->parent->right == node) {
                node->parent->right = NULL;
                freeNodes(node);
                return 1;
            }
        } else {
            binarySearchTree->root = NULL;
            free(node->key);
            free(node->value);
            free(node);
        }

        

        printf("Element removing error\n");
        return 0;
    }

    if (left && !right) {
        if (node->parent) {
            if (node->parent->left == node) {
                node->parent->left = left;
            }

            left->parent = node->parent;
        } else {
            binarySearchTree->root = left;
            left->parent = NULL;
        }

        free(node->key);
        free(node->value);
        free(node);
    }

    if (!left && right) {
        if (node->parent) {
            if (node->parent->right == node) {
                node->parent->right = right;
            }

            right->parent = node->parent;
        } else {
            binarySearchTree->root = right;
            right->parent = NULL;
        }


        free(node->key);
        free(node->value);
        free(node);
    }

    return 1;
}

void *getElementValue(BinarySearchTree *binarySearchTree, void *key) {
    return findNode(binarySearchTree->root, key, binarySearchTree->keySize);
}

size_t getKeySize(BinarySearchTree *binarySearchTree) {
    return binarySearchTree->keySize;
}

size_t getValueSize(BinarySearchTree *binarySearchTree) {
    return binarySearchTree->valueSize;
}


// Возращает элемент, дочерним элементом которого может стать элемент с заданным ключом
Node *findParentElement(Node *node, void *key, size_t keySize) {

    if ( memcmp(key, node->key, keySize) == 0) {
        return node;
    }

    if ( memcmp(key, node->key, keySize) > 0) {
        if (node->right == NULL) {
            return node;
        }
        
        return findParentElement(node->right, key, keySize);
    }

    if ( memcmp(key, node->key, keySize) < 0) {
        if (node->left == NULL) {
            return node;
        }

        return findParentElement(node->left, key, keySize);
    }

    return NULL;
}

Node *findNode(Node *parentNode, void *key, size_t keySize) {
    Node *left = parentNode->left;
    Node *right = parentNode->right;

    if (memcmp(parentNode->key, key, keySize) == 0) {
        return parentNode;
    }

    if (left) {
        return findNode(left, key, keySize);
    }

    if (right) {
        return findNode(right, key, keySize);
    }

    printf("Element not found\n");
    return NULL;
}

void freeNodes(Node *node) {
    free(node->key);
    free(node->value);

    if (node->left) {
        freeNodes(node->left);
    }

    if (node->right) {
        freeNodes(node->right);
    }

    free(node);


}

int isExist(BinarySearchTree *binarySearchTree, void *key) {
    return isExistNode(binarySearchTree->root, key, binarySearchTree->keySize);
}

int isExistNode(Node *node, void *key, size_t keySize) {
    if ( memcmp(key, node->key, keySize) == 0) {
        return 1;
    }

    if (!node->left && !node->right) {
        return 0;
    }

    if (node->left) {
        if (memcmp(key, node->key, keySize) < 0){
            return isExistNode(node->left, key, keySize);
        } else {
            return 0;
        }
    }

    if (node->right) {
        if (memcmp(key, node->key, keySize) > 0){
            return isExistNode(node->right, key, keySize);
        } else {
            return 0;
        }
    }

    return 0;
}
