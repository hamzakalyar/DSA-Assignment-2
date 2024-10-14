#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

using namespace std;

int main() {
    PriorityQueue pq;

    ifstream file("entries.txt");
    string name, role;

    while (file >> name >> role) {
        pq.insert(name, role);
    }

    std::cout << "Unsorted Queue:" << std::endl;
    pq.display();

    pq.sortQueue();

    cout << "\nSorted Queue:" << std::endl;
    pq.display();

    return 0;
}
