#include "MultiplierLibrary.h"

float* multiply(int* array, unsigned int size, float factor )
{
	float* resultArray = new float[size];

    for(int i = 0; i < size; i++)
		resultArray[i] = array[i] * factor;

    return resultArray;
}