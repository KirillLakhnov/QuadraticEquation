#ifndef TESTS_H
#define TESTS_H

#include <stdio.h>
#include <math.h>
#include "QuadraticEquation.h"

/**
 * \brief TestsUnit - receiving the data necessary for testing the function solving quadratic equations.
 */ struct TestsUnit
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

#endif // TESTS_H
