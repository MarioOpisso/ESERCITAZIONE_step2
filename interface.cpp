#include "interface.h"

void Menu(Function* array[], int size)
{
	cout << endl;
	cout << "Welcome to the menu: " << endl;
	
	bool state = 1;
	int option_ = 0;

	while(state)
	{
		cout << "0- Exit from menu." << endl;
		cout << "1- Visualize function list." << endl;
		cout << "2- Insert function." << endl;
		cout << "3- Delete a function." << endl;
		cout << "4- Delete all functions." << endl;
		cout << "5- Select a function." << endl;
		
		cin >> option_;
		while(option_ < 0 || option_ > 5)
		{
			cout << endl << "Invalid option, retry: " << endl;
			cin >> option_;
		}
		
		switch(option_)
		{
			case 0:
				state = 0;
				cout << endl << "Exiting the menu..." << endl;
				break;
			case 1:
				Visualize(array, size);
				break;
			case 2:				
				Insert(array, size);
				break;
			case 3:
			case 4:
				DeleteALL(array, size);
				break;
			case 5:
			default:
				break;
		}
	}
}


void Visualize(Function* array[], int size)
{
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

void Insert(Function* array[], int size)
{
	int coeff;
	int option;
	int val;

	cout << endl << "Select the type of function: " << endl;
	cout << "0- Polynomial" << endl;
	cout << "1- Power" << endl;
	cout << "2- Logarithmic" << endl;
				
	cin >> option;
	while(option < 0 || option > 2)
	{
		cout << endl << "Invalid option, retry: " << endl;
		cin >> option;
	}

	switch(option)
	{
		case 0:
			cout << endl << "How many coefficients?" << endl;
			cin >> coeff;
			
			double* cf;
			cf = new double[coeff];
			if(cf == NULL)
			{
				//error
				return;
			}
			
			for(int x = 0; x < coeff; x++)
			{
				cout << endl << "Insert the coefficient in position number " << x << ":" << endl;
				cin >> cf[x];
			}
			
			for(int i = 0; i < size; i++)
			{
				if(array[i] == NULL)
				{
					array[i] = new Polynomial(cf, coeff);
					break;
				}
			}
			
			delete cf;
			break;
			
		case 1:
			for(int i = 0; i < size; i++)
			{
				if(array[i] == NULL)
				{
					cout << endl << "Insert the exponent: ";
					cin >> val;
					cout << endl << "Insert the coefficient k: ";
					cin >> coeff;
					
					array[i] = new Power((double)coeff, (double)val);
					break;
				}
			}
			break;
		
		case 2:
			for(int i = 0; i < size; i++)
			{
				if(array[i] == NULL)
				{
					cout << endl << "Insert the base: ";
					cin >> val;
					cout << endl << "Insert the coefficient k: ";
					cin >> coeff;
					
					array[i] = new Logarithmic((double)val, (double)coeff);
					break;
				}
			}
			break;

		default:
			break;
	}
}


void DeleteALL(Function* array[], int size)
 {
	 for(int i = 0; i < size; i++)
	 {
		 delete array[i];
		 array[i] = NULL;
	 }
	 
	return;
 }