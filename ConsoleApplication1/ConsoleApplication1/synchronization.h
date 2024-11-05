#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include <mutex>
#include <condition_variable>

extern std::mutex mtx;  // Мьютекс для синхронизации доступа к миске
extern std::condition_variable cv;  // Условная переменная для ожидания наполнения миски
extern bool food_available;  // Флаг, указывающий, есть ли корм в миске

#endif  // SYNCHRONIZATION_H
