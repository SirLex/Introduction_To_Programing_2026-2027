/*
Задача 1: Напишете функции myMin(int x, int y) и myMax(int x, int y), които връщат съответно по-малкото и
по-голямото от две цели числа.

myMin(3, 7)    ->  3
myMin(10, -2)  ->  -2
myMax(3, 7)    ->  7
myMax(10, -2)  ->  10
*/

#include <iostream>

int myMin(int x, int y)
{
	return (x < y) ? x : y;
}

int myMax(int x, int y)
{
	return (x > y) ? x : y;
}

int main()
{
	int x, y;
	std::cin >> x >> y;

	std::cout << "Min: " << myMin(x, y) << '\n';
	std::cout << "Max: " << myMax(x, y) << '\n';
}
