#include <iostream>

using namespace std;

void insercion(int a[],int tam){
for (int i=0; i<tam; i++){
        int j,x;
		x=a[i];
		j=i;
		while (j>0 and a[j-1]>x){
			a[j]=a[j-1];
			j= j-1;
        }
		a[j]=x;
	}

	cout << "Los valores ordenados son: "<<endl;
	for(int i=0; i<tam; i++)
        cout<<a[i]<<"\t";

}
int main()
{
    int t=5;
    int a[t];

    cout<<"Ingrese 5 valores a ordenar: "<<endl;

    for(int i=0; i<t; i++)
    {
        cin>>a[i];
    }
    insercion(a,t);
}
