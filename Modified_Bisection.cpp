#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;



double f(double x)
{
    return x * x * x - 2 * x * x - x + 2;
}



void modifiedBisection(double a, double b, int n)
{
    double xr, fa, fb, fxr;

    cout << left
         << setw(10) << "i"
         << setw(15) << "a"
         << setw(15) << "b"
         << setw(15) << "xr"
         << setw(15) << "f(xr)"
         << endl;

    for(int i = 1; i <= n; i++)
    {
        fa = f(a);
        fb = f(b);

        
        xr = (a * fabs(fb) + b * fabs(fa))
             / (fabs(fa) + fabs(fb));

        fxr = f(xr);

        
        cout << left
             << setw(10) << i
             << setw(15) << fixed << setprecision(6) << a
             << setw(15) << b
             << setw(15) << xr
             << setw(15) << fxr
             << endl;

        
        if(fxr == 0)
        {
            break;
        }

        
        if(fa * fxr < 0)
        {
            b = xr;
        }
        else
        {
            a = xr;
        }
    }

    cout << "\nApproximate Root = "
         << fixed << setprecision(6) << xr
         << endl;
}


int main()
{
    
    cout << "Root 1: Initial Interval [-2, 0]\n";
    modifiedBisection(-2, 0, 15);

    cout << "\n-----------------------------------------------\n\n";


   
    cout << "Root 2: Initial Interval [0, 1.5]\n";
    modifiedBisection(0, 1.5, 15);

    cout << "\n-----------------------------------------------\n\n";


    cout << "Root 3: Initial Interval [1.5, 3]\n";
    modifiedBisection(1.5, 3, 15);

    return 0;
}