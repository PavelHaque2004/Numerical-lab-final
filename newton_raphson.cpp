#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double func(double x)
{
    return x * x * x - x * x - 2;
}

double dfunc(double x)
{
    return 3 * x * x - 2 * x;
}

int main()
{
    double a, b, eps;
    double fa, dfa;
    int itr = 1;

    cout << "Enter initial guess: ";
    cin >> a;

    cout << "Enter error tolerance: ";
    cin >> eps;

    cout << fixed << setprecision(6);

    cout << left
         << setw(12) << "Iteration"
         << setw(15) << "a"
         << setw(15) << "f(a)"
         << setw(15) << "f'(a)"
         << setw(15) << "b"
         << endl;

    cout << "------------------------------------------------------------"
         << endl;

    while (true)
    {
        fa = func(a);
        dfa = dfunc(a);

        if(dfa == 0)
        {
            cout << "Derivative is zero. Method failed." << endl;
            return 0;
        }

        b = a - fa / dfa;

        cout << left
             << setw(12) << itr
             << setw(15) << a
             << setw(15) << fa
             << setw(15) << dfa
             << setw(15) << b
             << endl;

        if(fabs(b - a) < eps)
            break;

        a = b;
        itr++;
    }

    cout << "\nRoot = " << b << endl;

    return 0;
}






































































































#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to calculate f(x)
double func(double x, double a[], int n)
{
    double result = 0;

    for(int i = n; i >= 0; i--)
    {
        result = result + a[i] * pow(x, i);
    }

    return result;
}

// Function to calculate f'(x)
double dfunc(double x, double a[], int n)
{
    double result = 0;

    for(int i = n; i >= 1; i--)
    {
        result = result + i * a[i] * pow(x, i - 1);
    }

    return result;
}

int main()
{
    int n, i;
    double a[100];
    double x0, x1;
    double fx, dfx;
    double error;
    double E;

    // Input total power
    cout << "ENTER THE TOTAL NO. OF POWER:::: ";
    cin >> n;

    // Input coefficients
    for(i = 0; i <= n; i++)
    {
        cout << "x^" << i << "::-";
        cin >> a[i];
    }

    // Display polynomial
    cout << "\nTHE POLYNOMIAL IS ::: ";

    for(i = n; i >= 0; i--)
    {
        if(a[i] >= 0 && i != n)
            cout << "+";

        cout << a[i] << "x^" << i << " ";
    }

    // Initial guess
    cout << "\n\nINTIAL X1---->";
    cin >> x0;

    // Error tolerance
    cout << "\nENTER ERROR TOLERANCE---->";
    cin >> E;

    cout << "\n**************************************\n";
    cout << "ITERATION\tX1\tFX1\tF'X1\n";
    cout << "**************************************\n";

    for(i = 1; i <= 100; i++)
    {
        // Calculate f(x0)
        fx = func(x0, a, n);

        // Calculate f'(x0)
        dfx = dfunc(x0, a, n);

        // Check derivative
        if(dfx == 0)
        {
            cout << "\nDerivative is zero. Method failed." << endl;
            return 0;
        }

        // Newton-Raphson formula
        x1 = x0 - (fx / dfx);

        cout << fixed << setprecision(3);

        cout << i << "\t\t"
             << x1 << "\t"
             << fx << "\t"
             << dfx << endl;

        // Relative error
        error = fabs((x1 - x0) / x1);

        // Check accuracy
        if(error < E)
        {
            break;
        }

        // Update x0
        x0 = x1;
    }

    cout << "**************************************\n";

    cout << fixed << setprecision(6);
    cout << "THE ROOT OF EQUATION IS " << x1 << endl;

    return 0;
}