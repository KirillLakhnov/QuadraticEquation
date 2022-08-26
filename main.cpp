#include "QuadraticEquation.h"
#include "tests.h"

int main (int argc, const char* argv[])
{
    Tests ();
    
    double a = NAN, b = NAN, c = NAN;
    
    InputCoefficients (&a, &b, &c);
    
    double x1 = NAN, x2 = NAN;
    int NumberSolutions = SolveQuadrant (a, b, c, &x1, &x2);
    
    OutputRoots (NumberSolutions, &x1, &x2);
    
    return 0;
}
