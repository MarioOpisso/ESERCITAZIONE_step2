/*! @file CPower.h
	@brief A class for power functions
	@author Mario Opisso
*/

#ifndef POWER_H
#define POWER_H

#include "CFunction.h"


/// @class Power
/// @brief a base class for power
class Power : public Function
{
	private: 
		double  k_coeff;
		double  e_coeff; 
		
	public: 
		///@name CONTRUCTORS/DESTRUCTOR
		///@{
		Power();
		Power(double k_coefficient, double e_coefficient);
		Power(const Power& p);
		~Power();
		///@}
		
		///@name OPERATORS
		/// @{
		Power& operator=(const Power& p);
		bool operator==(const Power& p);
		/// @}
		
		///@name BASIC HANDLING
		/// @{
		void Reset();
		/// @}
		
		///@name SETTER
		/// @{
		void SetPower(double k_coefficient, double e_coefficient);
		/// @}
		
		///@name GETTER
		/// @{
		double GetValue(double in);
		///@}
		
		//void ErrorMessage(const char *string); 
		//void WarningMessage(const char *string);
		
		///@name DEBUG AND SERIALIZATION
		/// @{
		void Dump();
		///@}
};

#endif