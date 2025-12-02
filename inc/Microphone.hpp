#pragma once
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

// ITEM 14: Think carefully about copying behavior in resource-managing classes.
// gestioneaza un Lock 
class MicrophoneLock {
private:
    std::mutex& mutexRef;

public:
    // Resource Acquisition Is Initialization (RAII)
    // Blocam mutexul in momentul crearii obiectului.
    explicit MicrophoneLock(std::mutex& m);

    // Deblocam mutexul automat la distrugere.
    ~MicrophoneLock();

    MicrophoneLock(const MicrophoneLock&) = delete; // No Copy Constructor
    MicrophoneLock& operator=(const MicrophoneLock&) = delete; // No Copy Assignment
};

void shoutCommandUnsafe(std::string message, int chefId);
void shoutCommandSafe(std::string message, int chefId);