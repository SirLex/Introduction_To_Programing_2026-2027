/*
Задача 9: Напишете функция nextPrime(int n), която връща най-малкото просто число, по-голямо от n. Напишете и
помощна функция isPrime, която проверява дали число е просто.

nextPrime(10)  ->  11
nextPrime(13)  ->  17
nextPrime(1)   ->  2
*/

#include <iostream>

bool isPrime(int number)
{
	if (number < 2)
	{
		return false;
	}

	for (int divisor = 2; divisor * divisor <= number; divisor++)
	{
		if (number % divisor == 0)
		{
			return false;
		}
	}

	return true;
}

int nextPrime(int n)
{
	int candidate = (n < 2) ? 2 : n + 1;

	while (!isPrime(candidate))
	{
		candidate++;
	}

	return candidate;
}

int main()
{
	int n;
	std::cin >> n;

	std::cout << nextPrime(n);
}
