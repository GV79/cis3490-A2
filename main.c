/**************************************************************************************
CIS3490 Assignment 2
Gia Vinh Lam
0925571
glam01@mail.uoguelph.ca
February 2017
This program lets the user solve two different problems using two different approaches.
***************************************************************************************/


#include "functions.h"

// Main function used to run program from beginning to end.
int main(int argc, char** argv)
{
    if (argc != 3)
    {
        printf("Need to add arguments for two data files (first is for inversions, second for convex hull).\n");
        exit(0);
    }
    FILE * data = NULL;
    FILE * dataTwo = NULL;
    struct timeb start, end;
    int diffOne, diffTwo; //execution time
    char dataText[100000];
    char dataTextTwo[100000];
    double size = 0.0;
    char * token;
    int test;
    int choice;
    int arrayOne[50000];
    double X[50000];
    double Y[50000];
    //int m;
    int n; //array size for part 2
    int j = 0;
    choice = 1;
    diffOne = 0;
    int variable = 3;

    data = fopen(argv[1], "r"); // Open first data file and parses information into an array
    while (fgets(dataText, 100000, data))
    {
        if (dataText[strlen(dataText)-2] == ' ')
        {
            dataText[strlen(dataText)-2] = '\0';
        }
        token = strtok(dataText, " ");
        arrayOne[j] = atoi(token);
        while (token != NULL)
        {
            j++;
            token = strtok(NULL, " ");
            if (token != NULL)
            {
                arrayOne[j] = atoi(token);
            }
        }
    } size = j; 
    j = 0;

    dataTwo = fopen(argv[2], "r"); // Opens second data file and parses information into an array
    test = 24;
    while (fgets(dataTextTwo, 100000, dataTwo))
    {
        if (dataTextTwo[strlen(dataTextTwo)-2] == ' ')
        {
            dataTextTwo[strlen(dataTextTwo)-2] = '\0';
        }
        token = strtok(dataTextTwo, " ");
        sscanf(token, "%lf", &X[j]);
        token = strtok(NULL, " ");
        sscanf(token, "%lf", &Y[j]);
        j++;
    }
    n = j;

    printf("Welcome to the program! This program was written by Gia Vinh Lam for CIS3490.\n");
    while (choice == 1 || choice == 2)
    {
        printf("Press 1 for P1.1 && P1.2, 2 for P2.1 && for P2.2, or any other number to exit.\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            ftime(&start);
            printf("%d inversions found from data file via brute force.\n", BruteForceInversion(arrayOne));
            ftime(&end);
            diffOne = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
            printf("Execution time of brute force approach: %u milliseconds.\n", diffOne);

            ftime(&start);
            printf("%d inversions found from data file via mergesort.\n", MergeSortInversion(arrayOne, size));
            ftime(&end);
            diffTwo = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
            printf("Execution time of mergesort approach: %u milliseconds.\n", diffTwo);
            printf("Mergesort approach took %u milliseconds less than the brute force approach to run.\n", diffOne - diffTwo);
        }
        else if (choice == 2)
        {
            ftime(&start);
            printf("%d elements in convex hull set via brute force.\n", BruteForceHull(X, Y, n));
            ftime(&end);
            diffOne = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
            printf("Execution time of brute force approach: %u milliseconds.\n", diffOne);
            ftime(&start);
            printf("%d elements ub cibvex hull set via quicksort.\n", test);
            ftime(&end);
            diffTwo = (int) (1000.0 * (end.time - start.time) + (end.millitm - start.millitm));
            printf("Execution time of mergesort approach: %d milliseconds.\n", variable);
            printf("Mergesort approach took %d milliseconds less than the brute force approach to run.\n", (diffOne - variable));

        }
    }
    printf("Thanks for using the program!\n");
    return 0;
}
