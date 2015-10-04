/*
 * File:   main.c
 * Author: Francisco
 *
 * Created on 3 de Outubro de 2015, 22:28
 */

/*
 * O Problema
 * Dada um conjunto de N intervalos de números, a tua tarefa é descobrir, para cada intervalo, qual o(s)
 * dígito(s) que aparece mais vezes, bem como quantas vezes ele aparece.
 *
 * Input
 * Na primeira linha vem um único número inteiro N, indicando a quantidade de intervalos a considerar.
 * Nas N linhas seguintes vem um par de números Ai Bi (separados por um espaço), indicando que i-ésimo
 * intervalo de números a considerar é [A,B] (ou seja, os números de A a B, inclusive).
 *
 * Output
 * O output deve ser constituído por N linhas, uma para cada um dos intervalos do input. Cada uma destas
 * linhas deve começar por ter um número inteiro indicando quantas vezes aparece o dígito mais frequente,
 * seguida de uma lista (por ordem crescente) dos dígitos que aparecem com essa frequência máxima. Todos
 * os números de uma mesma linha devem ser separados por um único espaço.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_NUMBER 1000000000

uint32_t inputmatrix[5][2] = {
    {4, 0}, // -- 1-1000 --
    {88, 90}, // 88, 89, 90 // -- 1 - 1 000 000 000 --
    {99, 100}, // 99, 100
    {1, 9}, // 1, 2, 3, 4, 5, 6, 7, 8, 9
    {1, 10} // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
};

uint32_t count[10];

// 0 1 2 3 4 5 6 7 8 9 // 1 u
// 10 11 12 13 14 15 16 17 18 19 // 1 u 10 Ed
// 100 101 102 103 104 105 106 107 108 109 // 10 Eu 10 Ed 100 c
// 110 111 112 113 114 115 116 117 118 119
// 1000 1001 1002 1003 1004 1005 1006 1007 1008 1009 // 100 Eu 100 Ed 100 Ec 1000 m
// 1010 1011 1012 1013 1014 1015 1016 1017 1018 1019 //
// 1100 1101 1102 1103 1104 1105 1106 1107 1108 1109
// 1110 1111 1112 1113 1114 1115 1116 1117 1118 1119
// 10000 10001 10002 10003 10004 10005 10006 10007 10008 10009 // 1000 Eu 1000 Ed 1000 Ec 1000 Em 10000 dm
// 10010 10011 10012 10013 10014 10015 10016 10017 10018 10019
// 10100 10101 10102 10103 10104 10105 10106 10107 10108 10109
// 11000 11001 11002 11003 11004 11005 11006 11007 11008 11009

void calc_freq_base(uint32_t a, uint32_t b);
void calc_freq();

/*
 *
 */
int main(int argc, char** argv)
{
    uint32_t a = 533;
    uint32_t b = 1066;

    calc_freq_base(a, b);
    print_freq();
    printf("\n");
    calc_freq(a, b);
    print_freq();

    return (EXIT_SUCCESS);
}

void calc_freq_base(uint32_t a, uint32_t b)
{
    uint32_t i, j;

    for (i = 0; i < 10; i++)
    {
        count[i] = 0;
    }

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
    int32_t m, n, i, j, k;

    for (i = 0; i < 10; i++)
    {
        count[i] = 0;
    }

    // find magnitude
    for (i = 10, m = -1; !(a % i); i *= 10)
        m++;

    // i = 100
    // m = 0

    for (n = a; n <= b;)
    {
        if (n % i)
        {
            // don't count for more than the last from sequence
            while (n + i / 10 > b)
            {
                // decrease magnitude
                i /= 10;
                m--;
            }

            // count unity
            if (i > 10)
            {
                for (k = 0; k < 10; k++)
                {
                    count[k] += quick_pow10(m);
                }
            }
            else
            {
                count[n % 10] += quick_pow10(m);
            }

            for (j = n / 10; j > 0; j /= 10)
            {
                if (j < 10) // count left most
                {
                    count[j] += quick_pow10(m + 1);
                }
                else // count others
                {
                    if (i > 10)
                    {
                        for (k = 0; k < 10; k++)
                        {
                            count[k] += quick_pow10(m);
                        }
                    }
                    else
                    {
                        count[n % 10] += quick_pow10(m);
                    }
                }
            }

            n += i == 1 ? 1 : i / 10;
        }
        else
        {
            // increase magnitude
            i *= 10;
            m++;
        }
    }
}

void print_freq()
{
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("%d = %d\n", i, count[i]);
    }
}

int quick_pow10(int n)
{
    static int pow10[10] = {
        1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
    };

    if (n < 0)
        return 1;
    else
        return pow10[n];
}

/*
 3 8
 2 0 9
 1 1 2 3 4 5 6 7 8 9
 2 1
 */