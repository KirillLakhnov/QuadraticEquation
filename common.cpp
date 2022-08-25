#include "common.h"

int CompareNumbers (double x, double y)
{
    const double epsilon = 1E-6;
    if (fabs (x-y) <= epsilon)
    {
        return EQUALLY;
    }
    else
    {
        return ((x-y) > epsilon) ? MORE : LESS;
    }
}

void ClearInput ()
{
    while (getchar () != '\n');
}