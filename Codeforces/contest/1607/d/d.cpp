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

int n;
vi v, vd, vu;
string s;

void solve() {
    cin >> n;
    v.resize(n);
    Trav(x, v) cin >> x;
    cin >> s;
    vd.clear();
    vu.clear();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') vd.pb(v[i]);
        else vu.pb(v[i]);
    }
    sort(ALL(vd));
    sort(ALL(vu));
    int ld = 0, lu = 0;
    for (int i = 1; i <= n; ++i) {
        while (ld < SZ(vd) && vd[ld] < i) ld++;
        if (ld != SZ(vd)) ld++;
        else if (lu != SZ(vu) && vu[lu] <= i) ++lu;
        else {
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
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