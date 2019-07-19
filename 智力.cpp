#include<bits/stdc++.h>
using namespace std;
int a[10000],b[10000],n,m,g[10000],flag,s = 0;
int main() {
	cin>>m>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];//时间限制
	for(int i=1; i<=n; i++)
		cin>>b[i];//罚款数量
	for(int i=1; i<=n; i++) {
		for(int j = i+1; j<=n; j++) {
			if(b[i]<b[j]) {
				swap(b[i],b[j]);
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=1; i<=n; i++) {
		flag = 1;
		for(int j = a[i]; j>=1; j--)
			if(g[j] == 0) {
				flag = 0,g[j] = 1;
				break;
			}
		if(flag == 1) {
			for(int j = n; j>=1; j--) {
				if(g[j] == 0) {
					g[j] = 1;
					break;
				}
			}
			s += b[i];
		}
	}
	printf("%d",m-s);
}
