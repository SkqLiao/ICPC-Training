#include<bits/stdc++.h>
#define int long long
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
const int N = 1e7 + 5, M = 1e7, mod = 998244353;
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

ll f[N], g[N], fac[N], ifac[N];

ll ksm(ll x, int p) {
    ll ans = 1;
    for (; p; p >>= 1, x = x * x % mod) if (p & 1) ans = ans * x % mod;
    return ans;
}

signed main() {
    fac[0] = 1;
    rep(i, 1, 1e7) fac[i] = fac[i - 1] * i % mod;
    ifac[M] = ksm(fac[M], mod - 2);
    dwn(i, M - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % mod;
    int n = yh(), k = yh();
    rep(i, 0, k) f[i] = fac[i], g[i] = i;
    rep(i, k + 1, n) {
        f[i] = fac[i - 1] * (g[i - 1] - g[i - k - 1] + mod) % mod;
        g[i] = (g[i - 1] + f[i] * ifac[i] % mod) % mod;
    }
    cout << f[n] << hvie;
    return 0;
}
