/*
Семинар, задача 23: Да се сортира масивът във възходящ ред веднъж с Bubble sort и веднъж със Selection sort (върху
две копия на входния масив). За всеки алгоритъм да се отпечатат сортираният масив и броят направени размени
(swaps).

Вход:
5
5 1 4 2 8

Изход:
Bubble sort: 1 2 4 5 8 (swaps: 4)
Selection sort: 1 2 4 5 8 (swaps: 2)
*/

#include <iostream>

int main()
{
	const int MAX_SIZE = 100;

	int arr[MAX_SIZE];
	int n;
	std::cin >> n;

	if (n < 1 || n > MAX_SIZE)
	{
		std::cout << "Invalid size!\n";
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	int bubble[MAX_SIZE];
	int selection[MAX_SIZE];
	for (int i = 0; i < n; i++)
	{
		bubble[i] = arr[i];
		selection[i] = arr[i];
	}

	// Bubble sort: съседните елементи в грешен ред се разменят;
	// след всяко минаване най-големият от останалите "изплува" в края
	int bubbleSwaps = 0;
	for (int i = 0; i < n - 1; i++)
	{
		bool hasSwapped = false;

		for (int j = 0; j < n - 1 - i; j++)
		{
			if (bubble[j] > bubble[j + 1])
			{
				int temp = bubble[j];
				bubble[j] = bubble[j + 1];
				bubble[j + 1] = temp;

				bubbleSwaps++;
				hasSwapped = true;
			}
		}

		// нямаше размени - масивът вече е сортиран
		if (!hasSwapped)
		{
			break;
		}
	}

	// Selection sort: на всяка стъпка намираме минимума на несортираната част
	// и го слагаме на първото ѝ място
	int selectionSwaps = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < n; j++)
		{
			if (selection[j] < selection[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			int temp = selection[i];
			selection[i] = selection[minIndex];
			selection[minIndex] = temp;

			selectionSwaps++;
		}
	}

	std::cout << "Bubble sort:";
	for (int i = 0; i < n; i++)
	{
		std::cout << ' ' << bubble[i];
	}
	std::cout << " (swaps: " << bubbleSwaps << ")\n";

	std::cout << "Selection sort:";
	for (int i = 0; i < n; i++)
	{
		std::cout << ' ' << selection[i];
	}
	std::cout << " (swaps: " << selectionSwaps << ")\n";
}
