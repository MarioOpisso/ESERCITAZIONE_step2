/*! @file interface.cpp
	@brief This is a program to manage an array of Function (polynomial, power and logarithmic).
	@author Opisso Mario
*/

#include "interface.h"

/// @brief menu interface
/// @param address of first array cell
/// @param array size
void Menu(Function* array[], int size)
{
	cout << endl;
	cout << "This is a program to manage an array of Function (polynomial, power and logarithmic)." << endl;
	
	bool state = 1;

	while(state)
	{
		cout << endl << "0- Exit from menu." << endl;
		cout << "1- Visualize function list." << endl;
		cout << "2- Insert function." << endl;
		cout << "3- Delete a function." << endl;
		cout << "4- Delete all functions." << endl;
		cout << "5- Select a function." << endl;
		
		switch(Control(0, 5))
		{
			case 0:
				state = 0;
				cout << endl << "Exiting the menu..." << endl;
				DeleteALL(array, size);
				break;
			case 1:
				Visualize(array, size);
				break;
			case 2:				
				Insert(array, size);
				break;
			case 3:
				Delete(array, size);
				break;
			case 4:
				DeleteALL(array, size);
				break;
			case 5:
				Selection(array, size);
				break;
			default:
				break;
		}
	}
}

/// @brief function list printer
/// @param address of first array cell
/// @param array size
void Visualize(Function* array[], int size)
{
	if(isEmpty(array, size))
	{
		return;
	}
	
	for(int i = 0; i < size; i++)
	{
		if(array[i] != NULL)
		{
			cout << endl <<" FUNCTION ID = " << i << " ----- ";
			array[i]->Dump();
		}
	}
	return;
}

/// @brief function adder
/// @param address of first array cell
/// @param array size
void Insert(Function* array[], int size)
{
	double coeffA;
	double coeffB;
	int a = LookForNull(array, size);
	if(a == -1)
	{
		return;
	}

	cout << endl << "Select the type of function: " << endl;
	cout << "0- Polynomial" << endl;
	cout << "1- Power" << endl;
	cout << "2- Logarithmic" << endl;
	
	switch(Control(0, 2))
	{
		case 0:
			double* cf;
			cout << endl << "How many coefficients?" << endl;
			cin >> coeffA;
		
			cf = new double[(int)coeffA];
			if(cf == NULL)
			{
				ErrorMessage("No space available to insert coefficients");
				return;
			}
			
			for(int x = 0; x < (int)coeffA; x++)
			{
				cout << endl << "Insert the coefficient in position number " << x << ":" << endl;
				cin >> cf[x];
			}
			
			array[a] = new Polynomial(cf, (int)coeffA);
			if(!Check(array[a]))
			{
				delete array[a];
				array[a] = NULL;
				Insert(array, size);
			}
			
			delete cf;
			break;
			
		case 1:
			cout << endl << "Insert the exponent: ";
			cin >> coeffB;
			cout << endl << "Insert the constant k: ";
			cin >> coeffA;
					
			array[a] = new Power(coeffA, coeffB);
			
			if(!Check(array[a]))
			{
				delete array[a];
				array[a] = NULL;
				Insert(array, size);
			}
			break;
			
		case 2:
			cout << endl << "Insert the base: ";
			cin >> coeffB;
			cout << endl << "Insert the coefficient k: ";
			cin >> coeffA;
					
			array[a] = new Logarithmic(coeffB, coeffA);
			
			if(!Check(array[a]))
			{
				delete array[a];
				array[a] = NULL;
				Insert(array, size);
			}
			break;

		default:
			break;
	}
}

/// @brief function deleter
/// @param address of first array cell
/// @param array size
void Delete(Function * array[], int size)
{
	if(isEmpty(array, size))
	{
		return;
	}
	
	int ID = GetID(array, size);
	
	if(Check(array[ID]))
	{
		delete array[ID];
		array[ID] = NULL;
		return;
	}
	Delete(array, size);
}

/// @brief list destructor
/// @param address of first array cell
/// @param array size
void DeleteALL(Function* array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		delete array[i];
		array[i] = NULL;
	}
}
 
/// @brief function selector
/// @param address of first array cell
/// @param array size
void Selection(Function * array[], int size)
{
	double x;
	
	if(isEmpty(array, size))
	{
		return;
	}
	
	int ID = GetID(array, size);
	
	array[ID]->Dump();
	cout << endl << "Insert the value of x: " << endl;
	cin >> x;
	cout << endl << "F(" << x << ") = " << array[ID]->GetValue(x);
}
 
/// @brief ID input
/// @param address of first array cell
/// @param array size
/// @return address of the selected cell
int GetID(Function * array[], int size)
{
	int ID;
	cout << endl << "Insert 1 to visualize the functions list or 0 to continue: " << endl;
	if(Control(0,1))
	{
		Visualize(array, size);
	}
	cout << endl << "Insert the ID of the function: " << endl;
	cin >> ID;
	
	while((ID < 0) || (ID > size-1) || (array[ID] == NULL))
	{
		cout << endl << "Invalid option, retry: " << endl;
		cin >> ID;
	}
	return ID;
}
 
/// @brief input check
/// @param inferior limit
/// @param superior limit
/// @return option selected
int Control(int a, int b)
{
	int val;
	cin >> val;
	while(val < a || val > b)
	{
		cout << endl << "Invalid option, retry: " << endl;
		cin >> val;
	}
	return val;
}

/// @brief function available control
/// @param address of first array cell
/// @param array 
/// @return 1 if the list is empty
bool isEmpty(Function * array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(array[i] != NULL)
		{
			return 0;
		}
	}
	ErrorMessage("No function available!");
	return 1;
}
 
/// @brief searching for null cell
/// @param address of first array cell
/// @param array size
/// @return address of the first null cell
int LookForNull(Function * array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		if(array[i] == NULL)
		{
			return i;
		}
	}
	ErrorMessage("The array is full!");
	return -1;
}

/// @brief error message printer
/// @param text
void ErrorMessage(const char *string)
{
	cout << endl << "***ERROR*** -- " << string << endl;
}

/// @brief function confirmer
/// @param address array cell
/// @return 1 if the function is confirmed
bool Check(Function* temp)
{
	cout << endl << "Check of the new function: "<< endl;
	temp->Dump();
	cout << endl <<  "Insert 1 to complete or 0 to retry: " << endl;
	return Control(0, 1);
}