#include <iostream>

using namespace std;

int main()
{
    cout<<"LISTA DE NUMEROS PRIMOS MENORES A 1000: "<<endl;
    int listado=1;
    int p=1,d=1;
    int acum=0;
    while(p<1000){
        acum = 0;
        d=1;
        while(d <= p){
            if(p%d==0)
                acum++;
            d++;
        }
    if(acum==2)
        cout<< listado++ << ". " << p <<endl;
    p++;
    }

    return 0;
}
