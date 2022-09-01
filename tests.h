#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <math.h>
#include "QuadraticEquation.h"

/**
 * \brief TestsUnit - receiving the data necessary for testing the function solving quadratic equations.
 */ 
struct TestsUnit
{
    double a;
    double b;
    double c;
    int NumberSolutionsTest;
    double x1;
    double x2;
};

/** \brief Tests - checks the operability of a function that solves quadratic equations.
 */
void Tests ();

/**
 * @brief FunctionTestsBody - the function that performs a single test of a function that solves square equations.
 * 
 * @param QuadraticTests - structure containing data for tests.
 */
void FunctionTestsBody (struct TestsUnit QuadraticTests, int i, const double accuracy); 

#endif // TESTS_H
