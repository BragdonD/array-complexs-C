#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ui.h"
#include "array.h"
#include "complex.h"

#define LOW_BOUND_DOUBLE -10.0
#define UPPER_BOUND_DOUBLE 10.0

int create_Complex_Array (array *array, int nb);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    if(argc < 2) {
        printf("usage: <path | prog> [number of complex]");
        return EXIT_FAILURE;
    }
    int complexNB = atoi(argv[1]);
    printf("%d complex numbers will be generated...\n", complexNB);

    array arr = init_arr();

    if(create_Complex_Array(&arr, complexNB) == 1) {
        printf("Failed to created array");
        empty_arr(&arr);
        return EXIT_FAILURE;
    }

    print_arr(&arr);

    empty_arr(&arr);
    return EXIT_SUCCESS;
}


int create_Complex_Array (array *array, int nb) {
    for(int i=0; i<nb; i++)
    {
        complex temp;
        set_realPart_Complex(&temp, random_Double(LOW_BOUND_DOUBLE, UPPER_BOUND_DOUBLE));
        set_imaginaryPart_Complex(&temp, random_Double(LOW_BOUND_DOUBLE, UPPER_BOUND_DOUBLE));
        if(!insert_into_arr(array, temp, i )) {
            printf("Failed to insert into array !\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}