#include<iostream>
#include<cstring>
using namespace std;
inline int read()
{
    int x,f=1;
    char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
    for(x=ch-'0';isdigit(ch=getchar());x=x*10+ch-'0');
    return x*f;
}
int u[200100],v[200100];
int first[400200],next[400200];
int main()
{
    int n=read(),m=read(),k;
    memset(first,-1,sizeof(first));
    for(int i=1;i<=m*2;i+=2)
    {
        u[i]=read(),v[i]=read();
        u[i+1]=v[i],v[i+1]=u[i];
        next[i]=first[u[i]];
        first[u[i]]=i;
        next[i+1]=first[u[i+1]];
        first[u[i+1]]=i+1;                                                            
    }
    for(int i=1;i<=n;i++)
    {
        k=first[i];
        printf("Friends of %d :",i);
        if(first[i]==-1) {printf("\n");continue;}
        while(k!=-1)
        {
            printf(" %d",v[k]);
            k=next[k];
        }
        printf("\n");
    }
}
