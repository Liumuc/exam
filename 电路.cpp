#include <bits/stdc++.h>
using namespace std;
const int N = 505;
struct node {
    int x, y;
};
deque<node> q;
int n, m, dis[N][N];
char s[N][N];
void check(int x, int y, int s, int t) {
    if (dis[x][y] > s + t) {
        dis[x][y] = s + t;
        if (t)
            q.push_back((node){ x, y });
        else
            q.push_front((node){ x, y });
    }
}
void bfs() {
    q.push_front((node){ 1, 1 });
    memset(dis, 0x7f, sizeof(dis));
    dis[1][1] = 0;
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y;
        q.pop_front();
        if (x > 1 && y > 1)
            check(x - 1, y - 1, dis[x][y], s[x - 1][y - 1] != '\\');
        if (x > 1 && y <= m)
            check(x - 1, y + 1, dis[x][y], s[x - 1][y] != '/');
        if (x <= n && y <= m)
            check(x + 1, y + 1, dis[x][y], s[x][y] != '\\');
        if (x <= n && y > 1)
            check(x + 1, y - 1, dis[x][y], s[x][y - 1] != '/');
    }
    printf("%d\n", dis[n + 1][m + 1]);
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    if ((n + m) % 2 == 1)
        puts("NO SOLUTION");
    else
        bfs();
    return 0;
}
