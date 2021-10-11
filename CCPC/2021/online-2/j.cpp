#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
#define fi first
#define se second

typedef double db;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e3 + 5;
int n, m;
int fa[N], du[N];
pii a[N];
set<int>st;

int read() {
    int ret = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = 0;
        c = getchar();
    }
    while (isdigit(c)) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
        c = getchar();
    }
    return f ? ret : -ret;
}
int findf(int x) {
    return fa[x] == x ? x : fa[x] = findf(fa[x]);
}

int main() {
    rep(cas, 1, read()) {
        n = read(); m = read(); int tmpm = m;
        st.clear();
        for (int i = 1; i <= n; ++i) st.insert(i + n);
        for (int i = 1; i <= 2 * n; ++i) fa[i] = i, du[i] = 0;
        for (int i = 1; i <= m; ++i) {
            a[i].fi = read(), a[i].se = read(), fa[a[i].fi] = a[i].se + n;
            du[a[i].fi] = du[a[i].se + n] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (; du[i] < 2 && m < 2 * n - 1;) {
                int tmp = 0;
                for (auto v : st) {
                    if (findf(i) == findf(v)) continue;
                    ++du[i]; ++du[v]; ++m;
                    a[m].fi = i; a[m].se = v;
                    tmp = v;
                    fa[findf(i)] = findf(v);
                    break;
                }
                if (du[tmp] == 2) st.erase(tmp);
            }
        }
        int l = 0, r = 0;
        for (int i = 1; i <= n; ++i) if (du[i] != 2) {
                l = i;
                break;
            }
        for (int i = n + 1; i <= 2 * n; ++i) if (du[i] != 2) {
                r = i;
                break;
            }
        ++m; a[m].fi = l; a[m].se = r;
        sort(a + tmpm + 1, a + m + 1);
        printf("%d\n", m - tmpm);
        for (int i = tmpm + 1; i <= m; ++i) printf("%d %d\n", a[i].fi, a[i].se - n);
    }
    return 0;
}
