/*
Задача 17 (бонус): Двама състезатели се движат по една и съща писта в една и съща посока, но с различни скорости.
По-бързият тръгва зад по-бавния, на известно разстояние от него. Програмата приема скоростите на двамата бегачи
и разстоянието между тях в началния момент. Да се изчисли след колко часа по-бързият ще настигне по-бавния.

Вход: 10 12 4, Изход: 2
*/

#include <iostream>

int main()
{
	double slowerSpeed, fasterSpeed, distance;
	std::cin >> slowerSpeed >> fasterSpeed >> distance;

	double time = distance / (fasterSpeed - slowerSpeed);

	std::cout << time;
}