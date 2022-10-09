#include<string>

using namespace std;

class Person
{
    string name;
    int id;
    int age;

public:
    Person();

    Person(string _name, int _id, int _age);

    void setName(string _name);

    void setId(int _id);

    void setAge(int _age);

    string getName();

    int getId();

    int getAge();

    void print();
};
