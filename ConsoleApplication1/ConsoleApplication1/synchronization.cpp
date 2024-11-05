#include "synchronization.h"

std::mutex mtx;  // Мьютекс для синхронизации доступа к миске
std::condition_variable cv;  // Условная переменная для ожидания наполнения миски
bool food_available = true;  // Флаг, указывающий, есть ли корм в миске
