#include <iostream>
#include <cmath>
using namespace std;

#define TOLERANCE 0.0001
#define MAX_ITER 100

double f(double x)
{
    return x * x * x - 6 * x * x + 11 * x - 6;
}

double df(double x)
{
    return 3 * x * x - 12 * x + 11;
}

int isDuplicate(double root[], int count, double x)
{
    int i;

    for(i = 0; i < count; i++)
    {
        if(fabs(root[i] - x) < 0.001)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    double roots[10];
    int rootCount = 0;

    double initialGuess;
    double x0, x1, error;

    int iteration;
    int i;

    cout << "Roots of f(x) = x^3 - 6x^2 + 11x - 6\n\n";

    for(initialGuess = 0.5; initialGuess <= 3.5; initialGuess += 0.1)
    {
        x0 = initialGuess;
        iteration = 0;

        while(iteration < MAX_ITER)
        {
            if(fabs(df(x0)) < 0.0000001)
                break;

            x1 = x0 - f(x0) / df(x0);

            error = fabs((x1 - x0) / x1) * 100;

            if(error < TOLERANCE)
            {
                if(!isDuplicate(roots, rootCount, x1))
                {
                    roots[rootCount] = x1;
                    rootCount++;
                }

                break;
            }

            x0 = x1;
            iteration++;
        }
    }

    cout << "\nAll distinct roots:\n";

    for(i = 0; i < rootCount; i++)
    {
        cout << "Root " << i + 1 << " = " << roots[i] << endl;
    }

    return 0;
}