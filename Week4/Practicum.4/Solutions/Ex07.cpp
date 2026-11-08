/*
Задача 7: Напишете функция digitalRoot(unsigned int n), която връща цифровия корен на неотрицателно цяло число -
едноцифреното число, до което се стига, като цифрите на числото се събират многократно.

Вход: 9517, Изход: 4

Пояснение: 9 + 5 + 1 + 7 = 22, а 2 + 2 = 4.
*/

#include <iostream>

unsigned int sumDigits(unsigned int n)
{
	unsigned int sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}

	return sum;
}

unsigned int digitalRoot(unsigned int n)
{
	while (n >= 10)
	{
		n = sumDigits(n);
	}

	return n;
}

int main()
{
	unsigned int n;
	std::cin >> n;

	std::cout << digitalRoot(n);
}
