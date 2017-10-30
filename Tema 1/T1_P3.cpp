/*
Laborator 1(Greedy), Varianta 3, Problema 3
Olteanu Vlad Ionut, grupa 232, semigrupa 2
Se citesc n intervale [a,b] si se impart intr-un numar k minim de multimi a.i. toate intervalele dintr-o anumita multime sunt
disjuncte.

INPUT:
n
a1 b1
.....
an bn

OUTPUT:
m1: ai bi
.........
mk: aj bj
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct interval
{
    int a,b,index,Set;
};

class compare
{
public:
    int operator()(interval &x, interval &y)
    {
        if(x.b>y.b)return 1;
        else if(x.b<y.b)return 0;
        else
        {
            if(x.a>y.a)return 1;
            else return 0;
        }
    }
};

int v_compare(interval &x, interval &y)
{
    if(x.b>y.b)return 0;
        else if(x.b<y.b)return 1;
        else
        {
            if(x.a>y.a)return 0;
            else return 1;
        }
}

int main()
{
    //se citesc datele
    ifstream fin("date.in");
    int n;
    fin>>n;

    vector<interval> v;
    for(int i=0; i<n; ++i)
    {
        interval x;
        fin>>x.a>>x.b;
        x.index=i+1;
        v.push_back(x);
        //cout<<v[i].a<<" "<<v[i].b<<" "<<v[i].index<<"\n";
    }

    //se sorteaza vectorul
    sort(v.begin(), v.end(), v_compare);

    //se adauga primul interval din vectorul sortat in prima multime a solutiei
    priority_queue <interval, vector<interval>, compare> min_heap;
    int k=1;
    interval sol[n+1][n+1];
    v[0].Set=1;
    sol[k][0].index=1;
    sol[k][1]=v[0];
    min_heap.push(v[0]);

    //se verifica pe rand fiecare interval care nu a fost inca adaugat in solutie
    //daca se poate adauga unei multimi deja existente se adauga, altfel se creeaza o noua multime in care devine primul element
    for(int i=1; i<n; ++i)
    {
        interval x=min_heap.top();
        if(x.b<=v[i].a)
        {
            sol[x.Set][0].index++;
            sol[x.Set][sol[x.Set][0].index]=v[i];
            min_heap.pop();
            min_heap.push(v[i]);
        }
        else
        {
            ++k;
            sol[k][0].index=1;
            sol[k][1]=v[i];
            min_heap.push(v[i]);
        }
    }

    //se afiseaza solutia
    for(int i=1; i<=k; ++i)
    {
        cout<<i<<": ";
        for(int j=1; j<=sol[i][0].index; ++j)
            cout<<sol[i][j].index<<" ";
        cout<<"\n";
    }

    fin.close();
    return 0;
}
