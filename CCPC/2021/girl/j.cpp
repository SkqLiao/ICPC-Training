/* Code Information
 * Author: SkqLiiiao
 * Time: 2021-11-09 13:41:30
 * Url:
 **/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define fir first
#define sec second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define up(i, l, r) for (int i = l; i <= r; ++i)
#define dn(i, l, r) for (int i = l; i >= r; --i)
#define Trav(i, x) for (auto &i : x)
#define pb push_back
template <class T, class G> bool chkMax(T &x, G y) {
    return y > x ? x = y, 1 : 0;
}
template <class T, class G> bool chkMin(T &x, G y) {
    return y < x ? x = y, 1 : 0;
}

const int N = 100000 + 5;
const int M = 100 + 5;

int n, k, p;
vector<pii> g[N];
ll f[N][M << 1][2], h[M << 1][2];
int Sz[N], up;

void merge(int u, int v, int w, int a, int b, int c) {
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int x = 0; x <= 1; ++x) {
                for (int y = 0; y <= 1; ++y) {
                    chkMax(h[min(i + j, c)][x], f[u][i][x] + f[v][j][y]);
                }
            }
            if (i && j) chkMax(h[min(c, i + j - 2)][1], f[u][i][0] + f[v][j][0] + w);
        }
    }
    for (int i = 0; i <= c; ++i) {
        for (int j = 0; j <= 1; ++j) {
            f[u][i][j] = h[i][j];
            h[i][j] = -1e18;
        }
    }
}

void dfs(int x, int fa) {
    Sz[x] = 1;
    f[x][0][1] = f[x][1][0] = 0;
    for (auto [v, w] : g[x]) {
        if (v == fa) continue;
        dfs(v, x);
        merge(x, v, w, min(Sz[x], up), min(Sz[v], up), up);
        Sz[x] += Sz[v];
    }
}

void solve() {
    cin >> n >> k >> p;
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    up = 2 * k + 2;
    dfs(1, 0);
    ll ans = 0;
    for (int i = 0; i <= k; ++i) {
        chkMax(ans, max(f[1][i * 2][0], f[1][i * 2][1]) + 1ll * p * i);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}