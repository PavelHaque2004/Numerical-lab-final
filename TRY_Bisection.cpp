#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;



double f(double x)
{
    return x * x - 2;
}


int main()
{
    double a,b,c;
    double fa,fb,fc,tol;
    double root;
int itr=1;

    cout<<"\nEnter input value a : ";
    cin>>a;

    cout<<"\nEnter input value b: ";
    cin>>b;

    cout<<"Enter tol :";
    cin>>tol;

    fa=f(a);
    fb=f(b);


    if(fa*fb>0)
    {
        cout<<"\na b do not bracket root\n";
       return 0;
    }

    cout<<"\n";

    cout<<left
    <<setw(15)<<"Iteration"
    <<setw(15)<<"a"
    <<setw(15)<<"b"
    <<setw(15)<<"fa"
    <<setw(15)<<"fb"
    <<setw(15)<<"c"
    <<setw(15)<<"fc"<<endl;



    cout<<"------------------------------------------------------------------------------------------------------------\n";



    while(true)
    {
        // c=(a+b)/2.0;
        // fc = f(c);


        c=((a*fb)-(b*fa))/(fb-fa);
        fc=f(c);





        
    cout<<left
    <<setw(15)<<itr
    <<setw(15)<<a
    <<setw(15)<<b
    <<setw(15)<<fa
    <<setw(15)<<fb
    <<setw(15)<<c
    <<setw(15)<<fc<<endl;


        if(fc==0)
        {
            
            root=c;
            
            break;
        }


if(fa*fc>0)
{
    a=c;
    fa=fc;
}

else{
    b=c;
    fb=fc;
}




if(fabs((b-a))<tol)
{
root=(a+b)/2;
break;
}
itr++;







    }


cout<<"Approx root :"<<fixed<<setprecision(6)<<root<<endl;
return 0;

}