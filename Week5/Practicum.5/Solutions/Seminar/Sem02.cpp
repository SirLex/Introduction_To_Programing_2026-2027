/*
Семинар, задача 2: Да се въведат N числа и да се отпечатат сумата и средното им аритметично.

Вход:
10
1 2 3 4 5 6 7 8 9 10

Изход:
Sum: 55
Average: 5.5
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

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	// (double), за да не се получи целочислено деление
	double average = (double)sum / n;

	std::cout << "Sum: " << sum << '\n';
	std::cout << "Average: " << average << '\n';
}
