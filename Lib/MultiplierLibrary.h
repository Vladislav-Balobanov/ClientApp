#include <cstdint>

#ifdef MULTIPLIER_LIB
	#define LIB_EXPORT extern "C" __declspec(dllexport)
	#define LIB_EXPORT extern "C" __declspec(dllimport)
#else
	#define LIB_EXPORT extern "C"
#endif

LIB_EXPORT float* multiply(int* array, unsigned int size, float factor );