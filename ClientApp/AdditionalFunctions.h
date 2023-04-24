#pragma once
#include <iostream>

int* generateRandArray(size_t size)
{
	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = (rand() % 100);
	}

	return array;
}

template<typename T>
void print(T* array, std::string arrayName, unsigned int size)
{
	std::cout << arrayName << ": ";

	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << ' ';
	}

	std::cout << std::endl;
}