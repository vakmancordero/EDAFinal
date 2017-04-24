#include "person.h"

Person::Person() {

}

Person::Person(QString name, int age) {
    this->name = name;
    this->age = age;
}

QString Person::getName() {
    return this->name;
}

void Person::setName(QString name) {
    this->name = name;
}

int Person::getAge() {
    return this->age;
}

void Person::setAge(int age) {
    this->age = age;
}

int Person::compareTo(Person person) {

    int result = QString::compare(this->name, person.getName(), Qt::CaseInsensitive);

    if (result == 0) {

        if (this->age == person.getAge()) {

            return 0;

        } else {

            if (this->age < person.getAge()) {

                return -1;

            } else {

                return 1;

            }

        }

    } else {

        return result;

    }

}

QString Person::toString() {
    return this->name + " - " + QString::number(this->age);
}
