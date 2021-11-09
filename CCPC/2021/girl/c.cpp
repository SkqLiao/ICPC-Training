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

const int N = 40;
const int M = 19;

int n, m;
int a[N], w[N], b[N];
vi g[N], c[N];
int f[N][1 << M];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        c[a[i]].pb(i);
    }
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) b[i] = w[a[i]];
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        g[u].pb(v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (c[i].empty()) continue;
        if (SZ(c[i]) == 1) a[c[i][0]] = -1;
        else {
            for (auto x : c[i]) a[x] = cnt;
            cnt++;
        }
    }
    memset(f, -1, sizeof f);
    if (a[1] == -1) f[1][0] = b[1];
    else {
        f[1][0] = 0;
        f[1][1 << a[1]] = b[1];
    }
    for (int i = 1; i <= n; ++i) {
        int ans = 0;
        for (int j = 0; j < 1 << cnt; ++j) {
            if (f[i][j] == -1) continue;
            for (auto v : g[i]) {
                if (a[v] == -1) {
                    chkMax(f[v][j], f[i][j] + b[v]);
                } else {
                    chkMax(f[v][j], f[i][j]);
                    if (!((j >> a[v]) & 1)) chkMax(f[v][j | (1 << a[v])], f[i][j] + b[v]);
                }
            }
            chkMax(ans, f[i][j]);
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}