#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int zfill(int x,int y,int k)
{
    int sq;
    if(k>1)
    {
        k--;
        sq=pow(2,k);
        if(x>sq&&y>sq)
        {
            return pow(4,k)*3+zfill(x-sq,y-sq,k);
        }
        if(y<=sq&&x>sq)
        {
            return pow(4,k)*2+zfill(x-sq,y,k);
        }
        if(y>sq&&x<=sq)
        {
            return pow(4,k)+zfill(x,y-sq,k);
        }
        if(y<=sq&&x<=sq)
            return zfill(x,y,k);
    }
    else return (x-1)*2+y;
}
int main()
{
    ifstream fin("date.in");
    int n,k,x,y;
    fin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        fin>>x>>y;
        cout<<zfill(x,y,n)<<endl;
    }

    fin.close();
    return 0;
}
