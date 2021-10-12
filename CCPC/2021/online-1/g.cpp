/*
 * @date:
 * @source:
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
#define int ll
const int MAXN = 60;

vector<int> g[MAXN];

int divide(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

ll n;

ll cal(ll a, ll b, ll x) {
    if (x < 1 || x > n) return LLONG_MAX;
    return a * x * x + b * x;
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d >> n;
    ll ans = LLONG_MAX;
    for (int i = 1; i <= 54; ++i) {
        if (g[i][0] > n) continue;
        ll A = a * i + b;
        ll B = c * i * i + d * i;
        if (A > 0) {
            double mid = -B / 2.0 / A;
            if (mid <= g[i][0]) {
                chkMin(ans, cal(A, B, g[i][0]));
            } else if (mid >= n) {
                chkMin(ans, cal(A, B, *--upper_bound(ALL(g[i]), n)));
            } else {
                int p = lower_bound(ALL(g[i]), mid) - g[i].begin();
                int a = max(0ll, p - 2);
                int b = min(SZ(g[i]) - 1, p + 2);
                for (int j = a; j <= b; ++j) if (g[i][j] <= n) chkMin(ans, cal(A, B, g[i][j]));
            }
        } else {
            chkMin(ans, cal(A, B, g[i][0]));
            chkMin(ans, cal(A, B, *--upper_bound(ALL(g[i]), n)));
        }
    }
    cout << ans << "\n";
}

void pre() {
    for (int i = 1; i <= 1e6; ++i) g[divide(i)].pb(i);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int Case;
    cin >> Case;
    while (Case--) solve();
    return 0;
}