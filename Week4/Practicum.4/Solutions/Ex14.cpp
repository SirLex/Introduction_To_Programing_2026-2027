/*
Задача 14: Напишете функция moveLastDigits(unsigned int a, unsigned int b, unsigned int k), която връща числото,
получено, като последните k цифри на a се поставят пред цифрите на b. Приемете, че k не надвишава броя на цифрите
на a.

moveLastDigits(12345, 67, 2)  ->  4567
moveLastDigits(9876, 5, 3)    ->  8765
*/

#include <iostream>

unsigned int countDigits(unsigned int number)
{
	unsigned int count = 0;

	do
	{
		count++;
		number /= 10;
	} while (number > 0);

	return count;
}

unsigned int powerOfTen(unsigned int exp)
{
	unsigned int result = 1;

	for (unsigned int i = 0; i < exp; i++)
	{
		result *= 10;
	}

	return result;
}

unsigned int moveLastDigits(unsigned int a, unsigned int b, unsigned int k)
{
	unsigned int lastDigits = a % powerOfTen(k);

	return lastDigits * powerOfTen(countDigits(b)) + b;
}

int main()
{
	unsigned int a, b, k;
	std::cin >> a >> b >> k;

	std::cout << moveLastDigits(a, b, k);
}
