/*
Задача 2: Напишете функция myAbs(int x), която връща абсолютната стойност на цяло число.

myAbs(-5)  ->  5
myAbs(7)   ->  7
*/

#include <iostream>

int myAbs(int x)
{
	return (x < 0) ? -x : x;
}

int main()
{
	int x;
	std::cin >> x;

	std::cout << myAbs(x);
}
