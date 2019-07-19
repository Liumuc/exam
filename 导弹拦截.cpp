#include<bits/stdc++.h>
using namespace std;
long long l;
struct no {
	int r1,r2;
	int x,y;
} a[1000000];
int x,y,xx,yy,i,j,n;
bool cmp(no c,no d) {
	return c.r1<d.r1;
}
int main() {
	cin>>x>>y>>xx>>yy;
	cin>>n;
	int aa,bb;
	for(int i=1; i<=n; i++) {
		cin>>a[i].x>>a[i].y;
		a[i].r1 = (a[i].x-x)*(a[i].x-x)+(a[i].y-y)*(a[i].y-y);
		a[i].r2 = (a[i].x-xx)*(a[i].x-xx)+(a[i].y-yy)*(a[i].y-yy);
	}
	int maxn = 0,minn = 10000001,mm = 0;
	sort(a+1,a+n+1,cmp);
	for(int i=n; i>=1; i--) {
		mm = max(a[i+1].r2,mm);
		minn = min(minn,a[i].r1+mm);
	}
	cout<<minn;
}
