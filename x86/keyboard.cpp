#include<bits/stdc++.h>
using namespace std;
int n,m,len,to[50][50][4][2],dx[4]= {1,-1,0,0},dy[4]= {0,0,1,-1};
char a[50][50],s[10000];
bool f[50][50][10002];
struct ad {
	int x,y,s,p;
} t1,t2;
queue<ad> q;
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; ++i)for(int j=0; j<m; ++j) scanf(" %c",&a[i][j]);
	scanf(" %s",s);
	len=strlen(s);
	s[len++]='*';
	for(int i=0; i<n; ++i)for(int j=0; j<m; ++j)for(int k=0; k<4; ++k) {
				to[i][j][k][0]=-1;
				int tx=i+dx[k],ty=j+dy[k];
				while(tx>=0&&tx<n&&ty>=0&&ty<m) {
					if(a[i][j]!=a[tx][ty]) {
						to[i][j][k][0]=tx;
						to[i][j][k][1]=ty;
						break;
					}
					tx+=dx[k];
					ty+=dy[k];
				}
			}
	t1.x=t1.y=t1.s=t1.p=0;
	q.push(t1);
	while(q.size()>0) {
		t1=q.front();
		q.pop();
		if(t1.p==len) {
			printf("%d\n",t1.s);
			return 0;
		}
		if(a[t1.x][t1.y]==s[t1.p]&&f[t1.x][t1.y][t1.p+1]==0) {
			t2.x=t1.x;
			t2.y=t1.y;
			t2.s=t1.s+1;
			t2.p=t1.p+1;
			f[t2.x][t2.y][t2.p]=1;
			q.push(t2);
		}
		for(int i=0; i<4; ++i) {
			if(to[t1.x][t1.y][i][0]==-1) continue;
			t2.x=to[t1.x][t1.y][i][0];
			t2.y=to[t1.x][t1.y][i][1];
			if(f[t2.x][t2.y][t1.p]==1) continue;
			f[t2.x][t2.y][t1.p]=1;
			t2.p=t1.p;
			t2.s=t1.s+1;
			q.push(t2);
		}
	}
}
