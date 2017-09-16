#include <iostream>
using namespace std;

void cambio(int &v,int &b){
    int temp;
    temp=b;
    b=v;
    v=temp;
}

void seleccion(int a[], int tam){

	for( int i=0; i<tam-1;i++){
		int minimo;
		minimo=i;
		for (int j=i; j<tam; j++){
			if (a[j]<a[minimo])
				minimo=j;
		}
        if (minimo!=i){
            cambio(a[i],a[minimo]);
           /* int temp;
            temp=a[i];
            a[i]=a[minimo];
            a[minimo]=temp;
            */
        }
	}

	cout << "Los valores ordenados son: "<<endl;
	for(int i=0; i<tam; i++)
        cout<<a[i]<<"\t";

}

int main(){
    int t=5;
    int a[t];

    cout<<"Ingrese 5 valores a ordenar: "<<endl;

    for(int i=0; i<t; i++)
    {
        cin>>a[i];
    }

    seleccion(a,t);

    return 0;
}
