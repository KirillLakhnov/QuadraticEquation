#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>

enum ComparisonRezult
{
    EQUALLY = 0,    /**< Enum value EQUALLY 0 */
    MORE    = 1,    /**< Enum value MORE    1 */
    LESS    = 2,    /**< Enum value LESS    2 */
};

/** \brief CompareNumbers - the function comparing two numbers of the double type.
 *
 * This function receives two double numbers as input and outputs the result of their comparison.
 * \param[in] x - compared number.
 * \param[in] y - compared number.
 * \return result comparison (equal , more , less).
 */
int CompareNumbers (double x, double y);

/** \brief ClearInput - the function that clears the memory buffer in case of incorrectly entered coefficients.
 */
void ClearInput ();

#endif // COMMON_H
