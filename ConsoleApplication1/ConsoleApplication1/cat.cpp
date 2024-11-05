#include "cat.h"
#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include "synchronization.h"

using namespace std;

void cat(int id) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 5);  // Для случайного времени отхода

    while (true) {
        unique_lock<mutex> lock(mtx);

        while (!food_available) {
            cout << "Cat " << id << " is waiting for the bowl to be refilled.\n";
            cv.wait(lock);
        }

        food_available = false;
        cout << "Cat " << id << " is eating.\n";
        lock.unlock();  // Отпускаем мьютекс на время еды
        this_thread::sleep_for(chrono::seconds(1));

        lock.lock();
        cout << "Cat " << id << " is done eating and resting for " << dist(gen) << " seconds.\n";
        this_thread::sleep_for(chrono::seconds(dist(gen)));

        food_available = true;
        cv.notify_all();
    }
}
