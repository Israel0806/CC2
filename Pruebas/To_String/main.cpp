#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//const int dias_b[]= {31,29,31,30,31,30,31,31,30,31,30,31};
int dias[]= {31,28,31,30,31,30,31,31,30,31,30,31};

unsigned long long segundos;
long int minutos, horas;

string itos(int x)
{

    stringstream ss;
    ss << x;
    string str;
    ss >> str;
    return str;
}

int FechaJuliana(int anho, int mes, int dia)
{
    int I;
    int J;
    int K;
    I = anho;
    J = mes;
    K = dia;
    int s=K -   32075 + 1461 *(I    + 4800 +(J   - 14)/ 12)/ 4 + 367 * (J   - 2 -(J   - 14)/ 12 *12) / 2/ 12 - 3 * ((I    + 4900 +(J  -14)/12)/100)/4;
    return s;
}


int main (){
    int dia1, dia2, mes1, mes2, anho1,anho2;
    cout<<"FECHA INICIAL: \n";
    cout<<"-Anho: "; cin >> anho1;
    cout<<"-Mes: "; cin >> mes1;

    while(mes1<1 or mes1>12)
    {
        cout<<"Ingrese el mes correcto\n";
        cin>>mes1;
    }
    cout<<"-Dia: "; cin >> dia1;
    while( (dia1<1 or dia1>31) or ((mes1==4 or mes1==6 or mes1==9 or mes1==11) and (dia1<1 or dia1>31)) or (mes1==2 and(dia1<1 or dia1>28)))
    {
        cout<<"Ingrese el dia correcto\n";
        cin>>dia1;
    }
    cout<<"\nFECHA FINAL: \n";

    cout<<"-Anho: "; cin >> anho2;
    cout<<"-Mes: "; cin >> mes2;
    while(mes2<1 or mes2>12)
    {
        cout<<"Ingrese el mes correcto\n";
        cin>>mes2;
    }
    cout<<"-Dia: "; cin >> dia2;
    while( (dia2<1 or dia2>31) or ((mes2==4 or mes2==6 or mes2==9 or mes2==11) and (dia2<1 or dia2>31)) or (mes2==2 and(dia2<1 or dia2>28)))
    {
        cout<<"Ingrese el dia correcto\n";
        cin>>dia2;
    }
    int julianDate= FechaJuliana(anho1, mes1, dia1);
    int julianDate2= FechaJuliana(anho2, mes2, dia2);

    cout<<"El dia: "<<julianDate<<endl;
    cout<<"\n\n\n : "<<julianDate2<<endl;
    cout<<"resultado: "<<julianDate2-julianDate+1<<endl;
    cout<<"\nSegundos transcurridos: "<< segundos << endl;
    cout<<"\nMinutos transcurridos " << minutos << endl;
    cout<<"\nHoras transcurridas: " << horas << endl;

    return 0;
}

    /*string anhoJ= itos(anho1);
    if(anho1 % 4 == 0)
          dias[1] = 29;
         //Start building Julian date
         string julianDate;
         //last two digit of year: 2012 ==> 12
         julianDate += anhoJ.substr(0,4);

         int julianDays = 0;
         for (int i=0; i < mes1-1; i++)
         {
          julianDays += dias[i];
         }
         julianDays += dia1;
         string julianDay= itos(julianDays);
             if(julianDay.length() < 2)
             {
              julianDate += "00";
             }
             if(julianDay.length() < 3)
             {
              julianDate += "0";
             }

        julianDate += julianDays;
        string resultJulian =  julianDate;

        M1 = (M-14)/12
   Y1 = Y + 4800 .

Then the Julian date J is

 J = 1461*(Y1+M1)/4 + 367*(M-2-12*M1)/12 - (3*((Y1+M1+100)/100))/4
     + D - 32075  .
*/
