#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct coord
{
    int x,y;
};

int main()
{
    ifstream fin("date.in");
    int n,m;
    fin>>n>>m;
    int a[100][100],b[100][100];
    vector<coord> sol;

    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            fin>>a[i][j];
    fin.close();

    for(int i=0; i<n; ++i)
        b[i][0]=a[i][0];

    int maxim=0,maxi,maxj;
    for(int j=1; j<m; ++j)
        for(int i=0; i<n; ++i)
        {
            int mx=0;
            if(i>0&&b[i-1][j-1]>mx)mx=b[i-1][j-1];
            if(b[i][j-1]>mx)mx=b[i][j-1];
            if(i<n-1&&b[i+1][j-1]>mx)mx=b[i+1][j-1];
            b[i][j]=a[i][j]+mx;
            if(b[i][j]>maxim){
                maxim=b[i][j];
                maxi=i;
                maxj=j;
            }
        }

    coord x;
    x.x = maxi;
    x.y = maxj;
    sol.push_back(x);
    int i = maxi,j = maxj;
    while(j>0)
    {
        if(i>0&&b[i][j]-a[i][j]==b[i-1][j-1]){
            x.x = --i;
            x.y = --j;
            sol.push_back(x);
        }
        else if(b[i][j]-a[i][j]==b[i][j-1]){
            x.y = --j;
            sol.push_back(x);
        }
        else if(i<n-1&&b[i][j]-a[i][j]==b[i+1][j-1]){
            x.x = ++i;
            x.y = --j;
            sol.push_back(x);
        }
    }

    cout<<maxim<<endl;
    for(i=sol.size()-1; i>=0; --i)
        cout<<sol[i].x+1<<" "<<sol[i].y+1<<endl;

    return 0;
}
