#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <QFile>

#define SIZE 10

using namespace  std;

class HashTable {

    struct Nodo {
        string data;
        int listPosition;
        struct Nodo *next;
    };

    struct Lista {
        struct Nodo *header = NULL;
        int size;
    };

public:

    HashTable();

    struct Lista list[SIZE];

    int cont = 0;
    int collisionsBy = 0;

    int maxLength = 0;
    int comparisons = 0;
    float averageLength = 0;
    int tablePosition;
    int chainingPosition;
    bool secondFlag = false;

    void insert(string dato, int pos);
    void print();
    void loadTable(QFile data, QFile fileExport, QString method);

    int AritmeticaModular(string nombre);
    int Plegamiento(string nombre);
    int MitadDelCuadrado(string nombre);
    int MetodoDeLaMultiplicacion(string nombre);
    int Truncamiento(string nombre);

    void find(string buscarME, int posTabla);
    bool remove(int tablaRemoveChato, int posicion);
    void lengths(QFile data);
};


#endif // HASHTABLE_H
