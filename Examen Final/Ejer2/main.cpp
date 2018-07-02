#include <iostream>

using namespace std;

class operacion
{
private:
	int temp;
public:
	operacion(int x):temp(x) {};

	int operator()(int var)
	{ return temp*var;}
};
template <typename T>
void operador(T op, int *b)
{
	*(b-1) = *b;
	*b = op(*b);
}

int main()
{
	int *a = new int[2];
	*a = 1;
	*(a+1) = 2;
	for(int i = 0; i<=5; i++)
	{
		cout<<*a<<endl;
		operador(operacion(*a),a+1);
	}
return 0;
}
