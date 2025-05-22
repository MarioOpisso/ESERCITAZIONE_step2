/*! @file interface.h
	@brief This is a program to manage an array of Function (polynomial, power and logarithmic).
	@author Opisso Mario
*/

#ifndef _INTERFACE_
#define _INTERFACE_

#include "CPower.h"
#include "CPolynomial.h"
#include "CLogarithmic.h"

/// @name MENU FUNCTION
/// @{
void Menu(Function* array[], int size);
///@}

/// @name MANAGEMENT FUNCTIONS
/// @{
void Visualize(Function* array[], int size);
void Insert(Function* array[], int size);
void Delete(Function * array[], int size);
void DeleteALL(Function* array[], int size);
void Selection(Function * array[], int size);
/// @}

/// @name HANDLING FUNCTIONS
/// @{
int GetID(Function * array[], int size);
int Control(int a, int b);
bool isEmpty(Function * array[], int size);
int LookForNull(Function * array[], int size);
bool Check(Function* temp);
/// @}

/// @name DEBUG AND SERIALIZATION
/// @{
void ErrorMessage(const char *string);
/// @}
#endif