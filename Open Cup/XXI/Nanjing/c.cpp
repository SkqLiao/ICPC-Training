#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define hvie '\n'
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
typedef long long ll;
typedef pair<ll, ll> pll;
const ll inf = (ll)1e18;
const int N = 2e5 + 5;
const int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};

void gmin(ll &x, ll y) {
    x = min(x, y);
}
void gmax(ll &x, ll y) {
    x = max(x, y);
}

struct Segment {
#define ls (x<<1)
#define rs (x<<1|1)
    ll val[N << 2];
    void init(int n) {
        for (int i = 0; i < n * 4; ++i)val[i] = inf;
    }
    void pushup(int x) {
        val[x] = min(val[ls], val[rs]);
    }
    void update(int x, int l, int r, int p, ll v) {
        if (l == r) {
            val[x] = v;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) update(ls, l, mid, p, v);
        else update(rs, mid + 1, r, p, v);
        pushup(x);
    }
    ll query(int x, int l, int r, int L, int R) {
        if (L > R) return inf;
        if (L <= l && r <= R) return val[x];
        int mid = (l + r) >> 1; ll ret = inf;
        if (L <= mid) gmin(ret, query(ls, l, mid, L, R));
        if (R > mid) gmin(ret, query(rs, mid + 1, r, L, R));
        return ret;
    }
#undef ls
#undef rs
} tr[2][2];

int n;
ll ans;
ll mi[N], mx[N];
pll p[N], tp[N];

ll solve() {
    sort(p + 1, p + n + 1);
    int pos = 1;
    while (pos <= n && p[pos].fi <= 0) ++pos;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j)
            tr[i][j].init(n);
    mx[1] = mi[1] = 0;
    for (int i = 1; i < pos; ++i) {
        if (i > 1) mx[i] = max(p[i - 1].se, mx[i - 1]), mi[i] = max(-p[i - 1].se, mi[i - 1]);
        for (int j = 0; j < 2; ++j) for (int k = 0; k < 2; ++k)
                tr[j][k].update(1, 1, n, i, -p[i].fi + j * mx[i] * 2 + k * mi[i]);
    }
    ll tans = inf, tmin = 0, tmax = 0;
    for (int i = n; i && p[i].fi >= 0; --i) { // rig max
        int p1 = lower_bound(mx + 1, mx + pos, tmax) - mx, p2 = lower_bound(mi + 1, mi + pos, tmin) - mi;
        gmin(tans, p[i].fi * 2 + tmax * 2 + tmin + tr[0][0].query(1, 1, n, 1, min(p1, p2) - 1));
        gmin(tans, p[i].fi * 2 + tmax * 2 + tr[0][1].query(1, 1, n, p2, p1 - 1));
        gmin(tans, p[i].fi * 2 + tmin + tr[1][0].query(1, 1, n, p1, p2 - 1));
        gmin(tans, p[i].fi * 2 + tr[1][1].query(1, 1, n, max(p1, p2), pos - 1));
        gmax(tmax, p[i].se); gmax(tmin, -p[i].se);
    }
    return tans;
}


int main() {
    for (int T = read(); T--;) {
        n = read();
        for (int i = 1; i <= n; ++i) p[i].fi = read(), p[i].se = read();
        p[++n] = mkp(0, 0);
        for (int i = 1; i <= n; ++i) tp[i] = p[i];
        ans = inf;
        for (int j = 0; j < 4; ++j) {
            for (int i = 1; i <= n; ++i)
                p[i].fi = tp[i].fi * dx[j], p[i].se = tp[i].se * dy[j];
            ans = min(ans, solve());
        }
        printf("%lld\n", ans);
    }
    return 0;
}
