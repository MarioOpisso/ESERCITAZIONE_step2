#ifndef _INTERFACE_
#define _INTERFACE_

#include "CPower.h"
#include "CPolynomial.h"
#include "CLogarithmic.h"


void Menu(Function* array[], int size);
void Visualize(Function* array[], int size);
void Insert(Function* array[], int size);
void Delete(Function * array[], int size);
void DeleteALL(Function* array[], int size);
void Selection(Function * array[], int size);

int GetID(Function * array[], int size);
int Control(int a, int b);
bool isEmpty(Function * array[], int size);
int LookForNull(Function * array[], int size);
void ErrorMessage(const char *string);
bool Check(Function* temp);
#endif