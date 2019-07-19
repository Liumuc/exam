#include<bits/stdc++.h>
using namespace std;
const int inf = 99999999;
int v[100],w[100],tot = 0,head[100],next[100],dis[100];
bool flag[100];
int n,m,step;
int xx,yy,zz;
void add(int x,int y,int z)
{
	v[++tot]=y;
	w[tot]=z;
	next[tot] = head[x];
	head[x] = tot;
}
void dijstra()
{
	priority_queue< pair<int,int> >q;
	for(int i=1;i<=n;i++)
		dis[i] = inf;
	dis[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int t=q.top().second;
		q.pop();
		if(flag[t]) continue;
		flag[t]=1;
		for(int i=head[t];i!=0;i=next[i])
		{
			if(dis[v[i]] > dis[t] + w[i] && flag[v[i]]==0)
			{
				dis[v[i]] = dis[t] + w[i];
				q.push(make_pair(-dis[v[i]],v[i]));
			}
		}
	}
}
int main()
{
	cin>>n>>m;
	for(int i = 1;i<=m;i++)
	{
		cin>>xx>>yy>>zz;
		add(xx,yy,zz);
	}
	dijstra();
	cout<<dis[1];
	for(int i=2;i<=n;i++)
		cout<<" "<<dis[i];
}
