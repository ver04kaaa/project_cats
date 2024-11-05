#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include <mutex>
#include <condition_variable>

extern std::mutex mtx;  // ������� ��� ������������� ������� � �����
extern std::condition_variable cv;  // �������� ���������� ��� �������� ���������� �����
extern bool food_available;  // ����, �����������, ���� �� ���� � �����

#endif  // SYNCHRONIZATION_H
