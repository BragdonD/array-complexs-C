### Array-complex-Numbers in C

This repository was made for an exercice in Data Structures courses at Ajou University in 2022. The goal of the exercice was to implement a basic structure to use the complex numbers structure create inside previously at this link (https://github.com/BragdonD/complex-numbers-C) and to combine it with the array structure created at this link (https://github.com/BragdonD/dynamic-array-c). You can find the exercice inside `exercice.md`.

## Folder-organisation

In the inc folder you will find the header for each files In the src folder you will find the implementation of all the function. I divided the project in three parts, the first part is about the complex numbers. The second part is the array structure. The third part is about the user's interface.

## How to use it

First you will need to build the project, the makefile is provided with the program, so you just need to enter the following command at the racine of the workspace folder: mingw32-make. Ok so now, you have build the project, (the makefile is setup to compile the program for debug mode) you can now run the program by running the following once again at the racine of the workspace folder : .\bin\main.

In the program, you will be able to use multiple commands. They will be presented to you by a menu when the program is running.

## Warning

The realloc failed is considerated as a irrevocable. So if it happens the memory will be free and the program will be exited.
Please do not create the bin and obj folder. They will be created by the makefile. Plus do not touch to the created files inside those two folders.
