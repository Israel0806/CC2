#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void ComprobarMOD(int &a, int &b)
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
        return c;
    }
    friend Modulo operator -(Modulo A, Modulo B)
    {
        Modulo c;
        c.a=A.a-B.a;
        c.b=A.b;
        comprobarMOD(c.a,c.b);
        return c;
    }
    friend Modulo operator *(Modulo A, Modulo B)
    {
        Modulo c;
        c.a=A.a*B.a;
        c.b=A.b;
        comprobarMOD(c.a,c.b);
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
    Modulo a(-2,6), b(40,6);
    int c=a.getA(), d=a.getB();
    comprobarMOD(c,d);
    a.setA(c);
    a.setB(d);
    cout<<a.getA()<<"mod"<<a.getB()<<endl;
    a.Inverso();

    return 0;
}
