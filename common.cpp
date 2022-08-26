#include "common.h"

int CompareNumbersAccuracy (const double x, const double y, const double epsilon)
{
    isfinite (x);
    isfinite (y);
    isfinite (epsilon);
    
    if (fabs (x-y) <= epsilon)
    {
        return EQUALLY;
    }
    else
    {
        return ((x-y) > epsilon) ? MORE : LESS;
    }
}

int CompareNumbers (const double x, const double y)
{
    isfinite (x);
    isfinite (y);

    const double epsilon = 1E-6;
    return CompareNumbersAccuracy (x, y, epsilon);
}

void ClearInput ()
{
    while (getchar () != '\n');
}

int isfinite (const double a)
{
    return !isnan(a) && (2 * a + 1 != a);
}

int Isnan (const double a)
{
    return a != a;
}
