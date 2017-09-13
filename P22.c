/******************
Giavinh Lam
0925571
CIS3490 A2
This function will be run via entering '2' in the main menu of the program (main.c).
This program contains the function to run problem P2.2:
Given two input arrays (one for x coords and the other for y coords), it will output the convex hull set using a quick sort approach.
******************/

#include "functions.h"

void QuickSortHull(double xArray[30001][7], double yArray[30001][7], int size)
{
//int test = 0;
if (test != 0)
{
    int leftindex = 0;
    int rightindex = 0;
    double rightMost = atof(xArray[0]);
    for(int i = 0; i < size; i++)
    {
        if(rightMost < atof(xArray[i]))
        {
            rightindex = i;
            rightMost = atof(xArray[i]);
        }
    }
    double leftMost = atof(xArray[0]);
    for(int i = 0; i < size; i++)
    {
        if(leftMost > atof(xArray[i]))
        {
            leftindex = i;
            leftMost = atof(xArray[i]);
        }
    }
    double xTemp1[size][7];
    double yTemp1[size][7];
    double xTemp2[size][7];
    double yTemp2[size][7];
    int size2 = 0;
    int size3 = 0;
    int j = 0;
    int k = 0;
    for(int i = 0; i < size; i++)
    {
    ConvexHull[n].x = atof(xArray[leftindex]);
    ConvexHull[n].y = atof(yArray[leftindex]);    n++;

    ConvexHull[n].x = atof(xArray[rightindex]);
    ConvexHull[n].y = atof(yArray[rightindex]);    n++;
    FindHull(xTemp1, yTemp1, atof(xArray[leftindex]), atof(yArray[leftindex]), atof(xArray[rightindex]), atof(yArray[rightindex]), size2);
    FindHull(xTemp2, yTemp2, atof(xArray[rightindex]), atof(yArray[rightindex]), atof(xArray[leftindex]), atof(yArray[leftindex]), size3);
}

        if( 0 > ((atof(xArray[rightindex]) - atof(xArray[leftindex]))*(atof(yArray[i])-atof(yArray[leftindex])) - (atof(yArray[rightindex]) - atof(yArray[leftindex]))*(atof(xArray[i]) - atof(xArray[leftindex]))) )
        {
            strcpy(xTemp1[j], xArray[i]);
            strcpy(yTemp1[j], yArray[i]);
            size2++;
            j++;
        }
        else if( 0 < ((atof(xArray[rightindex]) - atof(xArray[leftindex]))*(atof(yArray[i])-atof(yArray[leftindex])) - (atof(yArray[rightindex]) - atof(yArray[leftindex]))*(atof(xArray[i]) - atof(xArray[leftindex]))))
        {
        strcpy(xTemp2[k], xArray[i]);
            strcpy(yTemp2[k], yArray[i]);
            size3++;
            k++;
        }

    }

}
}

void FindHull(double xArray[30001][7], double yArray[300001][7], double xx, double yy, double xx2, double yy2, int size)
{
    double xTemp1[size][7];
    double xTemp2[size][7];
    double yTemp1[size][7];
    double yTemp2[size][7];
    int distance = 0;
    int index = 0;
    int j = 0; int k = 0;

    for(int i = 0; i < size; i++)
    {
        if(distance < AreaFunction(xx, yy, xx2, yy2, atof(xArray[i]), atof(yArray[i])))
        {
            index = i;
            distance = AreaFunction(xx, yy, xx2, yy2, atof(xArray[i]), atof(yArray[i]));
        }
    ConvexHull[n].x = atof(xArray[index]);
    ConvexHull[n].y = atof(yArray[index]);
    n++;


    if(size == 0)
    {
        return;
    }

        if( (xx2-atof(xArray[index]))*(atof(yArray[i])-atof(yArray[index])) - (yy2-atof(yArray[index]))*(atof(xArray[i])-atof(xArray[index])) < 0 )
    {
        strcpy(xTemp2[k], xArray[i]);
        strcpy(yTemp2[k], yArray[i]);
            k++;
    }
        for(int i = 0; i < size; i++)
    {
        if( (atof(xArray[index])-xx)*(atof(yArray[i])-yy) - (atof(yArray[index])-yy)*(atof(xArray[i])-xx) < 0 ) 
    {
            strcpy(xTemp1[j], xArray[i]);
            strcpy(yTemp1[j], yArray[i]);
            j++;
    }
        
    FindHull(xTemp1, yTemp1, xx, yy, atof(xArray[index]), atof(yArray[index]), j);
    FindHull(xTemp2, yTemp2, atof(xArray[index]), atof(yArray[index]), xx2, yy2, k);

    return;

}
