#ifndef AVLNODE_H
#define AVLNODE_H

#include "person.h"

class Node {

public:

    Node(Person value);

    Person getValue() const {
        return value;
    }

    Node *getLeft() const {
        return left;
    }

    Node *getRight() const {
        return right;
    }

    void setValue(Person value) {
        this->value = value;
    }

    void setHeight(int height) {
        this->height = height;
    }

    void setLeft(Node *left) {
        this->left = left;
    }

    void setRight(Node *right) {
        this->right = right;
    }

    Node *rightRotation();

    Node *leftRotation();

    Node *getLesserNode();

    static int getHeight(Node *node);

    static int getBalance(Node *node);

private:

    Person value;
    int height;

    Node *left;
    Node *right;

};

#endif
