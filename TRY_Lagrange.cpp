#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    double n,x[100],y[100],xp,result=0,term;
    int i,j;

    cout<<"Enter data point ";
    cin>>n;
for(i=0;i<n;i++)
{
 cout<<"\nEnter input :";
    cin>>x[i]>>y[i];

}

cout<<"enter xp : ";
cin>>xp;

for(i=0;i<n;i++)
{
    term=y[i];
    for(j=0;j<n;j++)
    {
        if(i!=j)
        {
            term=term*(xp-x[j])/(x[i]-x[j]);
        }
    }
    result+=term;
}


cout<<"Root :"<<result;
   
}