#include "QuadraticEquation.h"

void InputCoefficients (double* a, double* b, double* c)
{
    assert (a);
    assert (b);
    assert (c);

    printf ("Enter the coefficients of the quadrant equation:  ");
    while (scanf ("%lg %lg %lg", a, b, c) != 3)
    {
        ClearInput ();
        printf ("The data is entered incorrectly. Enter other data:  ");
    }
}

int SolveQuadrant (const double a, const double b, const double c, double* x1, double* x2)
{
    isfinite (a);
    isfinite (b);
    isfinite (c);

    assert (x1);
    assert (x2);

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

int SolveLinear (const double b, const double c, double* x1)
{
    isfinite (b);
    isfinite (c);
    
    assert (x1);

    if (CompareNumbers (b, 0) == EQUALLY)
    {
        return (CompareNumbers (c, 0) == EQUALLY) ? INF_SOLUTION : ZERO_SOLUTION;
    }
    else
    {
        *x1 = (CompareNumbers (c, 0) == EQUALLY) ? 0 : (- c / b);
        return ONE_SOLUTION;
    }
}

void OutputRoots (const int NumberSolutions, const double* x1, const double* x2)
{
    assert (x1);
    assert (x2);

    switch (NumberSolutions)
    {
        case ZERO_SOLUTION: printf ("There are no solutions\n");                                               break;
        case  ONE_SOLUTION: printf ("The root of the quadratic equation is x = %lg\n", *x1);                   break;
        case  TWO_SOLUTION: printf ("The roots of the quadratic equation are x1 = %lg, x2 = %lg\n", *x1, *x2); break;
        case  INF_SOLUTION: printf ("There are an infinite number of solutions\n");                            break;
        default:            assert (0 && "Wrong number of solutions\n");                                       break;
    }
}
