#include<iostream>
using namespace std;
int main()
{
    int n,i,j;
    float x[100],y[100],xp;
    cout<<"Enter number of data point :";
    cin>>n;

    cout<<"Enter x and y value :\n";
    for(i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }

    cout<<"\nEnter xp value :";
    cin>>xp;

    float result=0,term;


    for(i=0;i<n;i++)
    { term=y[i];
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
term=(term*(xp-x[j]))/(x[i]-x[j]);
            }

        }
        result+=term;
    }
cout<<"Y value :"<<result;
return 0;
}