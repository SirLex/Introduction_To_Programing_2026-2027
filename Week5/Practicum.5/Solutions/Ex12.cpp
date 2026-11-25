/*
Задача 12: Напишете функция sortLex, която приема масив от неотрицателни цели числа и размера му и сортира масива
във възходящ ред според лексикографската наредба на записите на числата - числата се сравняват цифра по цифра
отляво надясно, както думи в речник. Например 123 е преди 9, защото първата цифра 1 е по-малка от 9, а 2018 е преди
7, защото 2 < 7. Не използвайте низове. Напишете програма, която въвежда масив, сортира го с функцията и го
извежда.

Вход:
6
13 14 7 2018 9 0

Изход:
0 13 14 2018 7 9
*/

#include <iostream>

int countDigits(int number)
{
	int count = 0;

	do
	{
		count++;
		number /= 10;
	} while (number > 0);

	return count;
}

int powerOfTen(int exp)
{
	int result = 1;

	for (int i = 0; i < exp; i++)
	{
		result *= 10;
	}

	return result;
}

// цифрата на позиция position, броено отляво, започвайки от 0
int getDigitFromLeft(int number, int digitsCount, int position)
{
	return (number / powerOfTen(digitsCount - 1 - position)) % 10;
}

// дали first е преди second в лексикографската наредба
bool isLexLess(int first, int second)
{
	int firstLength = countDigits(first);
	int secondLength = countDigits(second);
	int minLength = (firstLength < secondLength) ? firstLength : secondLength;

	for (int position = 0; position < minLength; position++)
	{
		int firstDigit = getDigitFromLeft(first, firstLength, position);
		int secondDigit = getDigitFromLeft(second, secondLength, position);

		if (firstDigit != secondDigit)
		{
			return (firstDigit < secondDigit);
		}
	}

	// ако едното число е начало на другото (например 12 и 123), по-краткото е първо
	return (firstLength < secondLength);
}

// масивът не е const, защото функцията го променя - промените се виждат и в main,
// тъй като функцията получава самия масив, а не копие
void sortLex(int arr[], int size)
{
	// Selection sort, в който вместо < сравняваме с isLexLess
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (isLexLess(arr[j], arr[minIndex]))
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}

int main()
{
	const int MAX_SIZE = 100;

	int arr[MAX_SIZE];
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	sortLex(arr, n);

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i];
		if (i < n - 1)
		{
			std::cout << ' ';
		}
	}
}
