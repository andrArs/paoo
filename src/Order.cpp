#include "Order.hpp"


Pizza::Pizza(int size) : diameterCm(size) {
    std::cout << " [Pizza] Baked: Fresh out of the oven (" << diameterCm << " cm).\n";
}

Pizza::~Pizza() {
    // Item 13: resursa este eliberata automat aici.
    std::cout << " [Pizza] Eaten: Gone from memory.\n";
}

void Pizza::smell() {
    std::cout << " -> Smells like pepperoni and cheese!\n";
}


OnlineOrder::OnlineOrder(std::unique_ptr<Pizza> p) : myPizza(std::move(p)) {
}

void OnlineOrder::deliver() {
    if(myPizza) {
        std::cout << " [Delivery] Delivering order...\n";
        myPizza->smell();
    } else {
        std::cout << " [Delivery] Box is empty! Ghost delivery?\n";
    }
}