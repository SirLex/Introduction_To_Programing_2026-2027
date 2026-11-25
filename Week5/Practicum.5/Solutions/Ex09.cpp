/*
Задача 9: Два масива наричаме линейно зависими, ако имат еднаква дължина и единият може да се получи от другия,
като всички елементи се умножат по едно и също число (не непременно цяло). Напишете функция areLinearlyDependent,
която приема два масива от цели числа и размерите им и връща дали са линейно зависими. Напишете програма, която
въвежда двата масива - първо N и N числа, след това M и M числа - и извежда Yes, ако масивите са линейно зависими,
и No в противен случай.

Вход:
5
1 2 3 4 5
5
2 4 6 8 10

Изход:
Yes

Вход:
5
1 2 3 4 5
5
2 4 6 8 11

Изход:
No

Вход:
2
2 4
2
3 6

Изход:
Yes
*/

#include <iostream>

bool areLinearlyDependent(const int first[], int firstSize, const int second[], int secondSize)
{
	if (firstSize != secondSize)
	{
		return false;
	}

	// масивите са пропорционални точно когато за всеки две позиции i и j
	// first[i] / second[i] == first[j] / second[j]; кръстосаното умножение
	// избягва деленето, реалните числа и деленето на 0
	for (int i = 0; i < firstSize; i++)
	{
		for (int j = i + 1; j < firstSize; j++)
		{
			long long left = (long long)first[i] * second[j];
			long long right = (long long)first[j] * second[i];

			if (left != right)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	const int MAX_SIZE = 100;

	int first[MAX_SIZE];
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> first[i];
	}

	int second[MAX_SIZE];
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::cin >> second[i];
	}

	if (areLinearlyDependent(first, n, second, m))
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}
}
