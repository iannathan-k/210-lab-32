#include <iostream>
#include <deque>
#include <ctime>
#include <array>
#include "Car.h"

using namespace std;

// COMSC-210 | Lab 33 | Ian Kusmiantoro

const int LANES = 4;

void printPlaza(const array<deque<Car>, LANES>&);

int main() {
    srand(time(0));
   
    const int INITIAL_LINE = 2;
    const int RUN_TIME = 20;
    const int MIN = 1;
    const int MAX = 100;

    const int PROB_JOIN_EMPTY = 50;
    const int PROB_PAID = 46;
    const int PROB_JOIN = PROB_PAID + 39;

    array<deque<Car>, LANES> plaza;

    for (deque<Car>& queue : plaza) {
        for (int i = 0; i < INITIAL_LINE; i++) {
            queue.push_back(Car());
        }
    }

    // Initial State
    cout << "Initial Queue:" << endl;
    printPlaza(plaza);

    // Iterate over each time interval
    for (int i = 1; i <= RUN_TIME; i++) {
        cout << "===== TIME " << i << " =====" << endl;

        // For each lane within the time interval...
        for (int j = 0; j < LANES; j++) {
            cout << "Lane " << j + 1 << ": ";

            // Using reference because the deque needs to edited!
            deque<Car>& q = plaza.at(j);
            int prob = rand() % (MAX - MIN + 1) + MIN;

            // Guard clause to handle when empty, and will skip the rest of the code if entered
            // This is to avoid repeatedly nesting which i personally dislike because i think it looks ugly
            if (q.empty()) {
                // 50-50 that a car joins if the line is empty
                if (prob <= PROB_JOIN_EMPTY) {
                    // Car Joins
                    cout << "Joined - ";
                    q.push_back(Car());
                    q.back().print(); // Prints the newly added car
                } else {
                    // Car doesn't Join
                    cout << "Nothing Happened" << endl;
                }
                continue;
            }

            if (prob <= PROB_PAID) {
                // Car Leaves
                cout << "Paid - ";
                q.front().print(); // Prints front car before popping
                q.pop_front();
            } else if (prob <= PROB_JOIN) {
                // Car Joins
                cout << "Joined - ";
                q.push_back(Car());
                q.back().print(); // Prints the newly added car
            } else {
                // Car Switches
                cout << "Switched - ";

                // Select random lane that isnt itself
                int new_lane = rand() % LANES;
                while (new_lane == j) {
                    new_lane = rand() % LANES;
                }

                // remove car from this lane
                Car c = q.back();
                c.print();
                q.pop_back();

                // put car in new lane
                plaza.at(new_lane).push_back(c);
            }
        }

        printPlaza(plaza);
    }

    return 0;
}

// printPlaza() prints a given array of deques in a neatly formatted manner
// parameters: const array<deque<Car>, 4>& plaza - the array of deques to be printed
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