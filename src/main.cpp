#include "Person.h"
#include <iostream>
using namespace std;

Person createTempPerson() {
    Person temp("ion", 25);
    int numbers[] = {5, 10, 15};
    temp.setFavoriteNumbers(numbers, 3);
    return temp; 
}

int main() {
    cout << "create person A" << endl;
    Person A("Andreea", 21);
    int numbersA[] = {3, 7, 49};
    A.setFavoriteNumbers(numbersA, 3);
    A.print();

    cout << "\ncreate person B (copy constructor)" << endl;
    Person B = A;
    B.print();

    cout << "\nmodify person B's age, and favorite numbers" << endl;
    B.setAge(30);
    int numbersB[] = {1, 8};
    B.setFavoriteNumbers(numbersB, 2);
    cout << "B: ";
    B.print();
    cout << "A: ";
    A.print();

    cout << "\ncreate person C (move constructor)" << endl;
    Person C = std::move(createTempPerson());
    C.print();

    cout << "\nfinal program" << endl;
    return 0;
}
