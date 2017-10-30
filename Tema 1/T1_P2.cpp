/*
Laborator 1(Greedy), Varianta 3, Problema 2
Olteanu Vlad Ionut, grupa 232, semigrupa 2
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void dfs(vector<int> v[],vector<int> &color, int nod, int parent, int& col)
{
    if(color[parent]==0)col=1;
    else col=0;
    color[nod]=col;
    for(int i=0; i<v[nod].size(); ++i)
        if(v[nod][i]!=parent)
            {
                dfs(v, color, v[nod][i], nod, col);
            }
}

int main()
{
    ifstream fin("date.in");
    int n;
    fin>>n;

    vector<int> v[n+1], color;
    color.push_back(0);
    for(int i=0; i<n; ++i)
        {
            color.push_back(i);
            int x,y;
            fin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

    int cnt_black=0, cnt_white=0, col=0;
    dfs(v, color, 1, 0, col);
    for(int i=1; i<=n; ++i)
        if(color[i]==0)++cnt_black;
        else ++cnt_white;

    if(cnt_black>cnt_white)col=0;
    else col=1;

    for(int i=1; i<=n; ++i)
        if(color[i]==col)cout<<i<<" ";
    cout<<endl;

    fin.close();
    return 0;
}
