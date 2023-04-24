///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															 //
// �������� ���� ����������� ���������� ���������������� ������ �������� � ������� ���������� ������� � ������������� �����. //
//																															 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "MultiplierLibrary.h"
#include "AdditionalFunctions.h"

int main()
{
	setlocale(LC_ALL, "rus");

	size_t countOfElements = 0;
	double factor = 0;

	std::cout << "������� ���������� ���������: ";
	std::cin >> countOfElements;

	// ��������� ��������� �������: 
	int* generatedArray = generateRandArray(countOfElements);
	print<int>(generatedArray, "generatedVector", countOfElements);

	std::cout << "Insert factor: ";
	std::cin >> factor;

	// ���������� ������� ������� ��������� ������� �� �����:
	float* resultArray = multiply(generatedArray, countOfElements, factor);
	print<float>(resultArray, "resultVector", countOfElements);

	delete[] generatedArray;
	delete[] resultArray;

	return 0;
}