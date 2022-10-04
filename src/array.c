#include <stdlib.h>
#include <string.h>
#include "array.h"

array init_arr() {
    array to_alloc;
    to_alloc.arr = NULL;
    to_alloc.length = 0;
    return to_alloc;
}

bool insert_into_arr(array* arr, array_type elem, int i) {
    if(i > arr->length) return false;

    array_type* tmp_arr = NULL;
    tmp_arr = realloc(arr->arr, arr->length + 1);
    if(tmp_arr == NULL) {
        printf("Realloc failed!\n");
        return false;
    }

    for(int j=arr->length; j>i; j--) {
        printf("%d\n", j);
        tmp_arr[j] = tmp_arr[j-1];
    }
    tmp_arr[i] = elem;
    arr->arr = tmp_arr;
    arr->length += 1;
    return true;
}

bool delete_into_arr(array* arr, int i) {
    if(arr->length == 0) return false;
    if(i > arr->length) return false;

    array_type* tmp = NULL;
    tmp = realloc(arr->arr, arr->length - 1);
    if(tmp == NULL) return false;

    for(int j=i; j<arr->length-1; j++) {
        tmp[j] = arr->arr[j+1];
    }
    
    arr->arr = tmp;
    arr->length -= 1;
    return true;
}

int arr_lenght(array* arr) {
    return arr->length;
}

bool empty_arr(array* arr) {
    if(arr->length == 0) return false;
    free(arr->arr);
    arr->arr = NULL;
    arr->length = 0;
    return true;
}

void print_arr(array* arr) {
    printf("[");
    for(int i=0; i<arr->length; i++)
    {
        print_Complex(arr->arr[i]);
        printf(i < arr->length - 1 ? ",\n" : "");
    }
    printf("]\n");
}