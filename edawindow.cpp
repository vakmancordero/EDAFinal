#include "edawindow.h"
#include "ui_edawindow.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <iostream>

#include "quicksort.h"

using namespace std;

EDAWindow::EDAWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::EDAWindow) {

    ui->setupUi(this);
}

EDAWindow::~EDAWindow() {
    delete ui;
}

void EDAWindow::on_actionSalir_triggered() {
    QCoreApplication::quit();
}

void EDAWindow::on_pathButton_clicked() {

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "C:\\", tr("Text Files (*.txt *.docx)"));

    if (!fileName.isEmpty() && !fileName.isNull()) {

        QMessageBox::about(this, "Selected file", fileName);

        ui->pathLine->setText(fileName);

    }

}

void EDAWindow::on_addAllButton_clicked() {

    QString text = ui->pathLine->text();

    if (!text.isEmpty()) {

        QFile inputFile(ui->pathLine->text());

        int counter = 0;

        if (inputFile.open(QIODevice::ReadOnly)) {

           QuickSort<Person> quickSort;

           QTextStream in(&inputFile);

           while (!in.atEnd()) {

               QStringList lineSplit = in.readLine().trimmed().split(";");

               Person person(
                       lineSplit.at(0).trimmed(),
                       lineSplit.at(1).trimmed().toInt()
               );

               this->personsList.add(person);

               counter++;

           }

           for (int i = 0; i < personsList.size(); i++) {
               qDebug() << personsList.get(i).toString() << endl;
           }

           quickSort.quickSort(
                   this->personsList, 0,
                   this->personsList.size() - 1
           );

           for (int i = 0; i < personsList.size(); i++) {
               qDebug() << personsList.get(i).toString() << endl;
           }

           inputFile.close();

        } else {

            QMessageBox::critical(this, "Error", "Archivo incorrecto.");

        }

        QDateTime currentDateTime = QDateTime::currentDateTime();

    } else {

        QMessageBox::critical(this, "Error", "Por favor, introduzca la ruta de un archivo.");

    }

}
