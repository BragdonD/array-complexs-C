#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ui.h"
#include "array.h"
#include "complex.h"

#define LOW_BOUND_DOUBLE -10.0
#define UPPER_BOUND_DOUBLE 10.0

int create_Complex_Array (array *array, int length);

//////////////////////////////////////////////////////////////////
///                                                            ///
/// This program has been made by Thomas DUCLOS.               ///
/// Its objective is to create an array of complex numbers and ///
/// to do the basic arithmetic operations on those numbers.    ///
/// The array is a dynamic array, you can add and remove       ///
/// elements from it.                                          ///
///                                                            ///
//////////////////////////////////////////////////////////////////

int main(int argc, char const *argv[])
{
    // Initialisation of the variables
    array arr = init_arr();
    complex new_Complex = Init_Complex(0.0, 0.0);
    int position = -1;
    int complexArrLength = 0;
    int choice = -1;
    int index1 = -1, index2 = -1;

    srand(time(NULL)); 

    do {
        Menu();
        if( ( choice = Choice() ) == -1) // Check if the choice was sucessfull
            return EXIT_FAILURE;
        // If the choice is an arithmetic operation we need to check if we had enough values inside the array
        if( choice == 5 || choice == 6 || choice == 7 || choice == 8) { 
            if(arr_lenght(&arr) == 0) {
                printf("Impossible to do any operation on an empty array!\n");
                printf("A random array will be generated.\n");
                choice = 1;
            }
            else {
                printf("Write the index of the first element.\n");
                while(!getInt(&index1) || ( index1 < 0 || index1 >= arr_lenght(&arr)));
                printf("Write the index of the second element.\n");
                while(!getInt(&index2) || ( index2 < 0 || index2 >= arr_lenght(&arr)));
            }
        }
 
        switch (choice) /// Main part of the program
        {
        case 1: ///Create an array
            if(arr.arr != NULL) {
                printf("Emptying the previous array.\n");
                empty_arr(&arr);
            }
            printf("Write the number of complex numbers to generate : ");
            while(!getInt(&complexArrLength));
            printf("%d complex numbers will be generated...\n", complexArrLength);
            if(create_Complex_Array(&arr, complexArrLength) == 1) {
                printf("Failed to created array.\n");
                empty_arr(&arr);
                return EXIT_FAILURE;
            }
            break;
        case 2: ///Insert inside the array at a given position
            new_Complex = write_Complex();
            printf("Write index to insert the new complex number.\n");
            while(!getInt(&position));
            if(!insert_into_arr(&arr, new_Complex, position)) {
                printf("Failed to insert new complex into the array.\n");
                empty_arr(&arr);
                return EXIT_FAILURE;
            }
            break;
        case 3: ///Delete inside the array at a given position
            printf("Write index to delete the complex number.\n");
            while(!getInt(&position));
            if(!delete_into_arr(&arr, position)) {
                printf("Failed to delete complex from the array.\n");
                empty_arr(&arr);
                return EXIT_FAILURE;
            }
            break;
        case 4: ///Print the array values
            print_arr(&arr);
            break;
        case 5: ///Add Complex numbers + print output
            print_operation(arr.arr[index1], arr.arr[index2], '+', Add_Complexs(arr.arr[index1],arr.arr[index2]));
            break;
        case 6: ///Sub Complex numbers + print output
            print_operation(arr.arr[index1], arr.arr[index2], '-', Sub_Complexs(arr.arr[index1],arr.arr[index2]));
            break;
        case 7: ///Multiply Complex numbers + print output
            print_operation(arr.arr[index1], arr.arr[index2], '*', Mul_Complexs(arr.arr[index1],arr.arr[index2]));
            break;
        case 8: ///Divide Complex numbers + print output
            print_operation(arr.arr[index1], arr.arr[index2], '/', Div_Complexs(arr.arr[index1],arr.arr[index2]));
            break;
        case 9: ///Leave the program
            printf("Leaving...\n");
            break;
        default: ///Wrong input
            printf("Input corresponds to 0 proposition in the menu.");
            break;
        }
    } while(choice != 9);

    empty_arr(&arr);
    return EXIT_SUCCESS;
}

/// @brief Function to generate n random complex numbers inside an array
/// @brief The function use the define number LOW_BOUND_DOUBLE and UPPER_BOUND_DOUBLE 
/// @brief to generate the doubles of the real and imaginary part of the complex number.
/// @brief Edit them to change the interval of the numbers.
/// @param array The array of complex numbers
/// @param length The number of complex numbers to create
/// @return 1 on FAILURE - 0 on SUCCESS
int create_Complex_Array (array *array, int length) {
    complex temp = Init_Complex(0.0, 0.0);
    if(length <= 0) return EXIT_FAILURE;
    for(int i=0; i<length; i++)
    {
        
        set_realPart_Complex(&temp, random_Double(LOW_BOUND_DOUBLE, UPPER_BOUND_DOUBLE));
        set_imaginaryPart_Complex(&temp, random_Double(LOW_BOUND_DOUBLE, UPPER_BOUND_DOUBLE));
        if(!insert_into_arr(array, temp, i )) {
            printf("Failed to insert into array !\n");
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}