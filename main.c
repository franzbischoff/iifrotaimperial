/*
 * File:   main.c
 * Author: Francisco
 *
 * Created on 3 de Outubro de 2015, 22:28
 */

#include <stdio.h>
#include <stdlib.h>

uint32_t inputmatrix[2][5] = {
    {4, 0}, // -- 1-1000 --
    {88, 90}, // 88, 89, 90 // -- 1 - 1 000 000 000 --
    {99, 100}, // 99, 100
    {1, 9}, // 1, 2, 3, 4, 5, 6, 7, 8, 9
    {1, 10} // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};

uint32_t count[10];

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
// 101 102 103 104 105 106 107 108 109 110 111 112 113 114 115 116 117 118 119 120

/*
 *
 */
int main(int argc, char** argv)
{
    uint32_t a = 102;
    uint32_t b = 533;
    uint32_t n;

    for (n = a; n < b; n++)



    return (EXIT_SUCCESS);
}

/*
 3 8
 2 0 9
 1 1 2 3 4 5 6 7 8 9
 2 1
 */