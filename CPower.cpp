/*! @file CPower.h
	@brief Implementation of power class
	@author Mario Opisso
*/

#include "CPower.h"

/// @brief default constructor
Power::Power()
{
	cout << endl;
	cout << "POWER -- Default constructor";
	Reset();
}

/// @brief Constructor
/// @param coefficient k: (k*(x^e))
/// @param coefficient e: (k*(x^e))
Power::Power(double k_coefficient, double e_coefficient)
{
	cout << endl;
	cout << "POWER -- Parameter constructor";
	SetPower(k_coefficient, e_coefficient);
}

///@brief copy constructor
Power::Power(const Power& p)
{
	cout << endl;
	cout << "POWER -- Copy constructor";
	Power(p.k_coeff, p.e_coeff);
}

///@brief destructor
Power::~Power()
{
	cout << endl;
	cout << "POWER -- destructor";
	Reset();
}

///@brief overload operator = 
Power& Power::operator=(const Power& p)
{
	SetPower(p.k_coeff, p.e_coeff);
	return *this;
}

///@brief overload operator ==
bool Power::operator==(const Power& p)
{
	if((k_coeff == p.k_coeff)&&(e_coeff == p.e_coeff))
	{
		return true;
	}
	
	return false;
}

///@brief setter of coefficient k and e
///@param coefficient k
///@param coefficient e
void Power::SetPower(double k_coefficient, double e_coefficient)
{
	k_coeff = k_coefficient;
	e_coeff = e_coefficient;
}

///@brief return a value of the function, given an input
///@param in the input
///@return the value of the function
double Power::GetValue(double in)
{
	return k_coeff * pow(in, e_coeff);
}

///@brief reset the coefficient of the function
void Power::Reset()
{
	k_coeff = 0;
	e_coeff = 0;
}

/*void Power::ErrorMessage(const char *string) 
{	
	cout << endl << "ERROR -- Power --";
	cout << string << endl;
}

void Power::WarningMessage(const char *string) 
{
	cout << endl << "WARNING -- Power --";
	cout << string << endl;
}*/

///@brief gives the status of the object
void Power::Dump()
{
	cout << endl;
	cout << "---Power---" << endl;
	cout << endl;
	
	cout << "k coeff = " << k_coeff << endl;
	cout << "e coeff = " << e_coeff << endl;
}