#include <iostream>

using namespace std;

class mult {
    int a;
public:
    mult(int x) :a(x) {}
    int operator() (int b)
    {
        return a*b;
    }
};

template <class T>
int funct(T op, int A, int B)
{
    for(int i=A;i<=B;i++)
    {
        cout<<op(i)<<endl;
    }
}


int main()
{
    funct(mult(4),1,10);

    return 0;
}
