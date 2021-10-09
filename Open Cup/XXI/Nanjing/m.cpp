#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;

int n;
vector<int> G[N];
int a[N];
long long f[N][N][2], g[N][2];

int Sz[N];

void dfs2(int x) {
    Sz[x] = 1;
    for (auto v : G[x]) {
        dfs2(v);
        Sz[x] += Sz[v];
    }
}

int dfs(int x) {
    for (int i = 0; i <= Sz[x]; ++i) f[x][i][0] = f[x][i][1] = 1e17;
    f[x][1][1] = 0;
    f[x][0][0] = a[x];
    int num = 1;
    for (auto v : G[x]) {
        int sz = dfs(v);
        for (int i = 0; i <= num + sz; ++i) g[i][0] = g[i][1] = 1e17;
        for (int i = num; i >= 0; --i) {
            for (int j = sz; j >= 0; --j) {
                g[i + j][0] = min(g[i + j][0], f[x][i][0] + min(f[v][j][0] + a[v], f[v][j][1]));
                g[i + j][1] = min(g[i + j][1], f[x][i][1] + min(f[v][j][0], f[v][j][1]));
            }
        }
        num += sz;
        for (int i = 0; i <= num + sz; ++i) f[x][i][0] = g[i][0], f[x][i][1] = g[i][1];
    }
    return num;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 2, x; i <= n; ++i) {
        scanf("%d", &x);
        G[x].push_back(i);
    }
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    dfs2(1);
    dfs(1);
    for (int i = 0; i <= n; ++i) {
        printf("%lld%c", min(f[1][i][0], f[1][i][1]), " \n"[i == n]);
    }
}

int main() {
    int Case;
    scanf("%d", &Case);
    while (Case--) solve();
    return 0;
}