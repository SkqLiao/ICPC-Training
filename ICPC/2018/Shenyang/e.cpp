#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define yh read
#define int long long
#define hvie '\n'

typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 10, inf = (ll)1e18;

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

int n, Q;

struct Elem {
    int x, y, c;
} a[N];
int X[N], Y[N], C[N];

pii checkmax(const pii &A, const pii &B) {
    if (A.fi > B.fi) return A;
    return B;
}
pii checkmin(const pii &A, const pii &B) {
    if (A.fi < B.fi) return A;
    return B;
}

struct Data {
    pii Min1, Min2, Max1, Max2;
    void init() {
        Min1 = Min2 = mkp(inf, 0); Max1 = Max2 = mkp(-inf, 0);
    }
};

struct Segment {
#define ls (x<<1)
#define rs (x<<1|1)

    Data t[N << 2];
    Data merge(const Data &A, const Data &B) {
        Data ret; ret.init();
        if (A.Min1.fi < B.Min1.fi) ret.Min1 = A.Min1;
        else ret.Min1 = B.Min1;

        if (A.Max1.fi > B.Max1.fi) ret.Max1 = A.Max1;
        else ret.Max1 = B.Max1;

        if (ret.Min1.se != A.Min1.se) ret.Min2 = checkmin(ret.Min2, A.Min1);
        if (ret.Min1.se != A.Min2.se) ret.Min2 = checkmin(ret.Min2, A.Min2);
        if (ret.Min1.se != B.Min1.se) ret.Min2 = checkmin(ret.Min2, B.Min1);
        if (ret.Min1.se != B.Min2.se) ret.Min2 = checkmin(ret.Min2, B.Min2);

        if (ret.Max1.se != A.Max1.se) ret.Max2 = checkmax(ret.Max2, A.Max1);
        if (ret.Max1.se != A.Max2.se) ret.Max2 = checkmax(ret.Max2, A.Max2);
        if (ret.Max1.se != B.Max1.se) ret.Max2 = checkmax(ret.Max2, B.Max1);
        if (ret.Max1.se != B.Max2.se) ret.Max2 = checkmax(ret.Max2, B.Max2);

        return ret;
    }
    void build(int x, int l, int r, int op) {
        if (l == r) {
            t[x].Min2 = mkp(inf, 0); t[x].Max2 = mkp(-inf, 0);
            if (op == 0) t[x].Min1 = t[x].Max1 = mkp(X[l], a[l].c);
            else t[x].Min1 = t[x].Max1 = mkp(Y[l], a[l].c);
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid, op); build(rs, mid + 1, r, op);
        t[x] = merge(t[ls], t[rs]);
    }
    void update(int x, int l, int r, int p, int val, int c) {
        if (l == r) {
            t[x].Min1 = t[x].Max1 = mkp(val, c);
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) update(ls, l, mid, p, val, c);
        else update(rs, mid + 1, r, p, val, c);
        t[x] = merge(t[ls], t[rs]);
    }
    Data query(int x, int l, int r, int L, int R) {
        if (L <= l && r <= R) return t[x];
        int mid = (l + r) >> 1; Data ret; ret.init();
        if (L <= mid) ret = merge(ret, query(ls, l, mid, L, R));
        if (R > mid) ret = merge(ret, query(rs, mid + 1, r, L, R));
        return ret;
    }
#undef ls
#undef rs
} T[2];

void Query(int l, int r) {
    Data dx = T[0].query(1, 1, n, l, r), dy = T[1].query(1, 1, n, l, r);
    int ansx = 0, ansy = 0;
    if (dx.Min1.se != dx.Max1.se) ansx = dx.Max1.fi - dx.Min1.fi;
    else {
        if (dx.Min2.se) ansx = max(ansx, dx.Max1.fi - dx.Min2.fi);
        if (dx.Max2.se) ansx = max(ansx, dx.Max2.fi - dx.Min1.fi);
    }

    if (dy.Min1.se != dy.Max1.se) ansy = dy.Max1.fi - dy.Min1.fi;
    else {
        if (dy.Min2.se) ansy = max(ansy, dy.Max1.fi - dy.Min2.fi);
        if (dy.Max2.se) ansy = max(ansy, dy.Max2.fi - dy.Min1.fi);
    }
    printf("%lld\n", max(ansx, ansy));
}


signed main() {
    for (int tt = read(), cas = 1; cas <= tt; ++cas) {
        printf("Case #%lld:\n", cas);
        n = read(); Q = read();
        for (int i = 1; i <= n; ++i) {
            a[i].x = read(); a[i].y = read(); a[i].c = read();
            X[i] = a[i].x + a[i].y; Y[i] = a[i].x - a[i].y;
        }
        T[0].build(1, 1, n, 0); T[1].build(1, 1, n, 1);
        while (Q--) {
            int op = read();
            if (op == 1) {
                int k = read(), x = read(), y = read();
                a[k].x += x; a[k].y += y; X[k] = a[k].x + a[k].y; Y[k] = a[k].x - a[k].y;
                T[0].update(1, 1, n, k, X[k], a[k].c); T[1].update(1, 1, n, k, Y[k], a[k].c);
            } else if (op == 2) {
                int k = read(), c = read();
                a[k].c = c;
                T[0].update(1, 1, n, k, X[k], a[k].c); T[1].update(1, 1, n, k, Y[k], a[k].c);
            } else {
                int l = read(), r = read();
                Query(l, r);
            }
        }
    }
    return 0;
}
