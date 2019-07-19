#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX 
const int N = 2010;
const int M = 3010;
int u[M],v[M],w[M];
int dis[N],n,m;
void Bellman_Ford()
{
    cin>>n>>m;
    int flag=0;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];//读入
    for(int i=1;i<=m;i++)
        if(u[i]==1||(w[i]>=0)&&(v[i]==1))
            flag=1;//找到
    if(flag==0)
    {
        cout<<"N0\n";
        return;
    }
    for(int i=1;i<=n;i++)
        dis[i]=inf;
    dis[1]=0;
    for(int k=1;k<=n-1;k++)
    {
        for(int i=1;i<=m;i++)
        {
            if(dis[v[i]]>dis[u[i]]+w[i])//有向
            {
                dis[v[i]]=dis[u[i]]+w[i];
            }
            if(w[i]>=0)//无向
            {
                if(dis[u[i]]>dis[v[i]]+w[i])//换方向
                {
                    dis[u[i]]=dis[v[i]]+w[i];
                }
            }
        }
       
    }
    for(int i=1;i<=m;i++)//负环
    {
        if(dis[v[i]]>dis[u[i]]+w[i])
        {
            cout<<"YE5\n";
            return;
        }
        if(w[i]>=0)//无向
        {
            if(dis[u[i]]>dis[v[i]]+w[i])//换方向
            {
                cout<<"YE5\n";
                return;
            }
        }
    }
    cout<<"N0\n";
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        Bellman_Ford();
}
