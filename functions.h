#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/timeb.h>


double AreaFunction(double xvalueOne, double yvalueOne, double xvalueTwo, double yvalueTwo, double x3, double y3);
//Function comments are in the .c files
int BruteForceInversion(int A[50000]);
int MergeSortInversion(int A[50000], double size);
int Merge(int A[], int B[], int C[], int p, int q);
int BruteForceHull(double X[30000], double Y[30000], int n);
void QuickSortHull(double xArray[30001][7], double yArray[30001][7], int size);
