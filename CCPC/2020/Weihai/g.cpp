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

typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e5 + 10, M = N * 8, mod = 1e9 + 7, bas = 17, MOD = 65536;

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
int fc[N], sum[N], a[N];

void up(int &x, int y) {
    x += y;
    x %= mod;
}
int upm(int x) {
    return x % mod;
}

struct Segment {
#define ls (x<<1)
#define rs (x<<1|1)
    struct data {
        int mx, hs, len, tag;
        data(int mx = 0, int hs = 0, int len = 0, int tag = 0): mx(mx), hs(hs), len(len), tag(tag) {}
    } t[M];
    data merge(const data &A, const data &B) {
        data ret;
        ret.hs = (1ll * A.hs * fc[B.len] % mod + B.hs) % mod;
        ret.len = A.len + B.len;
        ret.mx = max(A.mx, B.mx);
        ret.tag = 0;
        return ret;
    }
    void pushup(int x) {
        t[x] = merge(t[ls], t[rs]);
    }
    void pushdown(int x) {
        if (t[x].tag) {
            int c = t[x].tag;
            t[ls].tag += c; t[rs].tag += c;
            t[ls].mx += c; t[rs].mx += c;
            assert(t[ls].len >= 1 && t[rs].len >= 1);
            up(t[ls].hs, 1ll * c * sum[t[ls].len - 1] % mod); up(t[rs].hs, 1ll * c * sum[t[rs].len - 1] % mod);
            t[x].tag = 0;
        }
    }
    void build(int x, int l, int r) {
        if (l == r) {
            t[x] = data(a[l], a[l], 1, 0);
            return;
        }
        int mid = (l + r) >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x);
    }
    data query(int x, int l, int r, int L, int R) {
        if (L <= l && r <= R) return t[x];
        int mid = (l + r) >> 1; data ret = data(0, 0, 0, 0);
        pushdown(x);
        if (L <= mid) ret = merge(ret, query(ls, l, mid, L, R));
        if (R > mid) ret = merge(ret, query(rs, mid + 1, r, L, R));
        pushup(x);
        return ret;
    }
    void modify(int x, int l, int r) {
        if (l > r) return;
        if (l == r) {
            t[x].mx %= MOD; t[x].hs = t[x].mx; t[x].len = 1; t[x].tag = 0;
            return;
        }
        pushdown(x);
        int mid = (l + r) >> 1;
        if (t[ls].mx >= MOD) modify(ls, l, mid);
        if (t[rs].mx >= MOD) modify(rs, mid + 1, r);
        pushup(x);
    }
    void update(int x, int l, int r, int L, int R) {
        if (L > R) return;
        if (L <= l && r <= R) {
            t[x].tag++; t[x].mx++; up(t[x].hs, sum[t[x].len - 1]);
            if (t[x].mx >= MOD) modify(x, l, r);
            return;
        }
        pushdown(x);
        int mid = (l + r) >> 1;
        if (L <= mid) update(ls, l, mid, L, R);
        if (R > mid) update(rs, mid + 1, r, L, R);
        pushup(x);
    }

#undef ls
#undef rs
} tr;

int main() {
    fc[0] = 1; for (int i = 1; i < N; ++i) fc[i] = 1ll * fc[i - 1] * bas % mod;
    sum[0] = 1; for (int i = 1; i < N; ++i) sum[i] = (sum[i - 1] + fc[i]) % mod;

    n = read(); Q = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    tr.build(1, 1, n);
    while (Q--) {
        int op = read();
        if (op & 1) {
            int l = read(), r = read();
            tr.update(1, 1, n, l, r);
        } else {
            int x = read(), y = read(), L = read();
            //printf("%d %d\n",tr.query(1,1,n,x,x+L-1).hs,tr.query(1,1,n,y,y+L-1).hs);
            puts(tr.query(1, 1, n, x, x + L - 1).hs == tr.query(1, 1, n, y, y + L - 1).hs ? "yes" : "no");
        }
    }
    return 0;
}

/*
5 6
1 2 1 2 1
2 1 2 2
2 1 3 3
1 1 1
1 3 5
2 1 2 4
2 1 2 2


3 3
0 65535 65535
2 1 2 2
1 2 3
2 1 2 2
*/


