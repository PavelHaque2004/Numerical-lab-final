#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n, i, j;
    float x[100], y[100], table[100][100];
    float xp, result, term;

    cout << "Enter number of data points: ";
    cin >> n;

    cout << "Enter x and y values:\n";

    for(i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        table[i][0] = y[i];
    }

    for(j = 1; j < n; j++)
    {
        for(i = 0; i < n - j; i++)
        {
            table[i][j] =
            (table[i + 1][j - 1] - table[i][j - 1])
            / (x[i + j] - x[i]);
        }
    }

    cout << "\nDivided Difference Table:\n\n";

    cout << left
         << setw(10) << "x"
         << setw(12) << "f(x)";

    for(j = 1; j < n; j++)
    {
        cout << setw(15) << "DD" + to_string(j);
    }

    cout << endl;

    cout << "------------------------------------------------------------\n";

    for(i = 0; i < n; i++)
    {
        cout << fixed << setprecision(6);

        cout << left
             << setw(10) << x[i]
             << setw(12) << table[i][0];

        for(j = 1; j < n - i; j++)
        {
            cout << setw(15) << table[i][j];
        }

        cout << endl;
    }

    cout << "\nEnter the value of x: ";
    cin >> xp;

    result = table[0][0];
    term = 1;

    for(i = 1; i < n; i++)
    {
        term = term * (xp - x[i - 1]);
        result = result + table[0][i] * term;
    }

    cout << "\nInterpolated value of y = "
         << fixed << setprecision(6)
         << result << endl;

    return 0;
}