/*
Задача 3: Напишете функция mySwap(int& a, int& b), която разменя стойностите на две целочислени променливи.

a = 2005, b = 2007  ->  a = 2007, b = 2005
*/

#include <iostream>

// параметрите са по референция, затова функцията променя самите променливи от main,
// а не техни копия
void mySwap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	mySwap(a, b);

	std::cout << "a = " << a << ", b = " << b;
}
