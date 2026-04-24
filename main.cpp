#include <iostream>
#include <deque>
#include <ctime>
#include <array>
#include "Car.h"

using namespace std;

// COMSC-210 | Lab 33 | Ian Kusmiantoro
const int LANES = 4;

void printQueue(const array<deque<Car>, 4>&);

int main() {
    srand(time(0));
   
    const int INITIAL_LINE = 2;
    const int MIN = 1;
    const int MAX = 100;

    array<deque<Car>, 4> plaza;

    for (deque<Car>& queue : plaza) {
        for (int i = 0; i < INITIAL_LINE; i++) {
            queue.push_back(Car());
        }
    }

    // Initial State
    cout << "Initial Queue:" << endl;
    printQueue(plaza);

    return 0;
}

// printQueue() prints a given deque in a neatly formatted manner
// parameters: const deque<Car>& queue - the deque to be printed
// returns: void
void printQueue(const array<deque<Car>, 4>& plaza) {
    for (int i = 0; i < LANES; i++) {
        cout << "Lane " << i + 1 << ":" << endl;

        deque<Car> queue = plaza.at(i);
        if (queue.empty()) {
            cout << "\tQueue is empty" << endl;
            continue;
        }

        for (Car c : queue) {
            cout << "\t";
            c.print();
        }
    }
    cout << endl;
}