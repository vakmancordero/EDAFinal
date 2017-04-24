#ifndef AVL_H
#define AVL_H

#include "Node.h"

#include <QByteArray>
#include <QTextStream>

class BinaryTreeAVL {

public:

    BinaryTreeAVL();

    void add(Person key);
    void remove(Person key);

    void preOrder(Node *root);
    void inOrder(Node *root);
    void postOrder(Node *root);

    void show();

    Node *getRoot() const {
        return root;
    }

    void clear() {
        root = nullptr;
        this->show();
    }

    Node *find(Person value);

    int rr = 0, ll = 0, rl = 0, lr = 0;

    void BinaryTreeAVL::rotaciones();

private:
    Node *add(Node *node, Person value);
    Node *remove(Node *root, Person value);

    QByteArray prepareGraph();
    void graph(Node* node,  QTextStream* stream);

    Node *root;

    Node *find(Person value, Node* node);

};

#endif
