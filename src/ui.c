/**
 * @file ui.c
 * @author Thomas DUCLOS
 * @brief Source file for the ui header. In this source file you can find all the function relative to the interaction with the user.
 * @version 1.2
 * @date 2022-10-04
 * @copyright Copyright (c) 2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <time.h>
#include "ui.h"

/// @brief Retrieve an integer from a string by type checking the content of the string.
/// @param str the string containing the data to be parsed.
/// @param val the integer value that has been extract
/// @return true if success
bool parseInt(char *str, int* val){
    errno = 0;
    char *temp = NULL;
    long res = strtol(str, &temp, 10);

    ///Test if there is an error in the input and handle it
    ///We are checking for integer range because we want to retrieve an int
    if (temp == str || *temp != '\n' ||
        ((res > INT_MAX  || res < INT_MAX ) && errno == ERANGE))
        return false;

    *val = (int) res; ///Cast from long to integer
    return true;
}

/// @brief Retrieve a double from a string by type checking the content of the string.
/// @param str the string containing the data to be parsed.
/// @param val the double value that has been extract
/// @return true if success
bool parseDouble(char *str, double* val) {
    errno = 0;
    char *temp = NULL;
    *val = strtod(str, &temp);

    ///Test if there is an error in the input and handle it
    if (*temp == 0)
        return false;
    return true;
}

/// @brief Get a double number with safe input methods
/// @param val the double value to be retrieve
/// @return true if success
bool getDouble(double* val) {
    char buffer[500];
    fgets(buffer, 500, stdin); ///Safe way to get a string
    return parseDouble(buffer, val);
}

/// @brief Get a integer number with safe input methods
/// @param val the integer value to be retrieve
/// @return true if success
bool getInt(int* val) {
    char buffer[500];
    fgets(buffer, 500, stdin); ///Safe way to get a string
    return parseInt(buffer, val);
}

/// @brief The user's menu. This menu is only intend for this program.
void Menu() {
    printf("Menu :\n");
    printf("1. Create a array of random number.\n");
    printf("2. Insert a number inside the array at a given position.\n");
    printf("3. Delete a element from the array at a given position.\n");
    printf("4. Print the array.\n");
    printf("5. Add complex numbers.\n");
    printf("6. Sub complex numbers.\n");
    printf("7. Mul complex numbers.\n");
    printf("8. Div complex numbers.\n");
    printf("9. Leave\n");
}

/// @brief Function to retrieve the choice made by user inside the menu
/// @return -1 on error
int Choice() {
    int choice = 0;

    printf("Your choice : ");
    
    if(getInt(&choice))
        return choice;
    return -1; ///Error to handle.
}

/// @brief Function to get a random double number
/// @param low the upper boundary of the interval of generation
/// @param high the lower boundary of the interval of generation
/// @return the random number generated
double random_Double( double low, double high )
{
    return ( (double)rand() * ( high - low ) ) / (double)RAND_MAX + low;
}

/// @brief Function to print an operation of complex numbers
/// @param val1 the first complex value
/// @param val2 the second complex value
/// @param operation the symbol of the operation
/// @param result the complex result of the operation
void print_operation(complex val1, complex val2, char operation, complex result) {
    printf("( ");
    print_Complex(val1);
    printf(" )");
    printf(" %c ", operation);
    printf("( ");
    print_Complex(val2);
    printf(" )");
    printf(" = ");
    print_Complex(result);
    printf("\n");
}
