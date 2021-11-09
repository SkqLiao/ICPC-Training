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

int n;
vi v;

void solve() {
    cin >> n;
    v.resize(n);
    Trav(x, v) cin >> x;
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += max(v[i - 1], v[i]);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}