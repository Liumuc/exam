#include<bits/stdc++.h>
using namespace std;
int b[100],sum = 0,n,k;
void dfs(int a)
{
	if(n == 0) return ;
	if(a == k)
	{
		if(n >= b[a-1])
		{
			sum++;
			return;
		}
	}
	for(int i = b[a - 1];i <= n/(k - a + 1);i++)
	{
		b [a] = i;
		n -= i;
		dfs(a+1);
		n += i;	
	}
	
}
int main()
{
	cin>>n>>k;
	b[0] = 1;
	dfs(1);
	cout<<sum;	
} 
