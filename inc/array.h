/**
 * @file array.h
 * @author Thomas DUCLOS
 * @brief this is the header file for the array structure and the relatives functions.
 * @note You need to change the typedef array_type each time you want to change the type of the array. 
 * @note This structure is useful if you have a single type of data to put inside an array of this type.
 * @note If you have multiple type of data you might want to split each type of array.
 * @version 1.2
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>
#include <stdio.h>
#include "complex.h"

typedef complex array_type;

typedef struct array {
    array_type* arr;
    int length;
} array;

array init_arr();
int arr_lenght(array* arr);
bool insert_into_arr(array* arr, array_type elem, int i);
bool delete_into_arr(array* arr, int i);
bool empty_arr(array* arr);
void print_arr(array* arr); ///Need to be edited each time the type is changed.

#endif