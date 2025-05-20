/*! @file CLogarithmic.h
	@brief A class for logarithmic functions
	@author Mario Opisso
*/

#ifndef POWER_H
#define POWER_H

#include "CFunction.h"
/// @class Logarithmic
/// @brief A base class for Logarithmic
class Logarithmic : public Function
{
	private: 
		double  b_coeff;
		double  k_coeff; 
		
	public:
		///@name CONTRUCTORS/DESTRUCTOR
		///@{
		Logarithmic();
		Logarithmic(double b_coefficient, double k_coefficient);
		Logarithmic(const Logarithmic& l);
		~Logarithmic();
		///@}
		
		///@name OPERATORS
		///@{
		Logarithmic& operator=(const Logarithmic& l);
		bool operator==(const Logarithmic& l);
		///@}
		
		///@name SETTERS
		///@{
		void SetLogarithmic(double b_coefficient, double k_coefficient);
		///@}
		
		///@name GETTER
		///@{
		double GetValue(double in);
		///@}
		
		///@name BASIC HANDLING
		///@{
		void Reset();
		///@}
		
		///@name DEBUG AND SERIALIZATION
		///@{
		void ErrorMessage(const char *string); 
		void WarningMessage(const char *string);
		void Dump();
		///@}
};

#endif