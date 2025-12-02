#include <iostream>
#include <vector>
#include <thread>
#include "Order.hpp"
#include "RecipeBook.hpp"
#include "Microphone.hpp"

int main() {

   //unique pointer
    std::cout << "--- PART A: UNIQUE OWNERSHIP (The Pizza) ---\n";
    std::unique_ptr<Pizza> freshPizza = std::make_unique<Pizza>(40);
    std::cout << " (Main function currently owns the pizza)\n";

    //mutam resursa - copierea este interzisa la unique_ptr
    OnlineOrder uberEatsOrder(std::move(freshPizza));
    
    uberEatsOrder.deliver();
    // vechiul proprietar nu mai are acces 
    if(freshPizza == nullptr) {
        std::cout << " [CHECK] Main no longer owns the pizza. Ownership transferred completely.\n";
    }

   //shared pointer
    std::cout << "\n--- PART B: SHARED OWNERSHIP (The Recipe Book) ---\n";
    std::shared_ptr<SecretRecipeBook> pastaRecipe = std::make_shared<SecretRecipeBook>("Pasta Carbonara");
    std::cout << " [REF COUNT] Book created. Readers: " << pastaRecipe.use_count() << "\n";

    {
        std::cout << " -> Shift starts. Chefs are arriving...\n";
        
        HeadChef gordon(pastaRecipe); 
        std::cout << " [REF COUNT] Head Chef arrived. Readers: " << pastaRecipe.use_count() << "\n";
        
        SousChef nino(pastaRecipe);   
        std::cout << " [REF COUNT] Sous Chef arrived. Readers: " << pastaRecipe.use_count() << "\n";

        gordon.cook();
        nino.learn();
    } 
    
    std::cout << " -> Shift ends.\n";
    std::cout << " [REF COUNT] Back to main only. Readers: " << pastaRecipe.use_count() << "\n";
    
    // threading, mutex, sync vs async
    std::cout << "\n\n--- PART C: THREADING & LOCKS (Shared Resource: The Console) ---\n";
    
    std::cout << "[test 1] UNSAFE (fara mutex - Race Condition):\n";    
    std::vector<std::thread> badThreads;
    for(int i=0; i<3; ++i) {
        badThreads.push_back(std::thread(shoutCommandUnsafe, "WHERE IS THE LAMB SAUCE?!", i));
    }
    for(auto& t : badThreads) t.join();

    std::cout <<"\n\n[test 2] SAFE (cu mutex RAII):\n";    
    std::vector<std::thread> goodThreads;
    for(int i=0; i<3; ++i) {
        goodThreads.push_back(std::thread(shoutCommandSafe, "Order ready, service please!", i));
    }
    
    for(auto& t : goodThreads) {
        if(t.joinable()) t.join();
    }

    std::cout << "\n=== END OF PROGRAM ===\n";
    return 0;
}