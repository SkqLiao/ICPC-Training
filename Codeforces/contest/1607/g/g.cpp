/* Code Information
 * Author: SkqLiiiao
 * Time: 2021-11-03 15:21:06
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

const int N = 2e5 + 5;

ll n, m;
ll v[N][2];
ll Ans[N][2];
pii f[N];

void solve() {
    cin >> n >> m;
    ll suma = 0, sumb = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i][0] >> v[i][1];
        ll x = min(v[i][0], m);
        suma += v[i][0] - x;
        sumb += v[i][1] - m + x;
        f[i] = {x, v[i][1] - m + x};
    }
    if (suma > sumb) {
        cout << suma - sumb << "\n";
        for (int i = 0; i < n; ++i) {
            ll x = min(v[i][0], m);
            cout << x << " " << m - x << "\n";
        }
        return ;
    }
    ll add = sumb - suma;
    for (int i = 0; i < n; ++i) {
        int x = min(1ll * min(f[i].fir, f[i].sec), add / 2);
        f[i].fir -= x;
        add -= x * 2;
    }
    cout << add << "\n";
    for (int i = 0; i < n; ++i) {
        cout << f[i].fir << " " << m - f[i].fir << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Case;
    cin >> Case;
    while (Case--)
        solve();
    return 0;
}