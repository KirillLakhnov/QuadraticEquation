#include "tests.h"

void Tests ()
{
    const double accuracy = 0.01;
    struct TestsUnit QuadraticTests[] = { {0, 0,        0,          INF_SOLUTION,  NAN,   NAN    },
                                          {0, 0,        5,          ZERO_SOLUTION, NAN,   NAN    },
                                          {0, 6,        0,          ONE_SOLUTION,  0,     NAN    },
                                          {0, 2,        8,          ONE_SOLUTION,  -4,    NAN    },
                                          {5, 0,        0,          ONE_SOLUTION,  0,     NAN    },
                                          {1, -1.25,    0.375,      TWO_SOLUTION,  0.5,   0.75   },
                                          {1, -4,       4,          ONE_SOLUTION,  2,     NAN    },
                                          {1, 4,        1,          TWO_SOLUTION,  -3.73, -0.27  },
                                          {1, 0,        2,          ZERO_SOLUTION, NAN,   NAN    }};
    
    for (int i = 0; i < sizeof(QuadraticTests) / sizeof (QuadraticTests[0]) ; i++)
    {
        double x1 = NAN, x2 = NAN;
        int NumberSolutions = SolveQuadrant (QuadraticTests[i].a, QuadraticTests[i].b, QuadraticTests[i].c, &x1, &x2);

        if (NumberSolutions == QuadraticTests[i].NumberSolutionsTest)
        {
            if ((x1 != x1 && QuadraticTests[i].x1 != QuadraticTests[i].x1) || CompareNumbersAccuracy (x1, QuadraticTests[i].x1, accuracy) == EQUALLY)
            {
                if ((x2 != x2 && QuadraticTests[i].x2 != QuadraticTests[i].x2) || CompareNumbersAccuracy (x2, QuadraticTests[i].x2, accuracy) == EQUALLY)
                {
                    printf ("Test %d passed successfully.\n\n", i);
                }
                else
                {
                    printf ("Test %d failed.\nThe number of roots and the first root are the same, but in the case of the second, the program outputs the root %lg,"
                            "with the correct root %lg.\n\n", i, QuadraticTests[i].x2, x2);
                }
            }
            else 
            {
                if ((x2 != x2 && QuadraticTests[i].x2 != QuadraticTests[i].x2) || CompareNumbersAccuracy (x2, QuadraticTests[i].x2, accuracy) == EQUALLY)
                {
                    printf("Test %d failed.\nThe number of roots and the second root are the same, but in the case of the first one, the program outputs the root %lg,"
                           "with the correct root %lg.\n\n", i, QuadraticTests[i].x1, x1);
                }
                else
                {
                    printf("Test %d failed.\nThe number of roots is the same, but both roots are different from the correct ones. In the case of the first %lg, one is correct, and %lg are issued."
                           "In the case of the second %lg, one is correct, and %lg are issued.\n\n", i, QuadraticTests[i].x1, x1, QuadraticTests[i].x2, x2 );
                }
            }
        }
        else
        {
            printf("Test %d failed.\nThe program outputs the wrong number of roots.\n\n", i);
        }
    }
}
