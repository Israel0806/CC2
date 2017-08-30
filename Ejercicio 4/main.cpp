#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string.h>

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

int inversa(int a, int b)
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
        p.push_back(temp);
        x++;
    }
    return p[x-1];
}

class Modulo {
    int a,b;
public:
    Modulo(int _a, int _b) :a(_a), b(_b) {}
    Modulo(const Modulo &A) { a=A.a; b=A.b; }

    int getA() { return a; }
    int getB() { return b; }
    void setA(int a) { this->a=a; }
    void setB(int b) { this->b=b; }

    friend void comprobarMOD(int &a, int &b);

    int Inverso()
    {
        int c;
        Modulo m(a,b);
        Euclides(m.a,m.b);
        if(m.b==1)
        {
            c=inversa(a,b);
        }
        return c;
    }
};

int main()
{
    int k1=29, k2=53;

    ifstream readOut;
    readOut.open("prueba.txt", ios::out );

    ofstream New;
    New.open("temp.txt", ios::in);

    if (readOut.is_open() and New.is_open() )
      {
        string line;
        while ( getline (readOut,line) )
        {
            int mod=256;
            char p[ line.size() ];
            strcpy( p,line.c_str() );

            for(unsigned int i=0;i<line.size();i++)
            {
                cout<<"line: "  <<p[i]            <<endl
                    <<int(p[i]) <<" mod 256"      <<endl;
                int x= int(p[i]);
                x*=k1;
                cout<<"x: "<<x<<endl;
                comprobarMOD(x,mod);

                cout<<"Inverso: "<<x<<" mod 256" <<endl<<endl;
                New << char(x);

            }
            New.close();
        }
        readOut.close();
      }
    else
    {
        cout<<"error\n";
    }

    ifstream readOut2;
    readOut2.open("temp.txt", ios::out );

    ofstream New2;
    New2.open("temp2.txt", ios::in);

    if (readOut2.is_open() and New2.is_open() )
      {
        string line;
        while ( getline (readOut2,line) )
        {
            int mod=256;
            char p[ line.size() ];
            strcpy( p,line.c_str() );

            for(unsigned int i=0;i<line.size();i++)
            {
                cout<<"line: "  <<p[i]            <<endl
                    <<int(p[i]) <<" mod 256"      <<endl;
                int x= int(p[i]);
                x*=k2;
                cout<<"x: "<<x<<endl;
                comprobarMOD(x,mod);

                cout<<"Inverso: "<<x<<" mod 256" <<endl<<endl;
                New2 << char(x);

            }
            New2.close();
        }
        readOut2.close();
      }
    else
    {
        cout<<"error\n";
    }


    return 0;
}


/*
                    ifstream readOut;
                    readOut.open("codigos.txt", ios::out );

                    ofstream Modify;
                    Modify.open("codigos.txt", ios::in);

                    if (readOut.is_open() and Modify.is_open())
                      {
                        int a=0;
                        string line;
                        while ( getline (readOut,line) )
                        {
                            a+=line.size()+1;
                            if(line=="codigo2")
                            {
                                getline(readOut,line);
                                a+=line.size();
                                p2=atoi(line.c_str());
                                p2++;
                                cout << p2 << '\n';
                                Modify.seekp(a+2);
                                Modify <<p2;
                                Modify.close();
                                break;
                            }
                        }
                        readOut.close();
                      }
                    else
                    {
                        cout<<"error\n";
                    }



        ifstream readOut;
        readOut.open("Impresoras.txt");
        ofstream readIn;
        readIn.open("temp.txt");
        while ( readOut >> codigo >> nombre >> categoria >>  precio >> cantidad >> tipo >> caracteristicas >> tamanho )
        {
            if ( miCodigo != codigo)
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << cantidad << ' ' << tipo << ' ' << caracteristicas << ' ' << tamanho <<endl;            }
            else
            {
                readIn<< codigo << ' ' << nombre << ' ' << categoria << ' ' << precio << ' ' << stock << ' ' << tipo << ' ' << caracteristicas << ' ' << tamanho <<endl;            }
    }
    readIn.close();
    readOut.close();
    remove("Impresoras.txt");
    rename("temp.txt","Impresoras.txt");
    cout <<endl<<endl<<endl;


*/

