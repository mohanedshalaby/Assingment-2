#include <iostream>
#include "Person.h"

Person::Person()
{
}

Person::Person(string _name, int _id, int _age)
{
    name = _name;
    id = _id;
    age = _age;
}

void Person::setName(string _name)
{
    name = _name;
}

void Person::setId(int _id)
{
    id = _id;
}

void Person::setAge(int _age)
{
    age = _age;
}

string Person::getName()
{
    return name;
}

int Person::getId()
{
    return id;
}

int Person::getAge()
{
    return age;
}

void Person::print()
{
    cout << "Name = " << name << endl;
    cout << "Age = " << age << endl;
    cout << "ID = " << id << endl;

    return;
}
