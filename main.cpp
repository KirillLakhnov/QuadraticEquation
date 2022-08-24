#include <stdio.h>
#include <math.h>
#include <assert.h>

enum Solutions
{
    ZERO_SOLUTION = 0,  /**< Enum value ZERO_SOLUTION 0 */
    ONE_SOLUTION  = 1,  /**< Enum value ONE_SOLUTION  1 */
    TWO_SOLUTION  = 2,  /**< Enum value TWO_SOLUTION  2 */
    INF_SOLUTION  = 3,  /**< Enum value INF_SOLUTION  3 */
};

enum ComparisonRezult
{
    EQUALLY = 0,    /**< Enum value EQUALLY 0 */
    MORE    = 1,    /**< Enum value MORE    1 */
    LESS    = 2,    /**< Enum value LESS    2 */
};

/** \brief CompareNumbers - the function comparing two numbers of the double type.
  *
  * This function receives two double numbers as input and outputs the result of their comparison.
  * \param x - compared number.
  * \param y - compared number.
  * \return result comparison (equal , more , less).
  */
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

/** \brief SolveLinear - the function solving linear equations
  *
  * This function receives two double numbers and one pointer to a double variable as input.
  * \param b - сoefficient of the linear equation.
  * \param c - сoefficient of the linear equation.
  * \param x1 - the pointer to a double variable to which the root of a linear equation is passed.
  * \return number of solutions.
  */
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

/** \brief SolveQuadrant - the function that solves quadratic equations.
  *
  * This function accepts three double numbers and two pointers to double variables as input&
  * \param a - coefficient of the quadratic equation.
  * \param b - coefficient of the quadratic equation.
  * \param c - coefficient of the quadratic equation.
  * \param x1 - the pointer to a double variable to which the root of a quadratic equation is passed.
  * \param x2 - the pointer to a double variable to which the root of a quadratic equation is passed.
  * \return number of solutions.
  */
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

/** \brief ClearInput - the function that clears the memory buffer in case of incorrectly entered coefficients.
  */

void ClearInput ()
{
    while (getchar () != '\n');
}

/** \brief InputCoefficients - the function is responsible for entering coefficient values by the user.
  *
  * This function receives three pointers to variables of type double as input.
  * \param a - pointer to variables that are coefficients of a quadratic equation.
  * \param b - pointer to variables that are coefficients of a quadratic equation.
  * \param c - pointer to variables that are coefficients of a quadratic equation.
  */
void InputCoefficients (double* a, double* b, double* c)
{
    printf ("Enter the coefficients of the quadrant equation:  ");
    while (scanf ("%lg %lg %lg", a, b, c) != 3)
    {
        ClearInput ();
        printf ("The data is entered incorrectly. Enter other data:  ");
    }
}

/** \brief OutputRoots - the function that outputs the roots of a quadratic equation.
  *
  * This function takes one int number and two pointers to variables of the double type as input.
  * \param NumberSolutions - number of solutions of the quadratic equation.
  * \param x1 - pointer to variables that are the roots of the equation.
  * \param x2 - pointer to variables that are the roots of the equation.
  */
void OutputRoots (int NumberSolutions, double* x1, double* x2)
{
    switch (NumberSolutions)
    {
        case ZERO_SOLUTION: printf ("There are no solutions\n");                    break;
        case  ONE_SOLUTION: printf ("x = %lg\n", *x1);                              break;
        case  TWO_SOLUTION: printf ("x1 = %lg\nx2 = %lg\n", *x1, *x2);              break;
        case  INF_SOLUTION: printf ("There are an infinite number of solutions\n"); break;
        default:            assert (0 && "Wrong number of solutions\n");            break;
    }
}

void Test ()
{
    double TestsArr[8][6]= { {0, 0,  0,  INF_SOLUTION,  NAN, NAN },
                             {0, 0,  5,  ZERO_SOLUTION, NAN, NAN },
                             {0, 6,  0,  ONE_SOLUTION,  0,   NAN },
                             {0, 2,  8,  ONE_SOLUTION,  -4,  NAN },
                             {5, 0,  0,  ONE_SOLUTION,  0,   NAN },
                             {1, -3, 0,  TWO_SOLUTION,  1,   2   },
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
        
        if (x1 == NAN && x1tests == NAN)
        assert ((NumberSolutions == NumberSolutionsTests) && ((x1 == NAN && x1tests == NAN) || x1 == x1tests) && ((x2 == NAN && x2tests == NAN) || x2 == x2tests));
        
    }
}

int main (int argc, const char* argv[])
{
    Test ();
    
    double a = NAN, b = NAN, c = NAN;
    
    InputCoefficients (&a, &b, &c);
    
    double x1 = NAN, x2 = NAN;
    int NumberSolutions = SolveQuadrant (a, b, c, &x1, &x2);
    
    OutputRoots (NumberSolutions, &x1, &x2);
    
    return 0;
}
