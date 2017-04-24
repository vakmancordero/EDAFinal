#include "edawindow.h"
#include "ui_edawindow.h"

#include "quicksort.h"
#include "binarysearch.h"

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

           QTextStream in(&inputFile);

           QuickSort<Person> quickSort;

           QStringList items;
           items << tr("Aritmetica modular") << tr("Plegamiento");
           items << tr("Mitad del cuadrado") << tr("Multiplicacion") << tr("Truncamiento");

           bool ok;

           QString item = QInputDialog::getItem(
                    this, tr("Cuadro de diálogo"),
                    tr("Función de dispersión:"), items, 0, false, &ok
           );

           QFile data("file.csv");

           if(data.open(QFile::WriteOnly | QFile::Truncate)) {

               QTextStream output(&data);

               output << "Funcion:" << ";" << item << endl;

               output << "Sol. Colisiones:" << ";" << "Encadenamiento" << endl;

               output << "Dataset:" << ";" << "" << endl;

               output << "Tipo:" << ";" << "String" << ";" << "Integer" << endl;

               if (ok && !item.isEmpty()) {

                   this->hashTable.collisionsBy = 0;

                   qDebug() << item << endl;

                   while (!in.atEnd()) {

                       QStringList lineSplit = in.readLine().trimmed().split(";");

                       Person person(
                               lineSplit.at(0).trimmed(),
                               lineSplit.at(1).trimmed().toInt()
                       );

                       string name = person.getName().trimmed().toStdString();

                       int position;

                       if (item == "Aritmetica modular") {
                           position = this->hashTable.AritmeticaModular(name);
                       } else if(item == "Plegamiento") {
                           position = this->hashTable.Plegamiento(name);
                       } else if(item == "Mitad del cuadrado") {
                           position = this->hashTable.MitadDelCuadrado(name);
                       } else if(item == "Multiplicacion") {
                           position = this->hashTable.MetodoDeLaMultiplicacion(name);
                       } else if(item == "Truncamiento") {
                           position = this->hashTable.Truncamiento(name);
                       }

                       this->hashTable.insert(name, position);
                       this->personsList.add(person);
                       this->binaryTreeAVL.add(person);

                       cout << "Here: " << person.toString().toStdString() << " - " << position << endl;

                       counter++;

                   }

                   quickSort.quickSort(
                           this->personsList, 0,
                           this->personsList.size() - 1
                   );

                   //this->hashTable.print();

                   QMessageBox::about(this, "Tamaño de la lista", QString::number(this->personsList.size()));

                   /*
                   for (int i = 0; i < personsList.size(); i++) {
                       qDebug() << personsList.get(i).toString() << endl;
                   }
                   */

                   inputFile.close();

               }

           }

        } else {

            QMessageBox::critical(this, "Error", "Archivo incorrecto.");

        }

        QDateTime currentDateTime = QDateTime::currentDateTime();

    } else {

        QMessageBox::critical(this, "Error", "Por favor, introduzca la ruta de un archivo.");

    }

}

void EDAWindow::on_actionInsertar_triggered() {

    QuickSort<Person> quickSort;

    Person person = this->getPerson();

    if (person.getName() != "") {

        this->personsList.add(person);

        this->binaryTreeAVL.add(person);

        quickSort.quickSort(
                this->personsList, 0,
                this->personsList.size() - 1
        );

        QMessageBox::about(this, "Tamaño de la lista", QString::number(this->personsList.size()));

    }

}

void EDAWindow::on_actionEliminar_triggered() {

    if (this->personsList.size() > 0) {

        Person person = this->getPerson();

        if (person.getName() != "") {

            qDebug() << person.toString() << endl;

            int resultIndex = this->findPerson(person);

            if (resultIndex >= 0) {

                QuickSort<Person> quickSort;

                cout << "Index donde se haya: " << resultIndex << endl;

                this->personsList.remove(resultIndex);

                quickSort.quickSort(
                        this->personsList, 0,
                        this->personsList.size() - 1
                );

                this->binaryTreeAVL.remove(person);

                QMessageBox::about(
                        this, "Información",
                        "Persona eliminada de la lista!\n" +
                        this->personsList.get(resultIndex).toString()
                );

            } else {

                QMessageBox::about(
                    this, "Información",
                    "Persona no encontrada"
                );

            }

        } else {

            QMessageBox::about(
                this, "Información",
                "Persona no valida, inténtelo de nuevo"
            );

        }

    } else {

        QMessageBox::about(
            this, "Información",
            "Aún no existen elementos que manipular"
        );

    }

}

void EDAWindow::on_actionBuscar_triggered() {

    if (this->personsList.size() > 0) {

        Person person = this->getPerson();

        if (person.getName() != "") {

            int resultListSearch = this->findPerson(person);

            Node *resultAVLSearch = binaryTreeAVL.find(person);

            /*      */

            QStringList items;
            items << tr("Aritmetica modular") << tr("Plegamiento");
            items << tr("Mitad del cuadrado") << tr("Multiplicacion") << tr("Truncamiento");

            bool ok;

            QString item = QInputDialog::getItem(
                     this, tr("Cuadro de diálogo"),
                     tr("Función de dispersión:"), items, 0, false, &ok
            );

            string name = person.getName().trimmed().toStdString();

            int position;

            if (item == "Aritmetica modular") {
                position = this->hashTable.AritmeticaModular(name);
            } else if(item == "Plegamiento") {
                position = this->hashTable.Plegamiento(name);
            } else if(item == "Mitad del cuadrado") {
                position = this->hashTable.MitadDelCuadrado(name);
            } else if(item == "Multiplicacion") {
                position = this->hashTable.MetodoDeLaMultiplicacion(name);
            } else if(item == "Truncamiento") {
                position = this->hashTable.Truncamiento(name);
            }

            this->hashTable.find(name, position);

            /*      */

            if (resultListSearch >= 0 && resultAVLSearch != NULL) {

                QMessageBox::about(
                        this, "Información",
                        "Persona encontrada en la lista! \n" +
                        this->personsList.get(resultListSearch).toString()
                );

            } else {

                QMessageBox::about(
                    this, "Información",
                    "Persona no encontrada!"
                );

            }

        }

    } else {

        QMessageBox::about(
            this, "Información",
            "Aún no existen elementos que manipular"
        );

    }

}


Person EDAWindow::getPerson() {

    bool ok;
    QInputDialog* inputDialog = new QInputDialog();
    inputDialog->setOptions(QInputDialog::NoButtons);

    QString name = inputDialog->getText(
                NULL, "Introducir datos",
                "Nombre de la persona:", QLineEdit::Normal,
                NULL, &ok
    );

    if (ok && !name.isEmpty()) {

        int age = QInputDialog::getInt(this, "Introducir datos", "Edad de la persona:");

        Person person(name, age);

        return person;

    } else {

        Person person("", 0);

        return person;

    }

}

int EDAWindow::findPerson(Person person) {

    BinarySearch<Person> binarySearch;

    return binarySearch.binarySearch(this->personsList, person);

}
