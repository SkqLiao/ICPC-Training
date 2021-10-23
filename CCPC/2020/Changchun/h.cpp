#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),i##ss=(b);i<=i##ss;i++)
#define dwn(i,a,b) for(int i=(a),i##ss=(b);i>=i##ss;i--)
#define deb(x) cerr<<(#x)<<":"<<(x)<<'\n'
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define hvie '\n'
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int yh() {
    int ret = 0; bool f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == EOF)return -1;
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c))ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
    return f ? -ret : ret;
}
const int maxn = 3e5 + 5, inf = 0x3f3f3f3f;
typedef int Data;
struct edge {
    int to, nxt;
    Data w;
};
vector<edge>E(maxn << 1);
int h[maxn], en = 1;
void addedge(int x, int y, Data w) {
    if (++en == (int)E.size()) E.pb((edge) {
        0, 0, 0
    });
    E[en].to = y;
    E[en].nxt = h[x];
    E[en].w = w;
    h[x] = en;
}
void link(int x, int y, Data w) {
    addedge(x, y, w);
    addedge(y, x, 0);
}
int S = 100001;
int T = 100002; //这里要求T一定是最大的编号,否则自己清零的时候注意
int maxnode = 100002;
int dep[maxn];
int cur[maxn];
queue<int>q;
bool bfs() {
    while (!q.empty()) q.pop();
    for (int i = 0; i <= maxnode; i++) dep[i] = inf; //这个右边界不一定是T
    dep[S] = 0;
    q.push(S);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int e = h[x]; e; e = E[e].nxt) {
            int y = E[e].to;
            if (E[e].w && dep[y] > dep[x] + 1) {
                dep[y] = dep[x] + 1;
                q.push(y);
            }
        }
    }
    return dep[T] < inf;
}
Data dfs(int x, Data flow) {
    if (x == T)return flow;
    Data delta = 0;
    for (int &e = cur[x]; e; e = E[e].nxt) {
        int y = E[e].to;
        if (E[e].w && dep[y] == dep[x] + 1) {
            delta = dfs(y, min(flow, E[e].w));
            if (delta) {
                E[e].w -= delta;
                E[e ^ 1].w += delta;
                return delta;
            }
        }
    }
    return 0;
}
Data calc() {
    Data ans = 0;
    while (bfs()) {
        rep(i, 0, maxnode) cur[i] = h[i]; //右边界不一定是T
        while (int path = dfs(S, inf))ans += path;
    }
    return ans;
}
int m;
int tt;
int H;
vector<int>nxt[maxn];
int pw[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int border[] = {0, 9, 99, 999, 9999, 99999};
bool bad[maxn];
int A[maxn];
int ds[maxn];
int main() {
    rep(i, 0, 99999) {
        rep(j, 0, 4) {
            int x = (i % pw[j + 1]) / pw[j];
            int y = (x + 1) % 10, z = (x + 9) % 10;
            nxt[i].pb(i + (y - x)*pw[j]);
            nxt[i].pb(i + (z - x)*pw[j]);
            ds[i] += x;
        }
    }
    dwn(_, yh(), 1) {
        m = yh(); tt = yh(); H = yh();
        rep(i, 0, maxnode) h[i] = cur[i] = 0;
        en = 1;
        rep(i, 1, tt) bad[A[i] = yh()] = 1;
        rep(i, 0, border[m]) {
            if (!bad[i] && ds[i] % 2 == 0) {
                for (int j : nxt[i])if (!bad[j] && j <= border[m]) {
                        link(i, j, 1);
                    }
            }
        }
        rep(i, 0, border[m]) {
            if (!bad[i] && ds[i] % 2 && i != H) link(i, T, 1);
            if (!bad[i] && ds[i] % 2 == 0 && i != H) link(S, i, 1);
        }

        calc();
        if (ds[H] % 2 == 0) {
            link(S, H, 1);
        } else {
            link(H, T, 1);
        }
        int ans2 = calc();
        puts(ans2 ? "Alice" : "Bob");
        rep(i, 1, tt) bad[A[i]] = 0;
    }
    return 0;
}