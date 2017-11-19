#include <iostream>
#include <fstream>
using namespace std;

int peak(int l, int r,int a[])
{
    if(l==r)return a[l];
    int m=(l+r)/2;
    if(a[m]<a[m+1])return peak(m+1,r,a);
    else return peak(l,m,a);
}

int main()
{
    ifstream fin("date.in");

    int n;
    fin>>n;
    int a[n];
    for(int i=0; i<n; ++i)
        fin>>a[i];

    cout<<peak(0,n-1,a);

    fin.close();
    return 0;
}
