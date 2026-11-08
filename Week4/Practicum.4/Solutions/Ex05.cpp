/*
Задача 5: Напишете функция geometricProgression(int start, int ratio, unsigned int n), която извежда на екрана
първите n члена на геометрична прогресия с първи член start и частно ratio, разделени с интервал.

geometricProgression(3, 2, 5)   ->  3 6 12 24 48
geometricProgression(1, -3, 4)  ->  1 -3 9 -27
*/

#include <iostream>

void geometricProgression(int start, int ratio, unsigned int n)
{
	long long term = start;

	for (unsigned int i = 0; i < n; i++)
	{
		std::cout << term;
		if (i < n - 1)
		{
			std::cout << ' ';
		}

		term *= ratio;
	}
}

int main()
{
	int start, ratio;
	unsigned int n;
	std::cin >> start >> ratio >> n;

	geometricProgression(start, ratio, n);
}
