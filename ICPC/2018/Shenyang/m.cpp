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
const int maxn = 3e5 + 5, mod = 1e9 + 7, lim = 1000;
int n, m;
int f[10005][1005], g[10005][1005];
void cp(int *f, int b) { //   *(1/(1-x^b))
    rep(i, b, lim) (f[i] += f[i - b]) %= mod;
}
inline void reduce(int &x) {
    x += x >> 31 & mod;
}
void zo(int *f, int V) { //   *(1-x^v)
    dwn(i, lim, V) reduce((f[i] -= f[i - V]) %= mod);
}

int main() {
    rep(_, 1, yh()) {
        cout << "Case #" << _ << ":\n";
        n = yh(), m = yh(); rep(i, 0, n)rep(j, 0, lim)f[i][j] = g[i][j] = 0;
        f[0][0] = 1;
        g[0][0] = 1;
        rep(i, 1, n) {
            int a = yh(), b = yh();
            rep(j, 0, lim) f[i][j] = f[i - 1][j], g[i][j] = g[i - 1][j];
            cp(f[i], b);
            zo(f[i], (a + 1)*b);
            cp(g[i], (a + 1)*b);
            zo(g[i], b);
        }
        // rep(k,0,n){rep(i,0,6)cout<<f[k][i]<<" ";puts("");}
        rep(i, 0, n) {
            rep(j, 1, lim) (g[i][j] += g[i][j - 1]) %= mod;
        }
        int ans = 0;
        while (m--) {
            int l = (yh() + ans) % n + 1, r = (yh() + ans) % n + 1, c = yh();
            if (l > r)swap(l, r);
            ans = 0;
            rep(j, 0, c) (ans += (ll)f[r][j] * g[l - 1][c - j] % mod) %= mod;
            cout << ans << hvie;
        }
    }
    return 0;
}