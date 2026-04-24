#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

void printQueue(const deque<Car>&);

int main() {
    deque<Car> toll_booth;

    const int INITIAL_LINE = 2;

    for (int i = 0; i < INITIAL_LINE; i++) {
        toll_booth.push_back(Car());
    }

    // Initial State
    cout << "Initial Queue:" << endl;
    printQueue(toll_booth);

    // Test adding and removing
    cout << "Car Added: " << endl;
    toll_booth.push_back(Car());
    printQueue(toll_booth);

    cout << "Car Removed: " << endl;
    toll_booth.pop_front();
    printQueue(toll_booth);

    return 0;
}

void printQueue(const deque<Car>& queue) {
    if (queue.empty()) {
        cout << "\tQueue is empty" << endl;
    }
    
    for (Car c : queue) {
        cout << "\t";
        c.print();
    }
}