#include<bits/stdc++.h>
using namespace std;
struct water{
	double x;
	double y;
}a[20005];
int n,cnt,l,h,x,r;
bool cmp(water x,water y)
{
	return x.x<y.x;
}
void Read()
{
	cin>>n>>l>>h;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>r;
		if(r<=h/2)continue;
		cnt++;
		a[cnt].x=x-sqrt(r*r-h*h/4.0);
		a[cnt].y=x+sqrt(r*r-h*h/4.0);
	}
}
void s()
{
	double t=0;
	int ans=0,bj=1,i=1;
	while(t<l)
	{
		ans++;
		double s=t;
		for(;a[i].x<=s&&i<=cnt;i++)
			if(t<a[i].y)t=a[i].y;
		if(t==s&&s<l)
		{
			cout<<-1<<endl;
			bj=0;
			break;
		}
	}
	if(bj==1)cout<<ans<<endl;
}
int main()
{
	int T; 
	cin>>T;
	while(T--)
	{
		Read();
		sort(a+1,a+cnt+1,cmp);
		s();
	}
	return 0;
}
