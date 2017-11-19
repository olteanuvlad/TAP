#include <iostream>
#include <fstream>
#include <cfloat>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct point
{
    double x,y;
}min_p1, min_p2;

vector<point> V(100005);

double dist(point a, point b)
{
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

int cmp_ord(point a, point b)
{
    return a.y<b.y;
}

int cmp_abs(point a, point b)
{
    return a.x<b.x;
}

double cmap(vector <point>& X, vector <point>& Y, int st, int dr)
{
    if (st >= dr - 1)
        return DBL_MAX;
    else if (dr - st == 2)
    {
        if (Y[st].y > Y[st + 1].y)
            swap(Y[st], Y[st + 1]);
        min_p1 = X[st];
        min_p2 = X[st+1];
        return dist(X[st], X[st + 1]);
    }
    int mij = (st + dr) / 2;
    double d = min(cmap(X, Y, st, mij), cmap(X, Y, mij, dr));

    merge(Y.begin() + st, Y.begin() + mij, Y.begin() + mij, Y.begin() + dr, V.begin(),cmp_ord);
    copy(V.begin(), V.begin() + (dr - st), Y.begin() + st);

    int v_size = 0;
    for (int i = st; i < dr; ++ i)
        if (abs(Y[i].y - X[mij].x) <= d)V[v_size ++] = Y[i];
    for (int i = 0; i < v_size - 1; ++ i)
    {
        for (int j = i + 1; j < v_size && j - i < 8; ++ j)
            {
                if(dist(V[i],V[j])<d)
                {
                    d = dist(V[i],V[j]);
                    min_p1 = V[i];
                    min_p2 = V[j];
                }
            }
    }
    return d;
}

int main()
{
    ifstream fin("date.in");
    int n;
    fin>>n;

    vector<point> X;
    for(int i=0; i<n; ++i)
    {
        point pt;
        fin>>pt.x>>pt.y;
        X.push_back(pt);
    }
    sort(X.begin(),X.end(),cmp_abs);

    vector<point> Y(X.size());
    copy(X.begin(),X.end(),Y.begin());


    cout<<sqrt(cmap(X, Y, 0, (int)X.size()))<<endl;
    cout<<"("<<min_p1.x<<","<<min_p1.y<<") ("<<min_p2.x<<","<<min_p2.y<<")"<<endl;

    fin.close();
    return 0;
}
