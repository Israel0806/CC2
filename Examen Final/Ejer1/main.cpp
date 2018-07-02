#include <iostream>

using namespace std;

int suma(int a, int b)
{
    return a+b;
}
int resta(int a, int b)
{
    return a-b;
}
int mult(int a, int b)
{
    return a*b;
}

int funct(int (*p)(int,int), int a, int b,int mod)
{
    int n=p(a,b);
    n=n%mod;
    if(n<0)
    {
        n=mod+n;
    }
    return n;
}

int main()
{
    cout<<funct(suma,2,4,6)<<endl;
    cout<<funct(resta,2,3,5)<<endl;
    cout<<funct(mult,2,2,3)<<endl;
    return 0;
}
