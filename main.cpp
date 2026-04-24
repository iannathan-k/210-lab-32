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
    const int PROB_PAID_MIN = 0, PROB_PAID_MAX = 46;
    const int PROB_JOIN_MIN = 47, PROB_JOIN_MAX = PROB_JOIN_MIN + 39;
    const int PROB_SWITCH = 15;

    array<deque<Car>, 4> plaza;

    for (deque<Car>& queue : plaza) {
        for (int i = 0; i < INITIAL_LINE; i++) {
            queue.push_back(Car());
        }
    }

    // Initial State
    cout << "Initial Queue:" << endl;
    printPlaza(plaza);

    // But I assume that's because you want us to implement the switching in milestone 5,
    // So the "when empty" clause is still on the table
    for (int i = 1; i <= RUN_TIME; i++) {
        cout << "===== TIME " << i << " =====" << endl;

        for (int j = 0; j < LANES; j++) {
            cout << "Lane " << j + 1 << ": ";

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
                    cout << "Nothing Happened" << endl;
                }
                continue;
            }

            if (prob <= PROB_PAID) {
                // Car Leaves
                cout << "Paid - ";
                q.front().print(); // Prints front car before popping
                q.pop_front();
                continue;
            } else if (prob <=) {

            }

            // Ok I was wrong, i am thiking about how to make the probabilities work
            prob = rand() % (MAX - MIN + 1) + MIN;
            if (prob <= PROB_JOIN) {
                // Car Joins
                cout << "Joined - ";
                q.push_back(Car());
                q.back().print(); // Prints the newly added car
                continue;
            }

            prob = rand() % (MAX - MIN + 1) + MIN;
            if (prob <= PROB_SWITCH) {
                // Car Switches
                cout << "Switched - ";

                // Select random lane
                int new_lane = rand() % LANES;
                while (new_lane == j) {
                    new_lane = rand() % LANES;
                }

                Car c = q.back();
                c.print();
                q.pop_back();

                plaza.at(new_lane).push_back(c);
                continue;
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