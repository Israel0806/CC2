#include <iostream>

using namespace std;

int main()
{
    int n=5,a[n];
    int iz=1,der=n,ultimo=n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    while(iz<der)
    {

        for(int i=der-1;i>=iz;i--)
        {
            if(a[i-1]>a[i])
            {
                swap(a[i-1],a[i]);
                ultimo=i;
            }
        }
        iz=ultimo+1;

        for(int i=iz;i<der;i++)
        {
            if(a[i-1]>a[i])
            {
                swap(a[i-1],a[i]);
                ultimo=i;
            }
        }
        der=ultimo;

    }
    cout<<endl<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<"--";
    return 0;
}
