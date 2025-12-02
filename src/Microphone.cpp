#include "Microphone.hpp"

std::mutex kitchenMicMutex;

MicrophoneLock::MicrophoneLock(std::mutex& m) : mutexRef(m) {
    mutexRef.lock(); 
}

MicrophoneLock::~MicrophoneLock() {
    mutexRef.unlock();
}

// functie fara RAII Lock
void shoutCommandUnsafe(std::string message, int chefId) {
    std::string fullText = "[Chef " + std::to_string(chefId) + "] (UNSAFE): " + message + "\n";
    
    for(char c : fullText) {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

// functie cu RAII Lock - Item 14
void shoutCommandSafe(std::string message, int chefId) {
    MicrophoneLock lock(kitchenMicMutex);

    std::string fullText = "[Chef " + std::to_string(chefId) + "] (SAFE): " + message + "\n";

    for(char c : fullText) {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    
}