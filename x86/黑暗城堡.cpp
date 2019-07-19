#include <bits/stdc++.h>
using namespace std;
long long n, m, x, y, z, f[1001][1001], c[1001], k, w, tot = 0, sum[1001], ans = 1, minn;
bool v[1001];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) f[i][j] = INT_MAX;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		f[x][y] = z;
		f[y][x] = z;
	}
	for (int i = 1; i <= n; i++) c[i] = f[1][i];
	memset(v, 0, sizeof(v));
	v[1] = 1;
	c[1] = 0;
	for (int i = 1; i <= n - 1; i++) {
		minn = INT_MAX;
		k = 0;
		for (int j = 1; j <= n; j++) {
			if (!v[j] && c[j] < minn)
				minn = c[j], k = j;
		}
		if (k == 0)
			break;
		v[k] = 1;
		for (int j = 1; j <= n; j++)
			if (c[j] > c[k] + f[k][j])
				c[j] = c[k] + f[k][j];
	}
	for (int i = 1; i <= n; i++) {
		tot = 0;
		for (int j = 1; j <= n; j++) {
			if (f[i][j] != INT_MAX && (f[i][j] + c[j] == c[i]))
				tot++;
		}
		if (tot > 0)
			ans *= tot;
		ans %= INT_MAX;
	}
	cout<<ans;
	return 0;
}
