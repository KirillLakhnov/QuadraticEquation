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

/** \brief CompareNumbers - the function comparing two numbers of the double type.
 *
 * This function receives two double numbers as input and outputs the result of their comparison.
 * \param[in] x - compared number.
 * \param[in] y - compared number.
 * \return result comparison (EQUALLY, MORE, LESS).
 */
int CompareNumbers (const double x, const double y);

/**
 * \brief CompareNumbersPlus - 
 * 
 * \param[in] x 
 * \param[in] y 
 * \param[in] epsilon 
 * \return int 
 */
int CompareNumbersAccuracy (const double x, const double y, const double epsilon);

//===================================================================================================

/** \brief ClearInput - the function that clears the memory buffer in case of incorrectly entered coefficients.
 */
void ClearInput ();

/**
 * \brief 
 * 
 * \param a 
 * \return int 
 */
int isfinite (const double a);

/**
 * \brief 
 * 
 * \param a 
 * \return int 
 */
int Isnan (const double a);

#endif // COMMON_H
