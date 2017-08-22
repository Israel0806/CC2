#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//const int dias_b[]= {31,29,31,30,31,30,31,31,30,31,30,31};
int dias[]= {31,28,31,30,31,30,31,31,30,31,30,31};

long long int segundos;
long long int minutos, horas;
float semanas,anhos;

int FechaJuliana(int Y, int M, int D)
{
	int M1 = (M-14)/12;
	int Y1 = Y + 4800;
	return (1461*(Y1+M1)/4 + 367*(M-2-12*M1)/12 - (3*((Y1+M1+100)/100))/4 + D - 32075);
}

int main (){
	int dia1, dia2, mes1, mes2, anho1,anho2;
	cout<<"FECHA INICIAL: \n";
	cout<<"-Anho: "; cin >> anho1;
	cout<<"-Mes: "; cin >> mes1;

	//Comprobar Mes
	while(mes1<1 or mes1>12)
	{
		cout<<"Ingrese el mes correcto\n";
		cin>>mes1;
	}
	cout<<"-Dia: "; cin >> dia1;
	//Comprobar Dia
	while( (dia1<1 or dia1>31) or ((mes1==4 or mes1==6 or mes1==9 or mes1==11) and (dia1<1 or dia1>31)) or (mes1==2 and(dia1<1 or dia1>28)))
	{
		cout<<"Ingrese el dia correcto\n";
		cin>>dia1;
	}
	cout<<"\nFECHA FINAL: \n";

	cout<<"-Anho: "; cin >> anho2;
	//Comprobar Mes
	cout<<"-Mes: "; cin >> mes2;
	while(mes2<1 or mes2>12)
	{
		cout<<"Ingrese el mes correcto\n";
		cin>>mes2;
	}
	cout<<"-Dia: "; cin >> dia2;
	//Comprobar Dia
	while( (dia2<1 or dia2>31) or ((mes2==4 or mes2==6 or mes2==9 or mes2==11) and (dia2<1 or dia2>31)) or (mes2==2 and(dia2<1 or dia2>28)))
	{
		cout<<"Ingrese el dia correcto\n";
		cin>>dia2;
	}

	int Inicio= FechaJuliana(anho1, mes1, dia1);
	int Fin= FechaJuliana(anho2, mes2, dia2);
	int Dias=Fin-Inicio+1;
	horas=24*Dias;
	minutos=horas*60;
	segundos=minutos*60;

    //Calcular semanas
	float temp=Dias;
	while(temp-7>0)
	{
		semanas++;
		temp-=7;
	}
	semanas+=temp/7;

    //Calcular años
	temp=Dias;
	while(temp-366>0)
	{
		anhos++;
		temp-=366;
	}
	anhos+=temp/365;
	semanas+=temp/7;

	temp=anhos;

    //Output
	cout<<"Numero de dias:    "       <<Dias      <<endl
		<<"Numero de semanas: "       <<semanas   <<endl
		<<"Numero de meses:   "                   <<endl
		<<"Numero de anhos:    "      <<anhos     <<endl<<endl
		<<"\nSegundos transcurridos: "<< segundos <<endl
		<<"\nMinutos transcurridos "  << minutos  <<endl
		<<"\nHoras transcurridas: "   << horas    <<endl;

	return 0;
}



// Julian conversion: https://www.hermetic.ch/cal_stud/jdn.htm
