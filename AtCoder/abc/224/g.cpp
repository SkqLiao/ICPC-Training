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

ll n, s, t, a, b;

double f(ll x) {
    return a * (x - 1) / 2.0 + (double)b * n / x;
}

void solve() {
    cin >> n >> s >> t >> a >> b;
    double ans = 1e100;
    if (s <= t) ans = a * (t - s);
    ll x = sqrt(2.0 * b * n / a);
    if (x <= t) chkMin(ans, f(x));
    if (x + 1 <= t) chkMin(ans, f(x + 1));
    chkMin(ans, f(t));
    cout << fixed << setprecision(16) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}