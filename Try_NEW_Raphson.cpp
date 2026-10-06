#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x)
{
    return x * x * x - x * x - 2;
}


double df(double x)
{
    return 3 * x * x - 2 * x;
}



int main()
{
    double a,b,fa,dfa,tol;
    int itr=1;

    cout<<"Enter initial guess :";
    cin>>a;
    cout<<"\n enter tol :";
    cin>>tol;

    cout<<fixed<< setprecision(6);

    cout<<left
    <<setw(15)<<"Iteration"
    <<setw(15)<<"a"
    <<setw(15)<<"fa"
    <<setw(15)<<"dfa"
    <<setw(15)<<"b"<<endl;


    cout<<"\n-----------------------------------------------------------------------------------------------------"<<endl;


while(true)
{
fa=f(a);
    dfa=df(a);

    if(dfa==0)
    {
        cout<<"Derivative is 0";
        return 0;
    }


    b=a-(fa/dfa);

    cout<<left
    <<setw(15)<<itr
    <<setw(15)<<a
    <<setw(15)<<fa
    <<setw(15)<<dfa
    <<setw(15)<<b<<endl;


    if(fabs(b-a)<tol)
    {
        break;
    }
    a=b;
    itr++;

}


    cout<<"Root :"<<b<<endl;
    return 0;

}