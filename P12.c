/******************
Giavinh Lam
0925571
CIS3490 A2
This function will be run via entering '1' oin the main menu of the program (main.c).
This program contains the function to run problem P1.2:
Given an input array, it will output number of inversions found using a mergesort method
******************/

#include "functions.h"

int MergeSortInversion(int A[50000], double size)
{
    int i = 0;
    int j = 0;
    if(size > 1)
    {
    	int size2 = floor(size/2);
    	int size3 = ceil(size/2);
    	int B[size2];
    	int C[size3];

    	for(i = 0; i < size2; i++)
    	{
        	B[i] = A[i];
    	}
    	
        for(i = size2; i < size; i++)
    	{
        	C[j] = A[i];
                j++;
    	}

        return MergeSortInversion(B, size2) + MergeSortInversion(C, size3) + Merge(A,B,C,size2,size3);
    }
    	return 0;
}

int Merge(int A[], int B[], int C[], int p, int q)
{
    int i = 0; int j = 0;
    int count = 0;
    int k = 0;
    while(i < p  && j < q )
    {
        if(B[i] <= C[j])
        {
            A[k] = B[i];
            i++;
        }
        else{
            A[k] = C[j];
            j++;
            count += p - i;
        }
        k++;
    }
    if(i == p)
    {
        for(; j < q; j++)
        {
            A[k] = C[j];
            k++;
        }
    }
    else{
        for(; i < p; i++)
        {
            A[k] = B[i];
            k++;
        }

    }

    return count;
}
