/*
 * File:   main.c
 * Author: Francisco
 *
 * Created on 3 de Outubro de 2015, 22:28
 */

/*
 * O Problema
 * Dada um conjunto de N intervalos de numeros, a tua tarefa e descobrir, para cada intervalo, qual o(s)
 * digito(s) que aparece mais vezes, bem como quantas vezes ele aparece.
 *
 * Input
 * Na primeira linha vem um unico numero inteiro N, indicando a quantidade de intervalos a considerar.
 * Nas N linhas seguintes vem um par de numeros Ai Bi (separados por um espaco), indicando que i-esimo
 * intervalo de numeros a considerar e [A,B] (ou seja, os numeros de A a B, inclusive).
 *
 * Output
 * O output deve ser constituido por N linhas, uma para cada um dos intervalos do input. Cada uma destas
 * linhas deve comecar por ter um numero inteiro indicando quantas vezes aparece o digito mais frequente,
 * seguida de uma lista (por ordem crescente) dos digitos que aparecem com essa frequencia maxima. Todos
 * os numeros de uma mesma linha devem ser separados por um unico espaco.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
 * 0 1 2 3 4 5 6 7 8 9 // 1 u
 * 10 11 12 13 14 15 16 17 18 19 // 1 u 10 Ed
 * 100 101 102 103 104 105 106 107 108 109 // 10 Eu 10 Ed 100 c
 * 1000 1001 1002 1003 1004 1005 1006 1007 1008 1009 // 100 Eu 100 Ed 100 Ec 1000 m
 * 10000 10001 10002 10003 10004 10005 10006 10007 10008 10009 // 1000 Eu 1000 Ed 1000 Ec 1000 Em 10000 dm
 * */

void calc_freq_base(uint32_t a, uint32_t b);
uint64_t quick_pow10(int32_t n);
void calc_freq();
void print_most_frequent();
void print_help();

uint32_t count[10];

int32_t main(int32_t argc, char** argv)
{
    uint32_t a = 0;
    uint32_t b = 0;
    uint32_t i, j, k;
    int32_t intervals = 0;
    char arg;
    uint8_t interactive = 0;
    uint8_t simple = 0;

    for (i = 1; i < argc; i++)
    {
        if (*(argv + i)[0] == '-')
        {
            k = strlen(*(argv + i) + 1);

            for (j = 0; j < k; j++)
            {
                arg = *(*(argv + i) + 1 + j);

                switch (arg)
                {
                case 'i':
                    interactive = 1;
                    break;
                case 'h':
                    print_help();
                    return (EXIT_SUCCESS);
                    break;
                case 's':
                    simple = 1;
                    break;
                default:
                    break;
                }
            }
        }
    }

    if (interactive)
        printf("Insert the number of intervals do consider: ");
    fscanf(stdin, "%u", &intervals);

    for (i = 0; i < intervals; i++)
    {
        if (interactive)
            printf("Insert first and second elements of the interval [e.g.: 33 453]: ");

        fscanf(stdin, "%u%u", &a, &b);

        if (simple)
            calc_freq_base(a, b);
        else
            calc_freq(a, b);

        print_most_frequent();
    }

    return (EXIT_SUCCESS);
}

void print_most_frequent()
{
    uint16_t i;
    uint32_t j;

    for (i = 0, j = 0; i < 10; i++)
    {
        // find the most frequent
        if (count[i] > j)
            j = count[i];
    }

    printf("%u", j);

    for (i = 0; i < 10; i++)
    {
        // print the most frequent
        if (count[i] == j)
            printf(" %u", i);
    }

    printf("\n");
}

void calc_freq_base(uint32_t a, uint32_t b)
{
    uint32_t i, j;

    // initilize counters
    for (i = 0; i < 10; i++)
    {
        count[i] = 0;
    }

    // just pass thru the numbers and count them
    for (i = a; i <= b; i++)
    {
        j = i;
        while (j > 0)
        {
            count[j % 10]++;
            j /= 10;
        }
    }
}

void calc_freq(uint32_t a, uint32_t b)
{
    uint64_t magnitude;
    int32_t m, n, i, j, k;

    // initialize counters
    for (i = 0; i < 10; i++)
    {
        count[i] = 0;
    }

    // adjust magnitude
    for (magnitude = 10, m = -1; !(a % magnitude); magnitude *= 10)
        m++;

    for (n = a; n <= b;)
    {
        if (n % magnitude)
        {
            // don't count for more than the last from the sequence
            while (n + magnitude / 10 > b)
            {
                // decrease magnitude
                magnitude /= 10;
                m--;
            }

            // first count rightmost digit
            if (magnitude > 10)
            {
                // if magnitude is more than 10^1, increase every unity by 10^m for m >= 0 or 1 for m < 0
                for (i = 0; i < 10; i++)
                {
                    count[i] += quick_pow10(m);
                }
            }
            else
            {
                // else, increase current unity by 10^m for m >= 0 or 1 for m < 0
                count[n % 10] += quick_pow10(m);
            }

            // now count other digits
            for (k = 3, j = n / 10; j > 0; j /= 10, k++)
            {
                if (j < 10) // count lefmost digit
                {
                    // increase current digit by 10^(m+1) for (m+1) >= 0 or 1 for (m+1) < 0
                    count[j] += quick_pow10(m + 1);
                }
                else // count other digits
                {
                    if (magnitude < quick_pow10(k))
                    {
                        // if magnitude is less then current magnitude, increase current digit by 10^(m+1) for (m+1) >= 0 or 1 for (m+1) < 0
                        count[j % 10] += quick_pow10(m + 1);
                    }
                    else
                    {
                        for (i = 0; i < 10; i++)
                        {
                            // else increase increase every digit by 10^m+ for m >= 0 or 1 for m < 0
                            count[i] += quick_pow10(m);
                        }
                    }
                }
            }

            // jump for the next chunk
            n += magnitude == 1 ? 1 : magnitude / 10;
        }
        else
        {
            // increase magnitude
            magnitude *= 10;
            m++;
        }
    }
}

void print_help()
{
    printf("IMPERIAL FLEET PROBLEM - Introducao a informatica\n\n");
    printf("SYNOPSIS\n\n");
    printf("\tPrints the most frequent digits in a given interval.\n\n");

    printf("DESCRIPTION\n\n");
    printf("\tINPUT:\n\t\tThis program uses the stdin. Type 'program < input.txt' for file input or use the -i argument for interactive mode.\n\n");

    printf("\tFORMAT:\n\t\tThe first line holds an integer 'N' with the number of intervals do consider. This number must be 1 <= N <= 1,000.\n");
    printf("\t\tThe following lines are composed of two integers 'A' and 'B'. These numbers must be 1 <= A <= B <= 1,000,000,000.\n\n");

    printf("\tOUTPUT:\n\t\tThe output is composed of N lines. The first number tells the frequency and the following numbers the digits that are most frequent.\n\n");

    printf("OPTIONS\n\n");
    printf("\t-h This help.\n\n");
    printf("\t-i Interactive mode.\n\n");
    printf("\t-s Simple, not optimized, algorithm.\n\n");

    printf("AUTHOR\n\n");
    printf("\tFrancisco Bischoff.\n\n");
}

uint64_t quick_pow10(int32_t n)
{
    static uint64_t pow10[11] = {
        1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000
    };

    if (n < 0)
        return 1;
    else
        return pow10[n];
}
