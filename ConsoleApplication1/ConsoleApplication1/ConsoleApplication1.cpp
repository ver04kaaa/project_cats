#include <iostream>
#include <thread>
#include <vector>
#include "cat.h"
#include "owner.h"

using namespace std;

int main() {
    vector<thread> cats;
    thread owner(refill_bowl);  // Поток для хозяина, который наполняет миску

    // Создаем потоки для каждой из 5 кошек
    for (int i = 1; i <= 5; ++i) {
        cats.push_back(thread(cat, i));
    }

    // Ожидаем завершения всех потоков
    for (auto& t : cats) {
        t.join();
    }
    owner.join();  // Ждем завершения потока хозяина

    return 0;
}
