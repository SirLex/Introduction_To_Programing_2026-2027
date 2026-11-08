/*
Задача 13: Напишете функция permutationNumbers(unsigned int a, unsigned int b), която връща дали цифрите на едното
число са пермутация на цифрите на другото, тоест дали всяка цифра се среща еднакъв брой пъти в двете числа.

permutationNumbers(12321, 21132)  ->  true
permutationNumbers(112, 122)      ->  false
*/

#include <iostream>

int countOccurrences(unsigned int number, unsigned int digit)
{
	int count = 0;

	do
	{
		if (number % 10 == digit)
		{
			count++;
		}
		number /= 10;
	} while (number > 0);

	return count;
}

bool permutationNumbers(unsigned int a, unsigned int b)
{
	for (unsigned int digit = 0; digit <= 9; digit++)
	{
		if (countOccurrences(a, digit) != countOccurrences(b, digit))
		{
			return false;
		}
	}

	return true;
}

int main()
{
	unsigned int a, b;
	std::cin >> a >> b;

	std::cout << std::boolalpha << permutationNumbers(a, b);
}
