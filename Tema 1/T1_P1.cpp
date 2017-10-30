#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int s_even=0,s_odd=0;
    vector<int> v;
    ifstream fin("date.in");

    int i=0;
    int x;
    fin>>x;
    while(!fin.eof())
    {
        v.push_back(x);
        if((i+1)%2!=0)s_odd+=v[i];
        else s_even+=v[i];
        ++i;
        fin>>x;
    }

    if(s_odd>s_even)cout<<s_odd<<" "<<s_even<<"\n";
    else cout<<s_even<<" "<<s_odd<<"\n";

    int lft,rgt;
    lft=0;
    rgt=v.size()-1;

    while(lft<=rgt)
    {
        if(s_odd>s_even)
        {
            if((lft+1)%2!=0)
            {
                cout<<"S ";
                ++lft;
            }
            else
            {
                cout<<"D ";
                --rgt;
            }
        }
        else
        {
            if((lft+1)%2==0)
            {
                cout<<"S ";
                ++lft;
            }
            else
            {
                cout<<"D ";
                --rgt;
            }
        }
        for(int i=lft; i<=rgt; ++i)
            cout<<v[i]<<" ";
        cout<<"\n";

        srand(time(NULL));
        if(rand()%2==0)
        {
            cout<<"S ";
            ++lft;
        }
        else
        {
            cout<<"D ";
            --rgt;
        }

        for(int i=lft; i<=rgt; ++i)
            cout<<v[i]<<" ";
        cout<<"\n";
    }

    fin.close();
    return 0;
}
