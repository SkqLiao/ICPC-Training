#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
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
    return ret;
}
typedef long long ll;
const int N = 3e5 + 10;
int n, m, R, cnt;
int tim[N], las[N];
ll f[N];

struct data {
    int d, k, c;
};
data a[N];

void gmin(ll &x, ll y) {
    x = min(x, y);
}

int main() {
    n = read(); m = read(); R = read();
    for (int i = 1; i <= n; ++i) a[i].d = read(), a[i].k = read(), a[i].c = read(), las[i] = 1;
    for (int i = 1; i <= m; ++i) {
        int day = read(), t = read();
        while (t--) tim[++cnt] = day;
    }
    sort(tim + 1, tim + cnt + 1);
    for (int i = 1; i <= cnt; ++i) {
        f[i] = f[i - 1] + R;
        for (int j = 1; j <= n; ++j) { //las[j] is last buy time
            while (tim[las[j]] + a[j].d <= tim[i] || las[j] + a[j].k <= i) ++las[j];
            gmin(f[i], f[las[j] - 1] + a[j].c);
        }
    }
    printf("%lld\n", f[cnt]);

    return 0;
}