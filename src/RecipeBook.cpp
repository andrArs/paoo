#include "RecipeBook.hpp"

SecretRecipeBook::SecretRecipeBook(std::string name) : recipeName(name) {
    std::cout << " [RecipeBook] Created: Opening book at '" << recipeName << "'\n";
}

SecretRecipeBook::~SecretRecipeBook() {

    std::cout << " [RecipeBook] Destroyed: Closing book (No chefs are reading anymore).\n";
}

void SecretRecipeBook::read() {
    std::cout << " -> Reading ingredients for " << recipeName << "...\n";
}


HeadChef::HeadChef(std::shared_ptr<SecretRecipeBook> b) : book(b) {}

void HeadChef::cook() {
    std::cout << " [HeadChef] ";
    if(book) {
        book->read();
    } else {
        std::cout << "I have no recipe book!\n";
    }
}

SousChef::SousChef(std::shared_ptr<SecretRecipeBook> b) : book(b) {}

void SousChef::learn() {
    std::cout << " [SousChef] ";
    if(book) {
        book->read();
    } else {
        std::cout << "I have no recipe book!\n";
    }
}