#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
using namespace std;

void comprobarMOD(int &a, int &b)
{
    bool cond=false;
        if(a<-b)
        {
            a*=-1;
            cond=true;
        }
        if(a>=b)
        {
            a=a%b;

            if(cond)
                a*=-1;
        }
        if(a<0)
        {
            a=b+a;
        }
}

int Euclides(int &a, int &b)
{
	if(a==0)
		return a;
	int d=a;
	a=b%a;
	b=d;
	if(b<0)
		b*=-1;
	return Euclides(a,b);
}

void inversa(int a, int b)
{
    int c=b;
    vector<int> q, p;
    p.push_back(0);
    p.push_back(1);
    int n=0;
    while(a!=0)
    {
        int d=a;
        q.push_back(b/a);
        a=b%a;
        b=d;
        n++;
    }
    int x=2;
    int temp;
    while(x!=n+1)
    {
        temp=p[x-2]-(q[x-2]*p[x-1]);
        comprobarMOD(temp,c);
        cout<<"P"<<x<<": "<<temp<<endl;
        p.push_back(temp);
        x++;
    }
    cout<<"Inversa: "<<p[x-1]<<" mod "<<c<<endl;

}

class Modulo {
    int a,b;
public:
    Modulo() {}
    Modulo(int _a, int _b) :a(_a), b(_b) {}
    Modulo(const Modulo &A) { a=A.a; b=A.b; }

    int getA() { return a; }
    int getB() { return b; }
    void setA(int a) { this->a=a; }
    void setB(int b) { this->b=b; }

    friend void comprobarMOD(int &a, int &b);

    friend Modulo operator +(Modulo A, Modulo B)
    {
        Modulo c;
        c.a=A.a+B.a;
        c.b=A.b;
        comprobarMOD(c.a,c.b);
        cout<<"El modulo es:\n "
            <<c.a<<"mod"<<c.b<<endl;
        return c;
    }
    friend Modulo operator -(Modulo A, Modulo B)
    {
        Modulo c;
        c.a=A.a-B.a;
        c.b=A.b;
        comprobarMOD(c.a,c.b);
        cout<<"El modulo es:\n "
            <<c.a<<"mod"<<c.b<<endl;
        return c;
    }
    friend Modulo operator *(Modulo A, Modulo B)
    {
        Modulo c;
        c.a=A.a*B.a;
        c.b=A.b;
        comprobarMOD(c.a,c.b);
        cout<<"El modulo es:\n "
            <<c.a<<"mod"<<c.b<<endl;
        return c;
    }
    void Inverso()
    {
        Modulo m(a,b);
        Euclides(m.a,m.b);
        if(m.b==1)
        {
            inversa(a,b);
        }
    }
};


int main()
{
    /*Modulo a(-2,6), b(40,6);
    int c=a.getA(), d=a.getB();
    comprobarMOD(c,d);
    a.setA(c);
    a.setB(d);
    cout<<a.getA()<<"mod"<<a.getB()<<endl;
    a.Inverso();
    */
    int op;
    bool cond=true;
    while(cond)
    {
        cout<<"\t\t\t\t\t\tCalculadora modular  \n"
            <<"Ingrese una Opcion:  \n"
            <<"1. Suma              \n"
            <<"2. Resta             \n"
            <<"3. Multiplicacion    \n"
            <<"4. Inversa           \n"
            <<"5. Salir             \n";
        cin>>op;
        switch(op)
        {
            int a,b,c;
            case 1:
            {
            cout<<"Ingrese dos numeros\n"; cin>>a>>b;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,c), B(b,c);
            Modulo C=A+B;
            break;
            }
            case 2:
            {
            cout<<"Ingrese dos numeros\n"; cin>>a>>b;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,c), B(b,c);
            Modulo C=A-B;

            break;
            }
            case 3:
            {
            cout<<"Ingrese dos numeros\n"; cin>>a>>b;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,c), B(b,c);
            Modulo C=A*B;

            break;
            }
            case 4:
            {
            cout<<"Ingrese un numero\n"; cin>>a;
            cout<<"Ingrese el modulo\n"; cin>>c;
            Modulo A(a,c);
            A.Inverso();
            break;
            }
            case 5:
                {
                break;
                }
            default:
                {
                cout<<"Ingrese una opcion correcta\n";
                break;
                }
        }
        if(op==5)
        {
            break;
        }
        char rpta;
        cout<<"\n\nDesea realizar otra operacion--> "; cin>>rpta;
        (rpta=='s' or rpta== 'S')?cond=true:cond=false;

        system("pause");
        system("cls");
    }


    return 0;
}
