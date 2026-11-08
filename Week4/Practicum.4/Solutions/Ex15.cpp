/*
Задача 15: Напишете функция removeDigitAt(unsigned int& num, unsigned int index), която премахва цифрата на позиция
index от числото num. Позициите се броят отляво надясно, започвайки от 1. Ако позицията е невалидна, числото не се
променя.

num = 12345, index = 3  ->  num = 1245
num = 12345, index = 7  ->  num = 12345
num = 120,   index = 1  ->  num = 20
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

void removeDigitAt(unsigned int& num, unsigned int index)
{
	unsigned int digitsCount = countDigits(num);

	if (index < 1 || index > digitsCount)
	{
		return;
	}

	unsigned int positionFromRight = digitsCount - index;
	unsigned int divisor = powerOfTen(positionFromRight);

	unsigned int leftPart = num / (divisor * 10);
	unsigned int rightPart = num % divisor;

	num = leftPart * divisor + rightPart;
}

int main()
{
	unsigned int num, index;
	std::cin >> num >> index;

	removeDigitAt(num, index);

	std::cout << num;
}
