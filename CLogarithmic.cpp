/*! @file CLogarithmic.h
	@brief A class for logarithmic functions
	@author Mario Opisso
*/
#include "CLogarithmic.h"

/// @brief default constructor
Logarithmic::Logarithmic()
{
	cout << endl;
	cout << "LOGARITHMIC -- Default constructor";
	Reset();
}

/// @brief constructor
/// @param coefficient b: k*(log b(x))
/// @param coefficient k: k*(log b(x))
Logarithmic::Logarithmic(double b_coefficient, double k_coefficient)
{
	cout << endl;
	cout << "LOGARITHMIC -- Parameter constructor";
	
	if((b_coefficient <= 0)||(b_coefficient == 1))
	{	
		WarningMessage("Unvalid value of b (<= 0)");
		Reset();
		return;
	}
	SetLogarithmic(b_coefficient, k_coefficient);
}

/// @brief copy constructor
Logarithmic::Logarithmic(const Logarithmic& l)
{
	cout << endl;
	cout << "LOGARITHMIC -- Copy constructor";
	Logarithmic(l.b_coeff, l.k_coeff);
}

/// @brief destructor
Logarithmic::~Logarithmic()
{
	cout << endl;
	cout << "LOGARITHMIC -- destructor";
	Reset();
}

/// @brief overload operator=
Logarithmic& Logarithmic::operator=(const Logarithmic& l)
{
	SetLogarithmic(l.b_coeff, l.k_coeff);
	return *this;
}

/// @brief overload operator==
bool Logarithmic::operator==(const Logarithmic& l)
{
	if((b_coeff == l.b_coeff)&&(k_coeff == l.k_coeff))
	{
		return true;
	}
	
	return false;
}

/// @brief setter of coefficient b & k
/// @param coefficient b 
/// @param coefficient k
void Logarithmic::SetLogarithmic(double b_coefficient, double k_coefficient)
{
	k_coeff = k_coefficient;
	b_coeff = b_coefficient;
}

/// @brief return a value of the function, given an input
/// @param in the input
/// @return the value of the function
double Logarithmic::GetValue(double in)
{
	if( in <= 0)
	{
		WarningMessage("Unvalid value (<= 0)");
		return 0;
	}
	return k_coeff * ( log2(in) / log2(b_coeff) );
}

/// @brief reset the coefficient of the function
void Logarithmic::Reset()
{
	k_coeff = 1;
	b_coeff = 10;
}

/// @brief error message
void Logarithmic::ErrorMessage(const char *string) 
{	
	cout << endl << "ERROR -- Logarithmic --";
	cout << string << endl;
}

/// @brief warning message 
void Logarithmic::WarningMessage(const char *string) 
{
	cout << endl << "WARNING -- Logarithmic --";
	cout << string << endl;
}

/// @brief gives the status of the object
void Logarithmic::Dump()
{
	cout << endl;
	cout << "---Logarithmic---" << endl;
	cout << endl;
	
	cout << "k coeff = " << k_coeff << endl;
	cout << "b coeff = " << b_coeff << endl;
}