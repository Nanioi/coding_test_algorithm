#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<pair<int,int>> q;
    pair<int,int> copy;
    vector<int> arr(9,0);
    int tc,n,m,input,cnt=0,flag=1;

    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        cin>>n>>m;
        for(int j=0;j<n;j++)
        {
            cin>>input;
            q.push(pair<int,int>(j,input));
            arr[input-1]++;
        }
        flag=1;
        while(flag){
            copy=q.front();
            q.pop();
            for(int k=8;k>=copy.second-1;k--)
            {
                if(k+1==copy.second)
                {
                    cnt++;
                    arr[k]--;
                    if(copy.second==m)
                    {
                        cout<<cnt<<endl;
                        flag=0;
                        break;
                    }
                }
                if(arr[k]>0)
                {
                    q.push(copy);
                    break;
                }
            }
        }
    }
}