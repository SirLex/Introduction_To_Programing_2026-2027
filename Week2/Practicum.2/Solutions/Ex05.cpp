/*
Задача 5: Въвеждат се три цели числа - ъгли в градуси. Да се провери дали съществува триъгълник с такива ъгли.
Ако не съществува, да се изведе Invalid triangle. Ако съществува, да се изведе видът му: Acute (остроъгълен),
Right (правоъгълен) или Obtuse (тъпоъгълен).

Вход: 60 60 60, Изход: Acute

Вход: 90 45 45, Изход: Right

Вход: 120 30 30, Изход: Obtuse

Вход: 100 50 40, Изход: Invalid triangle
*/

#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	bool isValid = (a > 0 && b > 0 && c > 0 && a + b + c == 180);

	if (!isValid)
	{
		std::cout << "Invalid triangle";
	}
	else if (a == 90 || b == 90 || c == 90)
	{
		std::cout << "Right";
	}
	else if (a > 90 || b > 90 || c > 90)
	{
		std::cout << "Obtuse";
	}
	else
	{
		std::cout << "Acute";
	}
}
