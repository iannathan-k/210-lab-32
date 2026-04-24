#include <iostream>
#include <deque>
#include <ctime>
#include "Car.h"

using namespace std;

// COMSC-210 | Lab 33 | Ian Kusmiantoro

void printQueue(const deque<Car>&);

int main() {
    srand(time(0));

    deque<Car> toll_booth;

    const int INITIAL_LINE = 2;
    const int MIN = 1;
    const int MAX = 100;
    const int PROB_LEAVE = 55;

    for (int i = 0; i < INITIAL_LINE; i++) {
        toll_booth.push_back(Car());
    }

    // Initial State
    cout << "Initial Queue:" << endl;
    printQueue(toll_booth);

    int time = 0;
    while (!toll_booth.empty()) {
        int prob = rand() % (MAX - MIN + 1) + MIN; // gen random num from 1 to 100
        time++;

        cout << "Time: " << time << endl;
        cout << "Operation: ";
        if (prob <= PROB_LEAVE) {
            // Pop front
            cout << "Paid - ";
            toll_booth.front().print(); // Print the front car before removing
            toll_booth.pop_front();
        } else {
            // Push back
            cout << "Joined - ";
            toll_booth.push_back(Car());
            toll_booth.back().print(); // Print the newly added car at the back
        }

        printQueue(toll_booth);
    }

    return 0;
}

// printQueue() prints a given deque in a neatly formatted manner
// parameters: const deque<Car>& queue - the deque to be printed
// returns: void
void printQueue(const deque<Car>& queue) {
    cout << "Queue:" << endl;
    if (queue.empty()) {
        cout << "\tQueue is empty" << endl;
        return;
    }

    for (Car c : queue) {
        cout << "\t";
        c.print();
    }
}