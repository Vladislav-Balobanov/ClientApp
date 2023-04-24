/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															           //
// �������� ���� ����������� ���������� ���������������� ������ �������� ������������ ��������� � ������� LoadLibrary � GetProcAdress. //
//																															           //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include "loader.h"
#include "AdditionalFunctions.h"

int main()
{
	setlocale(LC_ALL, "rus");

	size_t countOfElements = 0;
	double factor = 0;

	std::cout << "������� ���������� ���������: ";
	std::cin >> countOfElements;

	try
	{
		// �������� ���������:
		MultiplyFuncPointer multiplyPtr = loadFunctionFromDLL();

		if (multiplyPtr == NULL)
		{
			throw std::exception("�� �������� ��������� �������������� ������� �� MultiplyerLib.dll");
		}

		// ��������� ��������� �������:
		int* generatedArray = generateRandArray(countOfElements);
		print<int>(generatedArray, "generatedVector", countOfElements);

		std::cout << "Insert factor: ";
		std::cin >> factor;

		// ���������� ������� ��������� �� ����� �� �������� ���������:
		float* resultArray = multiplyPtr(generatedArray, countOfElements, factor);
		print<float>(resultArray, "resultVector", countOfElements);

		// ���������� ��������� �� ����� ������:
		delete[] generatedArray;
		delete[] resultArray;
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return -1;
	}

	return 0;
}