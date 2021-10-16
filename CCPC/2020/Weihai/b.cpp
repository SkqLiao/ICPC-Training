#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define fir first
#define sec second
#define yh read
#define hvie '\n'

typedef long long ll;
typedef pair<int, int> pii;

ll read() {
    ll ret = 0, f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
        c = getchar();
    }
    return f ? -ret : ret;
}
const int N = 2e5 + 5;
const int K = 45;
const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int INF = 0x3f3f3f3f;

int n, m, k, q;
int x[K], y[K];
set<pii> Exists, Nodes;
map<pii, int> p;
int Dis[K * 8][N];

int id(int x, int y) {
    return (x - 1) * m + y - 1;
}

bool judge(int x, int y) {
    return x >= 1 && y >= 1 && x <= n && y <= m && !Exists.count({x, y});
}

void bfs(int Dis[], int sx, int sy) {
    queue<pii> que;
    que.push({sx, sy});
    Dis[id(sx, sy)] = 0;
    while (!que.empty()) {
        auto a = que.front(); que.pop();
        for (int i = 1; i < 8; i += 2) {
            int nx = a.fir + dx[i], ny = a.sec + dy[i];
            if (judge(nx, ny) && Dis[id(nx, ny)] == INF) {
                Dis[id(nx, ny)] = Dis[id(a.fir, a.sec)] + 1;
                que.push({nx, ny});
            }
        }
    }
}

int solve(int sx, int sy, int tx, int ty) {
    int ans = abs(sx - tx) + abs(sy - ty), ans2 = INF;
    bool flag = 1;
    int mxx = max(sx, tx), mnx = min(sx, tx);
    int mxy = max(sy, ty), mny = min(sy, ty);
    for (int i = 1; i <= k; ++i) {
        if (x[i] >= mnx && x[i] <= mxx && y[i] >= mny && y[i] <= mxy) {
            flag = 0;
            for (int j = 0; j < 8; ++j) {
                int nx = x[i] + dx[j], ny = y[i] + dy[j];
                if (judge(nx, ny)) {
                    int a = p[ {nx, ny}];
                    ans2 = min(ans2, Dis[a][id(sx, sy)] + Dis[a][id(tx, ty)]);
                }
            }
        }
    }
    return flag ? ans : ans2 == INF ? -1 : ans2;
}

int main() {
    n = read(), m = read(), k = read(), q = read();
    for (int i = 1; i <= k; ++i) {
        x[i] = read(), y[i] = read();
        Exists.insert({x[i], y[i]});
    }
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < 8; ++j) {
            int nx = x[i] + dx[j], ny = y[i] + dy[j];
            if (judge(nx, ny)) Nodes.insert({nx, ny});
        }
    }
    memset(Dis, 0x3f, sizeof Dis);
    int id = 0;
    for (auto s : Nodes) {
        p[s] = ++id;
        bfs(Dis[id], s.fir, s.sec);
    }
    while (q--) {
        int sx = read(), sy = read(), tx = read(), ty = read();
        cout << solve(sx, sy, tx, ty) << "\n";
    }
    return 0;
}