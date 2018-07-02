#include <iostream>

using namespace std;

class operacion
{
public:
    int operator()(int a,int b)
    {
        return a+b;
    }
};

template <class T>
class operador
{
private:
    T op;
public:
    void operator()(int *a)
    {
        int temp=*a;
        *a=*(a+1);
        *(a+1)=op(temp,*(a+1));
    }
};

int main()
{
	int *a = new int[2];
	*a = 0;
	*(a+1) = 1;

    operador<operacion> opt;


	for(int i= 0; i<=10; i++)
	{
		cout<<*a<<endl;
        opt(a);
	}
    return 0;
}
