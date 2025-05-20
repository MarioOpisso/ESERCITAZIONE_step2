#ifndef _INTERFACE_
#define _INTERFACE_

#include "CPower.h"
#include "CPolynomial.h"
#include "CLogarithmic.h"


void Menu(Function* array[], int size);
void Visualize(Function* array[], int size);
void Insert(Function* array[], int size);
//bool Delete(Functon * array, int& size, int choice);
void DeleteALL(Function* array[], int size);
//void Selection(Functon * array, int& size, int choice);

#endif