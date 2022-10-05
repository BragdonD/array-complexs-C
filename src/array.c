/**
 * @file array.c
 * @author Thomas DUCLOS
 * @brief source file for the array structure and relative functions.
 * @version 0.1
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <string.h>
#include "array.h"

/// @brief Function to init an array at 0.
/// @return the array init at 0.
array init_arr() {
    array to_alloc;
    to_alloc.arr = NULL;
    to_alloc.length = 0;
    return to_alloc;
}

/// @brief Function to insert an new element inside the dynamic array.
/// @param arr the array to be resize.
/// @param elem the new elem.
/// @param i the index to be insert at.
/// @return true on success.
bool insert_into_arr(array* arr, array_type elem, int i) {
    if(i > arr->length) return false;

    array_type* tmp_arr = NULL;
    tmp_arr = realloc(arr->arr, (arr->length + 1) * sizeof(*tmp_arr));
    if(tmp_arr == NULL) {   ///Check if the array has been succesfully reallocated.
        printf("Realloc failed!\n");
        return false;
    }

    for(int j=arr->length; j>i; j--) { ///Shift the element to the right of the inserted element
        tmp_arr[j] = tmp_arr[j-1];
    }

    tmp_arr[i] = elem;
    arr->arr = tmp_arr;
    arr->length += 1;
    return true;
}

/// @brief Function to delete an element inside the dynamic array.
/// @param arr the array to be resize.
/// @param i the index to be delete at.
/// @return true on success.
bool delete_into_arr(array* arr, int i) {
    if(arr->length == 0) return false;
    if(i > arr->length) return false;

    array_type* tmp_arr = NULL;
    tmp_arr = realloc(arr->arr, (arr->length - 1) * sizeof(*tmp_arr));
    if(tmp_arr == NULL) return false; ///Check if the array has been succesfully reallocated.

    for(int j=i; j<arr->length-1; j++) { ///Shift down the element to the right
        tmp_arr[j] = arr->arr[j+1];
    }
    
    arr->arr = tmp_arr;
    arr->length -= 1;
    return true;
}

/// @brief Get the array length
/// @param arr the array
/// @return the length of the array
int arr_lenght(array* arr) {
    return arr->length;
}

/// @brief Function to free the data inside the array
/// @param arr the array to be free
/// @return true on success
bool empty_arr(array* arr) {
    if(arr->length == 0) return false;
    if(arr->arr == NULL) return false;
    free(arr->arr);
    arr->arr = NULL;
    arr->length = 0;
    return true;
}

/// @brief Function to print an array.
/// @brief This function is to be adapted every time the array type change.
/// @param arr the array to be print
void print_arr(array* arr) {
    printf("[");
    for(int i=0; i<arr->length; i++)
    {
        print_Complex(arr->arr[i]);
        printf(i < arr->length - 1 ? ",\n" : "");
    }
    printf("]\n");
}
