//  #include<iostream>
// using namespace std;

// int main()
// {
//     int n, i, j;
//     float x[100], y[100], table[100][100];
//     float xp, result, term;

//     cout << "Enter number of data points: ";
//     cin >> n;

//     cout << "Enter x and y values:\n";

//     for(i = 0; i < n; i++)
//     {
//         cin >> x[i] >> y[i];
//         table[i][0] = y[i];
//     }

   
//     for(j = 1; j < n; j++)
//     {
//         for(i = 0; i < n - j; i++)
//         {
//            table[i][j] =
            // (table[i + 1][j - 1] - table[i][j - 1])
            // / (x[i + j] - x[i]);
//         }
//     }

//     cout << "Enter the value of x: ";
//     cin >> xp;

    
//     result = table[0][0];
//     term = 1;

//     for(i = 1; i < n; i++)
//     {
//         term = term * (xp - x[i - 1]);
//         result = result + table[0][i] * term;
//     }

//     cout << "Interpolated value of y = " << result << endl;

//     return 0;
// }

#include<iostream>
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

    cout << "Enter the value of x: ";
    cin >> xp;

    
    result = table[0][0];
    term = 1;

    for(i = 1; i < n; i++)
    {
        term = term * (xp - x[i - 1]);
        result = result + table[0][i] * term;
    }

    cout << "Interpolated value of y = " << result << endl;

    return 0;
}