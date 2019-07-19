#include<bits/stdc++.h>
using namespace std;
int f[1000];
int n,m,k,sum;
void ini()
{
    for(int i=1;i<=n;i++)
        f[i]=i;
}

int get(int v)
{
    if(f[v]==v)
        return v;
    else
    {
        f[v]=get(f[v]);
        return f[v];
    }
}
void M(int v,int u)
{
    int t1=get(v);
    int t2=get(u);
    if(t1!=t2) 
        f[t2]=t1; 
}
int main()
{
    int i,x,y;
    scanf("%d%d",&n,&m);
    ini();
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        M(x,y);
    }
    sum=0;
    for(i=1;i<=n;i++)
        if(f[i]==i) sum++;
    printf("%d",sum);
    return 0;
}
