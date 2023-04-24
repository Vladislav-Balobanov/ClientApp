#pragma once
#include <iostream>
#include <Windows.h>
#include <errhandlingapi.h>

typedef float* (*MultiplyFuncPointer)(int* ,unsigned int, float);

MultiplyFuncPointer loadFunctionFromDLL()
{
	HINSTANCE LoadingDLL = LoadLibrary(L"..\\Lib\\MultiplierLibrary.dll");

	if (!LoadingDLL)
		return NULL;

	MultiplyFuncPointer multFuncPtr = (MultiplyFuncPointer)GetProcAddress(LoadingDLL, "multiply");

	return multFuncPtr;
}