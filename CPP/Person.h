#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person {
public:
    std::string name;
    int age;

    Person(std::string name, int age) {
        this->name = name;
        this->age = age;
    }
};


#endif //PERSON_H
