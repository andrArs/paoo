#pragma once
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <chrono>

// ITEM 14: Think carefully about copying behavior in resource-managing classes.
class MicrophoneLock {
private:
    std::mutex& mutexRef;

public:
   
    explicit MicrophoneLock(std::mutex& m);

    ~MicrophoneLock();

    MicrophoneLock(const MicrophoneLock&) = delete; // No Copy Constructor
    MicrophoneLock& operator=(const MicrophoneLock&) = delete; // No Copy Assignment
};

void shoutCommandUnsafe(std::string message, int chefId);
void shoutCommandSafe(std::string message, int chefId);