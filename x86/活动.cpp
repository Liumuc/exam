#include<bits/stdc++.h>
using namespace std;
struct no{
	int st;
	int en;
}a[10000]; 
bool cmp(no x,no y){
	return x.en < y.en;
}
int main()
{
	int n,t,sum=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].st>>a[i].en;
	}
	sort(a+1,a+n+1,cmp);
	t = a[1].en;
	for(int i=2;i<=n;i++){
		if(t <= a[i].st){
			sum++;
			t = a[i].en;
		} 
	}
	cout<<sum;
}
