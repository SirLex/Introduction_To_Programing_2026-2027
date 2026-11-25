/*
	Задача 2: insertAt
	Да се напише функция, която вмъква value на позиция index (0 <= index <= size), като измества останалите
	елементи надясно. Функцията връща false и не прави нищо, ако масивът е пълен или индексът е невалиден.

	Вход:
	4
	33 1 23 8
	2 100

	Изход:
	33 1 100 23 8
*/

#include <iostream>

bool insertAt(int arr[], int& size, int capacity, int index, int value)
{
	if (size == capacity || index < 0 || index > size)
	{
		return false;
	}

	// изместваме отдясно наляво, за да не презапишем елементи
	for (int i = size; i > index; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[index] = value;
	size++;

	return true;
}

int main()
{
	const int MAX_SIZE = 100;

	int size;
	std::cin >> size;

	if (size < 1 || size > MAX_SIZE)
	{
		return 1;
	}

	int arr[MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}

	int index, value;
	std::cin >> index >> value;

	if (!insertAt(arr, size, MAX_SIZE, index, value))
	{
		std::cout << "Cannot insert";
		return 1;
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
}
