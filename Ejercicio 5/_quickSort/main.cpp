#include <iostream>
using namespace std;


void corte(){


}

void _quickSort(){

    cout<<"Los valores ordenados son: "<<"\n";
    for(int j=0; j<tam; j++)
    {
        int i=j;
        while( i>0 )
        {
            if(a[i-1]>a[i])
            {
                int temp=a[i-1];
                a[i-1]=a[i];
                a[i]=temp;
            }
        }
    }


}
int main(){

    int t=5;
    int a[t];

    cout<<"Ingrese 5 valores a ordenar: "<<endl;

    for(int i=0; i<t; i++)
        cin>>a[i];

}
