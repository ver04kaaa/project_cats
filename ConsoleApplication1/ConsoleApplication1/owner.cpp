#include "owner.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "synchronization.h"

using namespace std;

void refill_bowl() {
    while (true) {
        this_thread::sleep_for(chrono::seconds(5));
        cout << "Owner is refilling the bowl.\n";
        food_available = true;
        cv.notify_all();
    }
}
