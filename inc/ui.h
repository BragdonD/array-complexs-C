/**
 * @file ui.h
 * @author Thomas DUCLOS
 * @brief this is the header file for the user interface.
 * @version 1.2
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef UI_H
#define UI_H

#include <stdbool.h>
#include "complex.h"


void Menu();
int Choice();

bool parseInt(char *str, int* val);
bool parseDouble(char *str, double* val);
bool getInt(int* val);
bool getDouble(double* val);

double random_Double( double low, double high );
void print_operation(complex val1, complex val2, char operation, complex result);

#endif