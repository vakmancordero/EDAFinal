#ifndef PERSON_H
#define PERSON_H

#include <QDebug>

class Person {

public:

    Person();

    Person(QString name, int edad);

    QString getName();
    void setName(QString name);

    int getAge();
    void setAge(int age);

    int compareTo(Person person);

    QString toString();

private:
    QString name;
    int age;

};

#endif // PERSON_H
