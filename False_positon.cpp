#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define E 0.001

double f(double x)
{
    return x - cos(x);
}

int main()
{
    double a, b, c;
    double fa, fb, fc;
    double root;
    int iteration = 1;

    
    cout << "Enter the value of a: ";
    cin >> a;

    cout << "Enter the value of b: ";
    cin >> b;

    
    fa = f(a);
    fb = f(b);

    
    if (fa * fb > 0)
    {
        cout << "a and b do not bracket any root." << endl;
        return 0;
    }

    cout << "\n";
    cout << "--------------------------------------------------------------------------------\n";

    cout << left
         << setw(10) << "Iteration"
         << setw(12) << "a"
         << setw(12) << "b"
         << setw(12) << "c"
         << setw(12) << "fa"
         << setw(12) << "fb"
         << setw(12) << "fc" << endl;

    cout << "--------------------------------------------------------------------------------\n";

    while (true)
    {
        
        c = (a * fb - b * fa) / (fb - fa);

        fc = f(c);

        cout << fixed << setprecision(6)
             << left
             << setw(10) << iteration
             << setw(12) << a
             << setw(12) << b
             << setw(12) << c
             << setw(12) << fa
             << setw(12) << fb
             << setw(12) << fc << endl;

        
        if (fc == 0)
        {
            root = c;
            break;
        }

        
        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }

        
        if (fabs((b - a) / b) < E)
        {
            root = (a + b) / 2;
            break;
        }

        iteration++;
    }

    cout << "--------------------------------------------------------------------------------\n";

    cout << "Approximate root = "
         << fixed << setprecision(6) << root << endl;

    return 0;
}