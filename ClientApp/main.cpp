/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																															           //
// Основной файл клиентского приложения демонстрирующего способ загрузки динамической библотеки с помощью LoadLibrary и GetProcAdress. //
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

	std::cout << "Введите количество элементов: ";
	std::cin >> countOfElements;

	try
	{
		// Загрузка библотеки:
		MultiplyFuncPointer multiplyPtr = loadFunctionFromDLL();

		if (multiplyPtr == NULL)
		{
			throw std::exception("Не возможно загрузить экспортируемую функцию из MultiplyerLib.dll");
		}

		// Генерация исходного массива:
		int* generatedArray = generateRandArray(countOfElements);
		print<int>(generatedArray, "generatedVector", countOfElements);

		std::cout << "Insert factor: ";
		std::cin >> factor;

		// Применение функции умножения на число из вненшней библотеки:
		float* resultArray = multiplyPtr(generatedArray, countOfElements, factor);
		print<float>(resultArray, "resultVector", countOfElements);

		// Незабываем отчистить за собой память:
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