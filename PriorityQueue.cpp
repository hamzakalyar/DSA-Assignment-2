#include "PriorityQueue.h"
#include <iostream>

PriorityQueue::PriorityQueue(int cap) : capacity(cap), size(0) {
    names = new std::string[capacity];
    roles = new std::string[capacity];
}

PriorityQueue::~PriorityQueue() {
    delete[] names;
    delete[] roles;
}

void PriorityQueue::resize() {
    capacity *= 2;
    std::string* newNames = new std::string[capacity];
    std::string* newRoles = new std::string[capacity];
    for (int i = 0; i < size; ++i) {
        newNames[i] = names[i];
        newRoles[i] = roles[i];
    }
    delete[] names;
    delete[] roles;
    names = newNames;
    roles = newRoles;
}

int PriorityQueue::getPriority(const std::string& role) const {
    if (role == "Parent") return 3;
    if (role == "Teacher") return 2;
    if (role == "Student") return 1;
    return 0;
}

void PriorityQueue::insert(const std::string& name, const std::string& role) {
    if (size == capacity) resize();
    names[size] = name;
    roles[size] = role;
    size++;
}

void PriorityQueue::sortQueue() {
    for (int i = 0; i < size - 1; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (getPriority(roles[j]) > getPriority(roles[maxIndex])) {
                maxIndex = j;
            }
        }
        std::swap(names[i], names[maxIndex]);
        std::swap(roles[i], roles[maxIndex]);
    }
}

void PriorityQueue::display() const {
    for (int i = 0; i < size; ++i) {
        std::cout << names[i] << " (" << roles[i] << ")" << std::endl;
    }
}
