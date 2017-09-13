/******************
Giavinh Lam
0925571
CIS3490 A2
This function will be run via entering '1' oin the main menu of the program (main.c).
This program contains the function to run problem P1.1:
Given an input array, it will output number of inversions found using brute force
******************/

#include "functions.h"

int BruteForceInversion(int A[50000])
{
    int c = 0;
    for (int i = 0; i <= 50000-2; i++)
    {
        for (int j = i+1; j <= 50000-1; j++)
        {
            if (A[i] > A[j])
            {
                c++;
            }
        }
    }
    return c;
}

