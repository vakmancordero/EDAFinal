#ifndef EDAWINDOW_H
#define EDAWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <iostream>

#include "linkedlist.h"
#include "binarytreeavl.h"
#include "hashtable.h"
#include "person.h"

namespace Ui {
class EDAWindow;
}

class EDAWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit EDAWindow(QWidget *parent = 0);
    ~EDAWindow();

    HashTable hashTable;

    LinkedList<Person> personsList;

    BinaryTreeAVL binaryTreeAVL;

    int findPerson(Person person);

    Person getPerson();

private slots:
    void on_actionSalir_triggered();

    void on_pathButton_clicked();

    void on_addAllButton_clicked();

    void on_actionInsertar_triggered();

    void on_actionEliminar_triggered();

    void on_actionBuscar_triggered();

private:
    Ui::EDAWindow *ui;
};

#endif // EDAWINDOW_H
