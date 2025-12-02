#pragma once
#include <iostream>
#include <memory>  

// resursa unica: pizza fizica
class Pizza {
public:
    int diameterCm;
    Pizza(int size);
    ~Pizza();
    void smell();
};

class OnlineOrder {
private:
    // ITEM 13: Unique Pointer
    std::unique_ptr<Pizza> myPizza;

public:
    OnlineOrder(std::unique_ptr<Pizza> p);
    
    void deliver();
};