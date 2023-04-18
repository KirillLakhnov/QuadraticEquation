//#define DEBUG

#include "QuadraticEquation.h"

#ifdef DEBUG
    #include "tests.h"
#endif

int main (int argc, const char* argv[])
{  
#ifdef DEBUG
    Tests ();
#else
    double a = NAN, b = NAN, c = NAN;
    
    InputCoefficients (&a, &b, &c);
    
    double x1 = NAN, x2 = NAN;
    int NumberSolutions = SolveQuadrant (a, b, c, &x1, &x2);
    
    OutputRoots (NumberSolutions, &x1, &x2);
#endif

    return 0;
}
