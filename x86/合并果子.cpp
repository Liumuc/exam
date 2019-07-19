#include<bits/stdc++.h>
using namespace std;
int n;
int num[850];
int sum[850][850]={0};
int dp[850][850]={0};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=1;i<=n;i++)
	{
		sum[i][i] = num[i];
		for(int j=i+1;j<=n;j++)
		{
			sum[i][j] = sum[i][j-1] + num[j];
		}	
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=j-1;i>=1;i--)
		{
			int minn=999999999;
			for(int k=i;k<j;k++)
			{
				minn=min(minn,dp[i][k]+dp[k+1][j]+sum[i][j]);
			}
			dp[i][j]=minn;
	    }
	}
	cout<<dp[1][n];	
	return 0;
}
