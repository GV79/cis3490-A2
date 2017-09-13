#include "functions.h"

int BruteForceHull(double X[50000], double Y[50000], int n)
{
    double convexX[50000] = {0.0};
    double convexY[50000] = {0.0};
    int cc = 0; //convex counter
    int l = 0;
    int check = 0;

    int i, j, k;
    i = 0;
    j = 0;
    k = 0;

    double a, b, c;
    int convexSet = 0;

    int sign = 0; // 1: positive, 2: negative for expression ax + by - c, 3: signs changed, line is not a boundary then

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            a = Y[j] - Y[i];
            b = X[i] - X[j];
            c = (X[i]*Y[j]) - (Y[i]*X[j]);

            if (X[i] == X[j] && Y[i] == Y[j])
            {
                continue;
            }

            if (a == 0)
            {
                continue;
            }

            for (k = 0; k < n; k++)
            {
                if ((X[k] == X[i] && Y[k] == Y[i]) || (X[k] == X[j] && Y[k] == Y[j]))
                {
                    continue;
                }


                if (sign == 3)
                {
                    break;
                }

                if ((a*X[k]) + (b*Y[k]) - c == 0) //ax+by-c
                {
                }
                else if ((a*X[k]) + (b*Y[k]) - c > 0)
                {
                    if (sign == 2)
                    {
                        sign = 3;
                    }
                    else
                    {
                        sign = 1;
                    }
                }
                else if ((a*X[k]) + (b*Y[k]) - c < 0)
                {
                    if (sign == 1)
                    {
                        sign = 3;
                    }
                    else
                    {
                        sign = 2;
                    }
                }
            }

            if (sign == 1 || sign == 2)
            {
               for (l = 0; l < n; l++)
                {
                    if (convexX[l] == X[i] && convexY[l] == Y[i])
                    {
                        check = 1;
                    }

                }

                if (check == 0)
                {
                    convexX[cc] = X[i];
                    convexY[cc] = Y[i];
                    cc++;
                    convexSet++;
                }
                check = 0;

                for (l = 0; l < n; l++)
                {
                    if (convexX[l] == X[j] && convexY[l] == Y[j])
                    {
                        check = 1;
                    }
                }

                if (check == 0)
                {
                    convexX[cc] = X[j];
                    convexY[cc] = Y[j];
                    cc++;
                    convexSet++;
                }
                check = 0;
            }
            sign = 0;
        }
    }

    int d, e;
    double comparison;
    double counter = 0;
    double subtraction = 0.0;

    for (d = 0; d < convexSet; d++)
    {
        comparison = convexX[d];
        for (e = 0; e < convexSet; e++)
        {
            if (comparison == convexX[e])
            {
                counter++;
            }
        }

        if (counter > 2)
        {
            subtraction = subtraction + (counter-2)/counter;
        }
        counter = 0;
    }
    convexSet = convexSet - subtraction;


for (int u = 0; u < convexSet; u++)
{
    printf("%lf %lf\n", convexX[u], convexY[u]);
}

/*
    for (int w = 0; w < convexSet-2; w++)
    {
        if (convexX[w] == convexX[w+1] && convexX[w+1] == convexX[w+2])
        {
            convexX
        }
    }
*/
    return convexSet;
}
