/**
 * @file complex.h
 * @author Thomas DUCLOS
 * @brief this is the header file for the complex structure and the relative functions declarations.
 * @version 1.3
 * @date 2022-10-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdbool.h>

typedef struct complex {
    double r_part; ///Real Part of the complex number
    double i_part; ///Imaginary Part of the complex number
} complex;

complex Init_Complex(double r_part, double i_part);
void set_realPart_Complex(complex *a, double r_part);
void set_imaginaryPart_Complex(complex *a, double i_part);
void print_Complex(complex a);
void Conj_Complex(complex* a);
double get_realPart_Complex(complex *a);
double get_imaginaryPart_Complex(complex *a);
bool Equ_Complexs(complex a, complex b);
complex Add_Complexs(complex a, complex b);
complex Sub_Complexs(complex a, complex b);
complex Mul_Complexs(complex a, complex b);
complex Div_Complexs(complex a, complex b);
complex write_Complex();

#endif