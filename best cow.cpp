#include<iostream>
#include<stdio.h>
double a[100001],b[100001],sum[100001],eps=1e-5,l=-1e6,r=1e6;
using namespace std;
int main()
{
    int n,L;
    cin>>n>>L;
    for (int i=1;i<=n;i++)
   		scanf("%lf",&a[i]);
    while (r-l>eps)
    {
        double mid=(l+r)/2.0,ans=-1e10,min1=1e10;
        for (int i=1;i<=n;i++)
        b[i]=a[i]-mid;
        for (int i=1;i<=n;i++)
        sum[i]=sum[i-1]+b[i];
        for (int i=L;i<=n;i++)
        {
            min1=min(sum[i-L],min1);
            ans=max(ans,sum[i]-min1);
        }
        if (ans>=0) l=mid;else r=mid;
    }
    cout<<int(r*1000);
    return 0;
}
