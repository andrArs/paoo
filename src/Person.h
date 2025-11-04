#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    int* favoriteNumbers; 
    int numbersCount;     

public:
    Person(const string& name, int age);
    Person(const Person& p);
    Person(Person&& p) noexcept;
    ~Person();

    void setName(const string& newName);
    void setAge(int newAge);
    void setFavoriteNumbers(const int* numbers, int count);

    const string& getName() const;
    int getAge() const;

    void print() const;
};
