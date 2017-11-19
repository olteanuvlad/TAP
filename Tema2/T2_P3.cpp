#include <iostream>
#include <fstream>
using namespace std;

int interclasare(int p,int m,int u,int a[])
{
    int *b=new int[u-p+1];
    int i=p,j=m+1, k=0,nr=0;
    while ((i<=m)&&(j<=u))
    {
        if (a[i]<=2*a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
            nr = nr + (m-i+1);
        }
        k++;
    }
    while(i<=m)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=u)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for (i=p; i<=u; i++)
        a[i]=b[i-p];
    return nr;
}

int nrInv(int p,int u,int a[])
{
    if (p == u)
    {
        return 0;
    }
    else
    {
        int m = (p+u)/2;
        int n1 = nrInv(p,m,a);
        int n2 = nrInv(m+1,u,a);
        return interclasare(p,m,u,a)+n1+n2;
    }
}

int main()
{
    ifstream fin("date.in");

    int n;
    fin>>n;

    int a[n];
    for(int i=0; i<n; ++i)
        fin>>a[i];

    cout<<nrInv(0,n-1,a)<<endl;

    fin.close();
    return 0;
}
