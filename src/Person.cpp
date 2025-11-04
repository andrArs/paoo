#include "Person.h"
#include <iostream>
using namespace std; 

Person::Person(const string& n, int a)
    : name(n), age(a), favoriteNumbers(nullptr), numbersCount(0) {
    cout << "constructor called for person: " << name << endl;
}

Person::Person(const Person& p)
    : name(p.name), age(p.age), numbersCount(p.numbersCount), favoriteNumbers(nullptr) {

    cout << "copy constructor called" << endl;
    if (numbersCount > 0) {
        favoriteNumbers = new int[numbersCount];
        for (int i = 0; i < numbersCount; ++i)
            favoriteNumbers[i] = p.favoriteNumbers[i];
    }
}

Person::Person(Person&& p) noexcept
    : name(std::move(p.name)), age(p.age), favoriteNumbers(p.favoriteNumbers), numbersCount(p.numbersCount) {

    cout << "move constructor called for person: " << name << endl;
    p.favoriteNumbers = nullptr;
    p.numbersCount = 0;
}

Person::~Person() {
    cout << "destructor called"<< endl;
    delete[] favoriteNumbers;

}

void Person::setName(const string& newName) {
    name = newName;
}

void Person::setAge(int newAge) { 
    age = newAge; 
}

void Person::setFavoriteNumbers(const int* numbers, int count) {
    delete[] favoriteNumbers;
    if (numbers && count > 0) {
        favoriteNumbers = new int[count];
        for (int i = 0; i < count; ++i)
            favoriteNumbers[i] = numbers[i];
        numbersCount = count;
    } else {
        favoriteNumbers = nullptr;
        numbersCount = 0;
    }
}

const string& Person::getName() const { return name; }
int Person::getAge() const { return age; }

void Person::print() const {
    cout << "Name: " << name << ", Age: " << age;
    if (favoriteNumbers && numbersCount > 0) {
        cout << ", Favorite Numbers: ";
        for (int i = 0; i < numbersCount; ++i)
            cout << favoriteNumbers[i] << " ";
    }
    cout << endl;
}
