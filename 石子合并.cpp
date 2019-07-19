#include<bits/stdc++.h>
using namespace std;
int n,a[409],f[409][409],g[409][409];
int sum[409];
int main(){
	cin>>n;
	int i,j,k;
	memset(f,127,sizeof(f));
	memset(g,128,sizeof(g));
	for(i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(i=1;i<=2*n;++i){
		sum[i]=sum[i-1]+a[i];
		f[i][i]=g[i][i]=0;
	}
	for(int len=2;len<=2*n;++len){
		for(int l=1;l<=2*n-len+1;++l){
			int r=l+len-1;
			for(int k=l;k<r;++k){
				f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]);
				g[l][r]=max(g[l][r],g[l][k]+g[k+1][r]);
			}
			f[l][r]+=sum[r]-sum[l-1];
			g[l][r]+=sum[r]-sum[l-1];
		}
	}
	int minn = INT_MAX,maxn=-1;
	for(i=1;i<=n;++i){
		minn=min(minn,f[i][i+n-1]);
		maxn=max(maxn,g[i][i+n-1]);
	}
	cout<<minn<<"\n"<<maxn;
	return 0;
}

