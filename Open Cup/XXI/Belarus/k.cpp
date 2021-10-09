/*
 * @date:
 * @source: https://codeforces.com/gym/102956/problem/K
*/
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
#define up(i, l, r) for (int i = l; i <= r; ++i)
#define dn(i, l, r) for (int i = l; i >= r; --i)
#define Trav(i, x) for (auto & i : x)
#define pb push_back
template<class T, class G> bool chkMax(T &x, G y) {
    return y > x ? x = y, 1 : 0;
}
template<class T, class G> bool chkMin(T &x, G y) {
    return y < x ? x = y, 1 : 0;
}

const int N = 70 + 5;
const int M = 150 + 5;

int n, m;
int a[N];
int f[N][N][M];

void solve() {
    cin >> n;
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) chkMax(m, a[i]);
    for (int l = n; l >= 1; --l) {
        for (int k = a[l]; k <= 2 * m; ++k) {
            chkMin(f[l][l][k / 2], k);
        }
        for (int r = l; r < n; ++r) {
            for (int k = 0; k <= m; ++k) {
                chkMin(f[l][r + 1][max(k, a[r + 1]) / 2], f[l][r][k] + max(0, a[r + 1] - k));
            }
            for (int p = r + 1; p <= n; ++p) {
                for (int k1 = 0; k1 <= m; ++k1) {
                    for (int k2 = 0; k2 <= m; ++k2) {
                        chkMin(f[l][p][min(m, k1 + k2)], f[l][r][k1] + f[r + 1][p][k2]);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        int ans = INT_MAX;
        for (int j = 0; j <= m; ++j) chkMin(ans, f[1][i][j]);
        cout << ans << " \n"[i == n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}