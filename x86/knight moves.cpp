#include <bits/stdc++.h>
const int xx[] = { 1, 1, -1, -1, 2, 2, -2, -2 }, yy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
struct ad {
	int x, y;
} q[100005], u;
int n, L, h, t, sx, sy, tx, i, ty, f[1005][1005];
int main() {
	for (scanf("%d", &n); n; n--) {
		scanf("%d%d%d%d%d", &L, &sx, &sy, &tx, &ty);
		h = 0;
		memset(f, 0, sizeof f);
		q[t = f[sx][sy] = 1] = (ad) {EOF
			sx, sy
		};
		while (!f[tx][ty] && h < t)
			for (i = 0, u = q[++h]; i < 8; ++i) {
				int x = u.x + xx[i], y = u.y + yy[i];
				if (x >= 0 && x <= L && y >= 0 && y <= L && !f[x][y]) {
					f[x][y] = f[u.x][u.y] + 1;
					q[++t] = (ad) {
						x, y
					};
				}
			}
		printf("%d\n", f[tx][ty] - 1);
	}
	return 0;
}
