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

const ll inf = 2e18;

int n;
vector<ll> a, f;

vector<ll> mul(vector<ll> &a, vector<ll> &b) {
    vector<ll> v(n, -inf);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            chkMax(v[(i + j) % n], a[i] + b[j]);
        }
    }
    return v;
}

vector<ll> ksm(vector<ll> v, int p) {
    vector<ll> ans(v);
    for (--p; p; p >>= 1) {
        if (p & 1) ans = mul(ans, v);
        v = mul(v, v);
    }
    return ans;
}

void solve() {
    cin >> n;
    a.resize(n);
    f.resize(n);
    ll mx1 = -inf, mx2 = -inf;
    Trav(x, a) {
        cin >> x;
        chkMax(mx1, x);
    }
    Trav(x, f) {
        cin >> x;
        chkMax(mx2, x);
    }
    if (mx2 % mx1 || mx2 / mx1 <= 0 || mx2 / mx1 > 1e9) {
        cout << "-1\n";
        return ;
    }
    int k = mx2 / mx1;
    vector<ll> v(n);
    v[0] = a[n - 1];
    for (int i = 1; i < n; ++i) v[i] = a[i - 1];
    if (ksm(v, k) == f) cout << k << endl;
    else cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}