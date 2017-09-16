#include <iostream>

using namespace std;

void _merge(int *a, int low, int high, int mid)
{
    int i, j, k, c[500];
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        a[i] = c[i];
    }
}
void _mergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        _mergeSort(a,low,mid);
        _mergeSort(a,mid+1,high);
        _merge(a,low,high,mid);
    }
}

int main()
{
    int tam=5,a[tam];


    cout<<"Ingrese 5 valores a ordenar:"<<endl;
    for(int i=0; i<tam; i++){
        cin>>a[i];
    }

    cout<<"Los valores antes de ser ordenados:\n";
    for(int i=0;i<tam;i++)
    {
        cout<<a[i]<<"\t";
    }


    _mergeSort(a,0,tam-1);
    cout<<endl<<"Los valores ordenados:\n";
    for(int i=0;i<tam;i++)
    {
        cout<<a[i]<<"\t";
    }
    return 0;
}
