#include<bits/stdc++.h>
#define int long long
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
#define pb push_back
using namespace std;
struct node {
    int x;  ll d;
    bool operator < (const node &a)const {
        return d > a.d;
    }
} ;
const int maxn = 1e5 + 5, maxm = 2e5 + 5, inf = 4557430888798830399;
struct ed {
    int x, y; ll w, b;
} e[maxm];
struct rec {
    int tp, id;
    ll w;
};
bool cmp(rec a, rec b) {
    if (a.w != b.w)return a.w < b.w;
    else return a.tp > b.tp;
}
struct Ed {
    int to, nxt; ll w;
} E[maxm * 5];
int cnt, h[maxn + maxm * 2], n, m;
ll d[maxn + maxm * 2];
bool vis[maxn + maxm * 2];
void addedge(int x, int y, ll w) {
    E[++cnt] = {y, h[x], w}; h[x] = cnt;
}
vector<rec>pt[maxn];

void dij() {
    priority_queue<node>q;
    q.push({(m << 1) + 1, 0});
    rep(i, 0, 2 * m + n) d[i] = inf, vis[i] = 0;
    // memset(d,0x3f,sizeof(d));
    // memset(vis,0,sizeof(vis));
    d[(m << 1) + 1] = 0;
    node x; int i, y;
    while (!q.empty()) {
        x = q.top(); q.pop();
        if (vis[x.x])continue;
        vis[x.x] = 1;
        for (i = h[x.x]; i; i = E[i].nxt) {
            y = E[i].to;
            ll w = E[i].w;
            if (d[y] > x.d + w) {
                d[y] = x.d + w;
                q.push({y, d[y]});
            }
        }
    }
}
signed main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    dwn(_, yh(), 1) {
        int i, j, x, y, w, b;
        ll ans;
        n = yh(), m = yh();
        cnt = 0;
        memset(h, 0, sizeof(h));
        rep(i, 1, n)pt[i].clear();
        rep(i, 1, m) {
            x = yh(), y = yh(), w = yh(), b = yh();
            e[i] = {x, y, w, b};
            pt[x].pb({1, i, w});
            pt[y].pb({0, i, w});
        }
        rep(i, 1, n) {
            sort(pt[i].begin(), pt[i].end(), cmp);
            if (pt[i].size() == 0)continue;
            int id = pt[i][0].id * 2 - pt[i][0].tp, pre;
            for (j = 1; j < (int)pt[i].size(); j++) {
                pre = id;
                id = pt[i][j].id * 2 - pt[i][j].tp;
                addedge(pre, id, 0);
            }
            for (auto x : pt[i]) {
                if (x.tp == 0) {
                    id = x.id * 2;
                    addedge(id, (m << 1) + i, 0);
                } else {
                    id = x.id * 2 - 1;
                    addedge(id, id + 1, e[x.id].w - e[x.id].b);
                    addedge((m << 1) + i, id + 1, e[x.id].w);
                }
            }
        }
        dij();
        rep(i, 1, n) {
            if (d[(m << 1) + i] == inf)ans = -1;
            else ans = d[(m << 1) + i];
            cout << ans << " \n"[i == n];
        }
    }
}
