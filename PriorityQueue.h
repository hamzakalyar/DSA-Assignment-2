#include <string>

using namespace std;

class PriorityQueue {
private:
    string* names;
    string* roles;
    int size;
    int capacity;

    void resize();
    int getPriority(const std::string& role) const;

public:
    PriorityQueue(int cap = 10);
    ~PriorityQueue();
    void insert(const std::string& name, const std::string& role);
    void sortQueue();
    void display() const;
};


