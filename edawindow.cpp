#include "edawindow.h"
#include "ui_edawindow.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

#include "person.h"
#include "linkedlist.h"

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

    LinkedList<int> list;

    list.add(3);

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

           QTextStream in(&inputFile);

           while (!in.atEnd()) {

               QStringList lineSplit = in.readLine().trimmed().split(";");

               Person person(
                       lineSplit.at(0).trimmed(),
                       lineSplit.at(1).trimmed().toInt()
               );

               qDebug() << person.toString() << endl;

               /*
               binaryTreeAVL.add(line);

               QString localAppend = QString::number(number).append(";");

               numbers.append(localAppend);
               */

               counter++;

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
