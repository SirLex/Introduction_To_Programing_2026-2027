/*
Задача 8: Въвеждат се неотрицателни цели числа a, b и s, като a ≤ b. Да се изведе първото число в интервала [a, b],
чиято
сума на цифрите е равна на s. Ако няма такова число, да се изведе No such number.

Вход: 10 50 7, Изход: 16

Вход: 10 20 15, Изход: No such number
*/

#include <iostream>

int main()
{
	int a, b, s;
	std::cin >> a >> b >> s;

	bool isFound = false;
	int result = 0;

	for (int number = a; number <= b; number++)
	{
		int digitsSum = 0;
		for (int temp = number; temp > 0; temp /= 10)
		{
			digitsSum += temp % 10;
		}

		// break е извън вътрешния цикъл, затова спира външния
		if (digitsSum == s)
		{
			isFound = true;
			result = number;
			break;
		}
	}

	if (isFound)
	{
		std::cout << result;
	}
	else
	{
		std::cout << "No such number";
	}
}
