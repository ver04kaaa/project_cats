#include "synchronization.h"

std::mutex mtx;  // ������� ��� ������������� ������� � �����
std::condition_variable cv;  // �������� ���������� ��� �������� ���������� �����
bool food_available = true;  // ����, �����������, ���� �� ���� � �����
