#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<pair<int,int>> p;
    vector<pair<int,int>>::iterator iter;
    int n,x,y,c=0,maxwidth=0,maxy=0,stidx,my,prex;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        p.push_back(pair<int,int>(x,y));
    }
    sort(p.begin()->first,p.end()->first);
    maxy=p.begin()->second;
    for(iter=p.begin();iter!=p.end();iter++)
    {
        if(maxy<iter->second)
        {
            maxy=iter->second;
            stidx=c;
        }
        c++;
    }
    prex=p.begin()->first;
    my=p.begin()->second;
    for(iter=p.begin();iter<=p.begin()+stidx;iter++)
    {
        if(my<iter->second)
        {
            maxwidth+=my*(iter->first-prex);
            prex=iter->first;
            my=iter->second;
        }
    }
    prex=(p.begin()+n-1)->first;
    my=(p.begin()+n-1)->second;
    for(iter=p.begin()+n-1;iter>=p.begin()+stidx;iter--)
    {
        if(my<iter->second)
        {
            maxwidth+=my*(prex-iter->first);
            prex=iter->first;
            my=iter->second;
        }
        if(iter->second==maxy)
        {
            maxwidth+=maxy*(iter->first-(p.begin()+stidx)->first+1);
            break;
        }
    }
    cout<<maxwidth;
}