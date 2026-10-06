#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x)
{
    return x * x - 4 * x - 10;
}

int main()
{
    double x1, x2, x3;
    double error;

    int itr = 1;

    cout << "Enter the value of x1: ";
    cin >> x1;

    cout << "Enter the value of x2: ";
    cin >> x2;

    cout << fixed << setprecision(6);

    cout << "______________________________________________________________________\n";
    cout << "Iteration\t x1\t\t x2\t\t x3\t\t f(x1)\t\t f(x2)\n";
    cout << "______________________________________________________________________\n";

    while(true)
    {
        
        x3 = x2 - (func(x2) * (x2 - x1))
                  / (func(x2) - func(x1));

        cout << itr << "\t\t"
             << x1 << "\t"
             << x2 << "\t"
             << x3 << "\t"
             << func(x1) << "\t"
             << func(x2) << endl;

       
        error = fabs(x3 - x2);

        if(error < 0.000001)
            break;

        
        x1 = x2;
        x2 = x3;

        itr++;
    }

    cout << "______________________________________________________________________\n";
    cout << "Approximate root = " << x3 << endl;

    return 0;
}