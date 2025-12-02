#pragma once
#include <iostream>
#include <memory>
#include <string>

// ITEM 13: Use objects to manage resources
// resursa partajata: cartea de retete
class SecretRecipeBook {
public:
    std::string recipeName;
    SecretRecipeBook(std::string name);
    ~SecretRecipeBook();
    void read();
};

// consumator 1 
class HeadChef {
public:
    std::shared_ptr<SecretRecipeBook> book;
    
    HeadChef(std::shared_ptr<SecretRecipeBook> b);
    void cook();
};

// consumator 2 
class SousChef {
public:
    std::shared_ptr<SecretRecipeBook> book;
    
    SousChef(std::shared_ptr<SecretRecipeBook> b);
    void learn();
};