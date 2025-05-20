#include "interface.h"

int main()
{
	int size = 10;
	Function* arr[size];
	for (int i = 0; i < size; i++) 
	{
        arr[i] = NULL;
    }
	
	Menu(arr, size);
}