#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>

/**
 * \brief ComparisonRezult - result of the comparison function.
 */
enum ComparisonRezult
{
    EQUALLY     =  0,    
    MORE        =  1,    
    LESS        =  2,    
};

//===================================================================================================

/**
 * \brief CompareNumbersPlus - compares two numbers depending on the accuracy.
 * 
 * \param[in] x - compared number.
 * \param[in] y - compared number.
 * \param[in] epsilon - accuracy of comparison.
 * \return  result comparison (EQUALLY, MORE, LESS).
 */
int CompareNumbersAccuracy (const double x, const double y, const double epsilon);

/** \brief CompareNumbers - сomparing two numbers of the double type.
 *
 * This function receives two double numbers as input and outputs the result of their comparison.
 * \param[in] x - compared number.
 * \param[in] y - compared number.
 * \return result comparison (EQUALLY, MORE, LESS).
 */
int CompareNumbers (const double x, const double y);

//===================================================================================================

/** \brief ClearInput - the function that clears the memory buffer in case of incorrectly entered coefficients.
 */
void ClearInput ();

/**
 * \brief isfinite - checks a number for values such as NAN and infinity.
 * 
 * \param a - the number being checked.
 * \return True or False (1 or 0)
 */
int isfinite (const double a);

/**
 * \brief Isnan - checks the number for the NAN value
 * 
 * \param a - the number being checked.
 * \return True or False (1 or 0)
 */
int Isnan (const double a);

#endif // COMMON_H
