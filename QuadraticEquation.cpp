#include "QuadraticEquation.h"

int SolveLinear (double b, double c, double* x1)
{
    if (CompareNumbers (b, 0) == EQUALLY)
    {
        return (CompareNumbers (c, 0) == EQUALLY) ? INF_SOLUTION : ZERO_SOLUTION;
    }
    else
    {
        (CompareNumbers (c, 0) == EQUALLY) ? (*x1 = 0) : (*x1 = - c / b);
        return ONE_SOLUTION;
    }
}

int SolveQuadrant (double a, double b, double c, double* x1, double* x2)
{
    if (CompareNumbers (a, 0) == EQUALLY)
    {
        return SolveLinear (b, c, x1);
    }
    else
    {
        if (CompareNumbers (c, 0) == EQUALLY)
        {
            if (CompareNumbers (b, 0) != EQUALLY)
            {
                *x1 = 0;
                *x2 = - b / a;
                return TWO_SOLUTION;
            }
            else
            {
                *x1 = 0;
                return ONE_SOLUTION;
            }
        }
        else
        {
            double D = b * b - 4 * a * c;
            
            if (CompareNumbers (D, 0) == MORE)
            {
                D = sqrt(D); // D is the root of the discriminant
                *x1 = ( -b - D ) / ( 2 * a );
                *x2 = ( -b + D ) / ( 2 * a );
                return TWO_SOLUTION;
            }
            else if (CompareNumbers (D, 0) == LESS)
            {
                return ZERO_SOLUTION;
            }
            else
            {
                *x1 = -b / ( 2 * a ) ;
                return ONE_SOLUTION;
            }
        }
    }
}

void InputCoefficients (double* a, double* b, double* c)
{
    printf ("Enter the coefficients of the quadrant equation:  ");
    while (scanf ("%lg %lg %lg", a, b, c) != 3)
    {
        ClearInput ();
        printf ("The data is entered incorrectly. Enter other data:  ");
    }
}


void OutputRoots (int NumberSolutions, double* x1, double* x2)
{
    switch (NumberSolutions)
    {
        case ZERO_SOLUTION: printf ("There are no solutions\n");                                               break;
        case  ONE_SOLUTION: printf ("The root of the quadratic equation is x = %lg\n", *x1);                   break;
        case  TWO_SOLUTION: printf ("The roots of the quadratic equation are x1 = %lg, x2 = %lg\n", *x1, *x2); break;
        case  INF_SOLUTION: printf ("There are an infinite number of solutions\n");                            break;
        default:            assert (0 && "Wrong number of solutions\n");                                       break;
    }
}


void Tests ()
{
    double TestsArr[8][6]= { {0, 0,  0,  INF_SOLUTION,  NAN, NAN },
                             {0, 0,  5,  ZERO_SOLUTION, NAN, NAN },
                             {0, 6,  0,  ONE_SOLUTION,  0,   NAN },
                             {0, 2,  8,  ONE_SOLUTION,  -4,  NAN },
                             {5, 0,  0,  ONE_SOLUTION,  0,   NAN },
                             {1, -3, 0,  TWO_SOLUTION,  0,   3   },
                             {1, -4, 4,  ONE_SOLUTION,  2,   NAN },
                             {1, 0,  2,  ZERO_SOLUTION, NAN, NAN },
                           };
    
    for (int i=0; i<8; i++)
    {
        double a = TestsArr[i][0];
        double b = TestsArr[i][1];
        double c = TestsArr[i][2];
        double x1tests = TestsArr[i][4];
        double x2tests = TestsArr[i][5];
        int NumberSolutionsTests = (int) TestsArr[i][3];
        
        double x1 = NAN, x2 = NAN;
        int NumberSolutions = SolveQuadrant (a, b, c, &x1, &x2);
        
        if ((NumberSolutions == NumberSolutionsTests) && ((x1 != x1 && x1tests != x1tests) || x1 == x1tests) && ((x2 != x1 && x2tests != x2tests) || x2 == x2tests))
        {
        printf ("Test %d passed successfully\n\n", i);
                 
        }
        else
        {
            printf ("Test %d failed\n", i);
            printf ("Test data: a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, the number of solutions is equal to %d\n", a, b, c, x1tests, x2tests, NumberSolutionsTests);
            printf ("Program result: x1 = %lg, x2 = %lg, the number of solutions is equal to %d\n\n", x1, x2, NumberSolutions);
        }
    }
}