#ifndef UI_H
#define UI_H

#include <stdbool.h>
#include "complex.h"

///User's functions to interact with complex number and the program
void Menu();
int Choice();
///Functions to get safe input
bool parseInt(char *str, int* val);
bool parseDouble(char *str, double* val);
///Functions to reduce the number of input to get safe input
bool getInt(int* val);
bool getDouble(double* val);

double random_Double( double low, double high );

#endif