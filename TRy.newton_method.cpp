#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define tol 0.0001
#define Max_iter 100

double f(double x)
{
    return x*x*x-6*x*x+11*x-6;
}


double df(double x)
{
    return 3*x*x-12*x+11;
}


int isdublicate(double root[],int count,double x)
{
    int i;
    for(i=0;i<count;i++)
    {
        if(fabs(root[i]-x)<tol)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
double x0,x1,error,root[100];
int count_root=0,i,iteration;

double initial_guess;

for(initial_guess=0.5;initial_guess<=3.5;initial_guess+=0.1)
{
    x0=initial_guess;
    iteration=0;

    while(iteration<Max_iter)
    {
        if(fabs(df(x0))<tol)
        {
            break;
        }

        x1=x0-(f(x0)/df(x0));

        error=((fabs(x1-x0))/x1)*100;
        if(error<tol)
        {
            if(!isdublicate(root,count_root,x1))
            {
                root[count_root]=x1;
                count_root++;
            }
            break;
        }
        x0=x1;
        iteration++;
    }
}


cout<<" \nall root \n";
for(i=0;i<count_root;i++)
{
    cout<<root[i]<<endl;
}
}