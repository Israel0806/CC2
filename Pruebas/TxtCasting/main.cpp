#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    ifstream readOut;
    readOut.open("prueba.txt", ios::out );

    if (readOut.is_open())
      {
        string line;
        while ( getline (readOut,line) )
        {
            int n=line.size();
            char p[n];
            strcpy(p,line.c_str());

            for(unsigned int i=0;i<line.size();i++)
            {
                cout<<"line "<<p[i]<<endl;
            }
            break;
        }
        readOut.close();
      }
    else
    {
        cout<<"error\n";
    }
    return 0;
}


