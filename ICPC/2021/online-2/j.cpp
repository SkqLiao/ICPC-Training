#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 5;
const int Dicx[] = {1, -1, 0, 0};
const int Dicy[] = {0, 0, 1, -1};

int n, m;
int h[N][N];
double now[N][N];

bool check(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= n;
}
vector<pair<int, pair<int, int>>> g;

void bfs() {
    for (int i = g.size() - 1; i >= 0; --i) {
        int x = g[i].second.first, y = g[i].second.second;
        int num = 0;
        for (int j = 0; j < 4; ++j) {
            int a = x + Dicx[j], b = y + Dicy[j];
            if (check(a, b) && h[a][b] < h[x][y]) ++num;
        }
        if (!num) continue;
        double per = now[x][y] / num;
        for (int j = 0; j < 4; ++j) {
            int a = x + Dicx[j], b = y + Dicy[j];
            if (check(a, b) && h[a][b] < h[x][y]) {
                now[a][b] += per;
            }
        }
    }
}


int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &h[i][j]);
            now[i][j] = m;
            g.push_back({h[i][j], {i, j}});
        }
    }
    sort(g.begin(), g.end());
    bfs();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (h[i][j]) printf("0");
            else printf("%.7lf", now[i][j]);
            if (j == n) puts("");
            else putchar(' ');
        }
    }
    return 0;
}
