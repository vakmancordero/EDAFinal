#include "hashtable.h"

#include <QFile>
#include <QTextStream>

HashTable::HashTable() {

}

void HashTable::lengths(QFile data){

    maxLength = 0; averageLength = 0;

    for (int i = 0; i < SIZE; i++){

        if (list[i].size > collisionsBy)

        maxLength = list[i].size;

        averageLength += list[i].size;

    }

    averageLength = averageLength / SIZE;

    if(data.open(QIODevice::WriteOnly | QIODevice::Append)) {

        QTextStream out(&data);

        out << "Longitud Máxima" << ";" << maxLength << endl;
        out << "Longitud Promedio" << ";" << averageLength << endl;

    }
}

void HashTable::find(string value, int position){

    comparisons = 0;

    bool firstFlag = false; secondFlag = false;

    struct Nodo * nodo = list[position].header;

    while (nodo != NULL) {

        if (!firstFlag) {

            comparisons++;
        }

        if (nodo->data.compare(value) == 0) {

            firstFlag = true; secondFlag = true;

            chainingPosition = nodo->listPosition;

            tablePosition = position;

            cout << "Lista: " << position << ", Posicion en la lista: " << nodo->listPosition << ", Valor:" << nodo->data << endl;
        }

        nodo = nodo->next;

    }

}


void HashTable::loadTable(QFile data, QFile fileExport, QString method){

    if (data.open(QIODevice::ReadOnly)) {

        QTextStream in(&data);

        if(fileExport.open(QIODevice::WriteOnly | QIODevice::Append)) {

            QTextStream out(&fileExport);

            int counter = 0;

            while (!in.atEnd()) {

                QStringList lineSplit = in.readLine().trimmed().split(";");
                string name = lineSplit.at(0).trimmed().toStdString();

                counter++;

            }

            out << "Total de Elementos:" << counter << endl;

        }

    }

}


int HashTable::AritmeticaModular(string nombre) {
  int posicion = 0;
  int ascii;
  int i = 0;
    char *c = new char[nombre.length()];
    strcpy(c,nombre.c_str());
    while((ascii = c[i++]))
        posicion += ascii;
    posicion = posicion % SIZE;
    return posicion;
}
int HashTable::Plegamiento(string nombre){

    int posicion = 0;
    int ascii;
    int i = 0;

    char *c = new char[nombre.length()];
    strcpy(c,nombre.c_str());
    while((ascii=c[i++]))
        posicion += ascii;
    // int a string
    ostringstream convert;
    convert << posicion;
    nombre = convert.str();

    string uno = "";
    string dos = "";

    char *y = new char[nombre.length() + 1];
    strcpy(y, nombre.c_str());

    posicion = 0;
    for(int x = 0; x < nombre.length(); x++){
        uno.push_back(y[x]);
        posicion += atoi(uno.c_str());
        uno = "";
    }
    posicion = posicion % SIZE;
    cout<<"  salida  "<<posicion<<"\n"<<endl;
    return posicion;
}
int HashTable::MitadDelCuadrado(string nombre){
    int posicion = 0;
    int ascii;
    int i = 0;

    char *c = new char[nombre.length()];
    strcpy(c,nombre.c_str());
    while((ascii=c[i++]))
        posicion += ascii;

    posicion = posicion * posicion;

    ostringstream convert;
    convert << posicion;
    nombre = convert.str();

    string salida;
    char *y = new char[nombre.length() + 1];
    strcpy(y, nombre.c_str());

    salida.push_back(y[(nombre.length()-6)]);
    salida.push_back(y[(nombre.length()-5)]);
    salida.push_back(y[(nombre.length()-4)]);
    posicion = atoi(salida.c_str());
    posicion = posicion % SIZE;

    //cout<<"accii  "<<nombre<<"  salida  "<<posicion<<"\n"<<endl;
    return posicion;
}
int HashTable::MetodoDeLaMultiplicacion(string nombre){
    float r = 0.6180334;
    float posicion = 0;
    int ascii;
    int i = 0;
    char *c = new char[nombre.length()];
    strcpy(c,nombre.c_str());
    while((ascii=c[i++]))
        posicion += ascii;
    posicion = r * posicion;
    int auxPos = posicion;
    posicion = posicion - auxPos;
    posicion = SIZE * posicion;
    auxPos = posicion;
    return auxPos;
}
int HashTable::Truncamiento(string nombre){
    int posicion = 0;
    int ascii;
    int i = 0;

    char *c = new char[nombre.length()];
    strcpy(c,nombre.c_str());

    while((ascii = c[i++]))
        posicion += ascii;

    ostringstream convert;
    convert << posicion;
    nombre = convert.str();

    char *y = new char[nombre.length() + 1];
    strcpy(y, nombre.c_str());

    string posicionAux;

    posicionAux.push_back(y[(nombre.length()-4)]);
    posicionAux.push_back(y[(nombre.length()-2)]);
    posicionAux.push_back(y[(nombre.length()-1)]);

    posicion = atoi(posicionAux.c_str()) % SIZE;
    posicion = posicion % SIZE;
    cout<<"accii  "<<nombre<<"  salida  "<<posicion<<"\n"<<endl;
    return posicion;
}

void HashTable::insert(string value, int position) {

    Nodo *temp = new Nodo();

    if (temp == NULL)
        printf( "No hay Memoria\n");

    temp->data = value;
    temp->listPosition = list[position].size + 1;

    if (list[position].header == NULL) {

        list[position].header = temp;

        list[position].size++;

    } else {

        collisionsBy++;

        struct Nodo *reco = list[position].header;

        for (int i = 1; i < list[position].size; i++) {
            if (reco->next != NULL) {
                reco = reco->next;
            }
        }

        temp->next = NULL;
        reco->next = temp;

        list[position].size++;
    }
}

void HashTable::print() {

    for(int i = 0; i < SIZE; i++){

        struct Nodo *walk = list[i].header;

        if (walk != NULL) {

            while (walk != NULL) {

                cout << " [" << walk->data << "] ";

                walk = walk->next;

            }

            cout << endl << endl;

        } else {

            cout << "[NULL]" << endl << endl;

        }

    }

}

bool HashTable::remove(int tableData, int posicion) {

    //cout << "table data: " << tableData << ", posicion en su lista " << posicion << endl;

    if (posicion < 1 || posicion > list[tableData].size) {

        return false;

    }

    struct Nodo *recorrer = list[tableData].header;

    if (posicion == 1) {

        if(recorrer->next == NULL) {

            list[tableData].header = NULL;

            list[tableData].size--;

            return true;

        } else {

            struct Nodo *aux = recorrer->next;

            list[tableData].header = aux;

            list[tableData].size--;

            return true;

        }

    }

    for (int i = 2; i < posicion; i++) {

        if (recorrer->next == NULL) {

            return false;

        }

        recorrer = recorrer->next;

    }

    recorrer->next = recorrer->next->next;

    list[tableData].size--;

    return true;
}
