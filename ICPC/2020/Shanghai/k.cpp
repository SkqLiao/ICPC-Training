#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define yh read
#define hvie '\n'


typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 4e5 + 10, inf = 0x3f3f3f3f;

int read() {
    int ret = 0, f = 0; char c = getchar();
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

int n, m, fg, cnt;
int a[N], vis[N], ed[N], st[N], dep[N];
int fa[20][N];
char s[N];
int h[N];
int to[N], nxt[N], en = 1;
void addedge(int x, int y) {
    to[++en] = y;
    nxt[en] = h[x];
    h[x] = en;
}


vector<pii>way;

int dfn[N], low[N], tag[N], sign = 0;
bool bridge[N];

void tarjan(int x, int lastedge, int ff) {
    dfn[x] = low[x] = ++sign;
    vis[x] = 1; st[x] = ++cnt;
    fa[0][x] = ff; dep[x] = dep[ff] + 1;
    for (int i = 1; i < 20; ++i) fa[i][x] = fa[i - 1][fa[i - 1][x]];
    for (int i = h[x]; i; i = nxt[i]) {
        int y = to[i];
        if (!dfn[y]) {
            tarjan(y, i, x);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) {
                bridge[i] = bridge[i ^ 1] = 1;
            }
        } else if ((lastedge ^ 1) != i) low[x] = min(low[x], dfn[y]);
    }
    ed[x] = cnt;
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    for (int t = dep[y] - dep[x], i = 0; t && i < 20; ++i)
        if (t & (1 << i)) y = fa[i][y];
    if (x == y) return x;
    for (int i = 19; i >= 0; --i)
        if (fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
    return fa[0][x];
}

int col[N], colors = 0;
void color(int x, int c) {
    col[x] = c; tag[c] = min(tag[c], low[x]);
    for (int i = h[x]; i; i = nxt[i])if (!bridge[i]) {
            int y = to[i];
            if (!col[y]) color(y, c);
        }
}

bool checkin(int x, int y) {
    if ((st[x] <= st[y] && ed[y] <= ed[x]) || (st[y] <= st[x] && ed[x] <= ed[y])) return 1;
    int z = lca(x, y);
    if ((col[z] == col[x] || col[z] == col[y]) && tag[col[z]] != dfn[z]) return 1;
    return 0;
}

void init() {

    way.clear(); cnt = 0; sign = 0;
    for (int i = 0; i <= en; i++) bridge[i] = 0;
    for (int i = 0; i <= n; ++i) {
        h[i] = dfn[i] = low[i] = col[i] = 0, vis[i] = 0; dep[i] = 0;
        for (int j = 0; j < 20; ++j) fa[j][i] = 0;
    }
    en = 1; colors = 0;
}

int main() {
    rep(_, 1, yh()) {
        init(); n = read(); m = read();
        scanf("%s", s + 1);
        for (int i = 1; i <= n; ++i) a[i] = s[i] == 'L' ? 1 : 0;
        for (int i = 1, x, y; i <= m; ++i) {
            x = read() + 1; y = read() + 1;
            if (a[x] != a[y]) addedge(x, y), addedge(y, x);
            else way.pb(mkp(x, y));
        }

        tarjan(1, 0, 0);
        for (int i = 1; i <= n; i++) {
            if (vis[i] && !col[i]) ++colors, tag[colors] = inf, color(i, colors);
        }

        fg = 0;
        for (auto v : way) {
            if (vis[v.fi] && vis[v.se] && checkin(v.fi, v.se)) {
                fg = 1;
                break;
            }
        }
        puts(fg ? "yes" : "no");
    }
    return 0;
}