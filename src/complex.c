/**
 * @file complex.c
 * @author Thomas DUCLOS
 * @brief Source file for the complex header. In this source file, you will find all the operations on the complex numbers structure.
 * @version 1.3
 * @date 2022-10-04
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include "complex.h"
#include "ui.h"

/// @brief Init a complex number with a real part and an imaginary part.
/// @param r_part real part of the complex number
/// @param i_part imaginary part of the complex number
/// @return a copy of the complex structure that has been created.
complex Init_Complex(double r_part, double i_part) {
    complex tmp;
    tmp.r_part = r_part;
    tmp.i_part = i_part;
    return tmp;
}

/// @brief Function to conjugate a complex number
/// @param a the complex number to be conjugated
void Conj_Complex(complex* a) {
    a->i_part = -(a->i_part);
}

/// @brief Function to add two complex numbers
/// @param a the first number.
/// @param b the second number.
/// @return the result of the operation.
complex Add_Complexs(complex a, complex b) {
    complex new_c = Init_Complex(0.0,0.0);
    new_c.r_part = a.r_part + b.r_part;
    new_c.i_part = a.i_part + b.i_part;
    return new_c;
}

/// @brief Function to substract two complex numbers
/// @param a the first number.
/// @param b the second number.
/// @return the result of the operation.
complex Sub_Complexs(complex a, complex b) {
    complex new_c = Init_Complex(0.0,0.0);
    new_c.r_part = a.r_part - b.r_part;
    new_c.i_part = a.i_part - b.i_part;
    return new_c;
}

/// @brief Function to multiply two complex numbers.
/// @param a the first number.
/// @param b the second number.
/// @return the result of the operation.
complex Mul_Complexs(complex a, complex b) {
    /// Multiplication of complex numbers is given by :
    /// z1 = a1 + ib1 et z2 = a2 + ib2
    /// z1*z2 = (a1 + i*b1) +i*(a2 + i*b2)
    /// z1*z2 = a1*a2 + a1*b2*i + i*a2*b1 + b2*b1*i^2
    /// or i^2 = -1
    /// z1*z2 = (a1*a2 - b1*b2) +i*(a1*b2+a2*b1)
    complex new_c = Init_Complex(0.0,0.0);
    new_c.r_part = a.r_part*b.r_part - a.i_part*b.i_part;
    new_c.i_part = a.r_part*b.i_part + a.i_part*b.r_part;
    return new_c;
}

/// @brief Function to divide two complex numbers.
/// @param a the numerator.
/// @param b the denominator.
/// @return the result of the operation.
complex Div_Complexs(complex a, complex b) {
    /// Division of complex numbers is given by :
    /// z1 = a1 + ib1 et z2 = a2 + ib2
    /// z1/z2 = (a1 + i*b1) / (a2 + i*b2)
    /// z1/z2 = [(a1 + i*b1) (a2 - i*b2)] / [(a2 + i*b2) (a2 - i*b2)]
    /// z1/z2 = [(a1 * a2) - (a1 * b2 * i) + (a2 * b1 * i) + (b1 * b2)] / (a2^2 + b2^2)
    /// z1*z2 = [(a1 * a2) + (b1 * b2) + i * (a2 * b1 - a1 * b2)] / (a2^2 + b2^2)
    /// z1*z2 = [(a1 * a2) + (b1 * b2)] / (a2^2 + b2^2) + [i * (a2 * b1 - a1 * b2)] / (a2^2 + b2^2)
    complex new_c = Init_Complex(0.0,0.0);
    new_c.r_part = (a.r_part*b.r_part -+ a.i_part*b.i_part) / ( a.r_part*a.r_part + b.r_part*b.r_part);
    new_c.i_part = (a.r_part*b.i_part - a.i_part*b.r_part) / ( a.r_part*a.r_part + b.r_part*b.r_part);
    return new_c;
}

/// @brief Function to test the equality of two complex numbers.
/// @param a The first complex number.
/// @param b The second complex number.
/// @return true if they are equal.
bool Equ_Complexs(complex a, complex b) {
    return ((a.r_part == b.r_part) && (b.i_part == a.i_part));
}

/// @brief Function to print a complex number. Limited to 1 number after the dot.
/// @param a The complex number to be print.
void print_Complex(complex a) {
    printf("%.1f + %.1fi", a.r_part, a.i_part);
}

/// @brief Function to write a complex number and store it inside a complex variable.
/// @return The complex variable created from the user's inputs.
complex write_Complex() {
    complex new_c = Init_Complex(0.0,0.0);
    do {
        printf("Please write the real part of the number : ");
    } while (!getDouble(&new_c.r_part));
    do {
        printf("Please write the imaginary part of the number : ");
    } while (!getDouble(&new_c.i_part));
    return new_c;
}

/// @brief Function to set the real part of the complex structure.
/// @param a a complex number.
void set_realPart_Complex(complex *a, double r_part) {
    a->r_part = r_part;
}

/// @brief Function to set the imaginary part of the complex structure.
/// @param a a complex number.
void set_imaginaryPart_Complex(complex *a, double i_part) {
    a->i_part = i_part;
}

/// @brief Function to get the real part of the complex structure.
/// @param a a complex number.
/// @return the real part.
double get_realPart_Complex(complex *a) {
    return a->r_part;
}

/// @brief Function to get the imaginary part of the complex structure.
/// @param a a complex number.
/// @return the imaginary part.
double get_imaginaryPart_Complex(complex *a) {
    return a->i_part;
}
