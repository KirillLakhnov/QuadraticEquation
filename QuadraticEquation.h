#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "common.h"

/**
 * \brief  Solutions - the result of the function of solving the quadratic equation.
 */
enum Solutions
{
    ZERO_SOLUTION = 0,  
    ONE_SOLUTION  = 1,  
    TWO_SOLUTION  = 2,  
    INF_SOLUTION  = 3,  
};

//===================================================================================================

/** \brief InputCoefficients - responsible for entering coefficient values by the user.
 *
 * This function receives three pointers to variables of type double as input.
 * \param[in] a - pointer to variables that are coefficients of a quadratic equation.
 * \param[in] b - pointer to variables that are coefficients of a quadratic equation.
 * \param[in] c - pointer to variables that are coefficients of a quadratic equation.
 */
void InputCoefficients (double* a, double* b, double* c);

//===================================================================================================

/** \brief SolveQuadrant - solves quadratic equations.
 *
 * This function accepts three double numbers and two pointers to double variables as input&
 * \param[in] a - coefficient of the quadratic equation.
 * \param[in] b - coefficient of the quadratic equation.
 * \param[in] c - coefficient of the quadratic equation.
 * \param[out] x1 - the pointer to a double variable to which the root of a quadratic equation is passed.
 * \param[out] x2 - the pointer to a double variable to which the root of a quadratic equation is passed.
 * \return number of solutions.
 */
int SolveQuadrant (const double a, const double b, const double c, double* x1, double* x2);

/** \brief SolveLinear - solves linear equations
 *
 * This function receives two double numbers and one pointer to a double variable as input.
 * \param[in] b - сoefficient of the linear equation.
 * \param[in] c - сoefficient of the linear equation.
 * \param[out] x1 - the pointer to a double variable to which the root of a linear equation is passed.
 * \return number of solutions.
 */
int SolveLinear (const double b, const double c, double* x1);

//===================================================================================================

/** \brief OutputRoots - outputs the roots of a quadratic equation.
 *
 * This function takes one int number and two pointers to variables of the double type as input.
 * \param[in] NumberSolutions - number of solutions of the quadratic equation.
 * \param[in] x1 - pointer to variables that are the roots of the equation.
 * \param[in] x2 - pointer to variables that are the roots of the equation.
 */
void OutputRoots (const int NumberSolutions, const double* x1, const double* x2);

#endif // QUADRATIC_EQUATION_H
