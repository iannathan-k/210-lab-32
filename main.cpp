#include <iostream>
#include <deque>
#include <ctime>
#include <array>
#include "Car.h"

using namespace std;

// COMSC-210 | Lab 33 | Ian Kusmiantoro

const int LANES = 4;

void printPlaza(const array<deque<Car>, 4>&);

int main() {
    srand(time(0));
   
    const int INITIAL_LINE = 2;
    const int RUN_TIME = 20;
    const int MIN = 1;
    const int MAX = 100;
    const int PROB_JOIN_EMPTY = 50;

    array<deque<Car>, 4> plaza;

    for (deque<Car>& queue : plaza) {
        for (int i = 0; i < INITIAL_LINE; i++) {
            queue.push_back(Car());
        }
    }

    // Initial State
    cout << "Initial Queue:" << endl;
    printPlaza(plaza);

    // Milestone 3 explicitly states to only code the 50/50
    // But I assume that's because you want us to implement the switching in milestone 5,
    // So the "when empty" clause is still on the table
    for (int i = 1; i <= RUN_TIME; i++) {
        cout << "===== TIME " << i << " =====" << endl;

        for (int j = 0; j < LANES; j++) {
            cout << "Lane " << j + 1 << ": ";

            deque<Car>& q = plaza.at(j);
            int prob = rand() % (MAX - MIN + 1) + MIN;

            // It seems like milestone 3 doesn't call for this yet, so I'll save it for milestone 5
            // // Guard clause to handle when empty, and will skip the rest of the code if entered
            // // This is to avoid repeatedly nesting which i personally dislike because i think it looks ugly
            // if (q.empty()) {
            //     // 50-50 that a car joins if the line is empty
            //     if (prob <= PROB_JOIN_EMPTY) {
            //         // Car Joins
            //         cout << "Joined - ";
            //         q.push_back(Car());
            //         q.back().print(); // Prints the newly added car
            //     } else {
            //         cout << "Nothing Happened" << endl;
            //     }
            //     continue;
            // }

            // Here's the 5050
            if (prob <= PROB_JOIN_EMPTY) {
                // Car Leaves
                cout << "Paid - ";
                q.front().print(); // Prints front car before popping
                q.pop_front();
            } else {
                // Car Joins
                cout << "Joined - ";
                q.push_back(Car());
                q.back().print(); // Prints the newly added car
            }
        }

        printPlaza(plaza);
    }

    return 0;
}

// printPlaza() prints a given deque in a neatly formatted manner
// parameters: const deque<Car>& queue - the deque to be printed
// returns: void
void printPlaza(const array<deque<Car>, 4>& plaza) {
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