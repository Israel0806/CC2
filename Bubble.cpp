#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void bubble(int *p,int x)
{       
		//srand(time(NULL));
		int temp;
		bool val = true;
		for(int i=0;i<x;i++)
		{	
			val = false;		
			for(int j=0;j<x-1 and val == false ;j++){
				//cout<<"\n array"<<i<<" :: "<<array[i]<<"---- array"<< j <<" :: "<<array[j];
				if(*(p + j)> *(p + j+1))
				{
				temp = *(p + j);
				*(p + j) = *(p + j+1);
				*(p + j+1) = temp;
				val = false;
				}
				
		}
		}
		for(int i=0;i<x;i++)
		{
			cout<<"\n valores:"<<*(p + i);
		}
}

void introduce(int *p,int x)
{
	for(int i=0;i<x;i++)
	{
		cout<<"\n Ingrese el numero ::";
		cin>>p[i];
	}
}
void display(int *p,int x)
{	
	int n = 1;
	for(int i=0;i<x;i++)
	{
		cout<<endl<<n<<" .- "<<p[i];
		n++;
	}
}

void random(int *p,int x)
{
	srand(time(NULL));
	int num;
	for(int i=0;i<x;i++)
	{
		num = rand()%1000;
		cout<<"\n i ="<<num;
		*(p + i) = num;
	}
	
}



int main()
{
	int x;
	cout<<"Digite la cantidad de numeros de su array:";
	cin>>x;
	int Arr[x];
	int *point;
	point = Arr;
	//introduce(point,x);
	//display(point,x);
	//bubble(point,x);
	random(point,x);
	display(point, x);
	bubble(point,x);
	cout<<endl;
	display(point, x);
	return 0;
}
