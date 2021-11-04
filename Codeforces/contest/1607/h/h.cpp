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

int n, m;
map<int, int> Map;
vector<pair<pii, pii>> f[N], v;
pii Ans[N];
pii a[N];

void solve() {
    cin >> n;
    Map.clear();
    m = 0;
    for (int i = 0, x, y, z; i < n; ++i) {
        cin >> x >> y >> z;
        a[i] = {x, y};
        if (!Map.count(x + y - z)) {
            Map[x + y - z] = m;
            f[m++].clear();
        }
        f[Map[x + y - z]].pb({{x, y}, {z, i}});
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        v.clear();
        Trav(a, f[i]) {
            v.pb({{max(0, a.fir.fir - a.sec.fir), min(a.fir.fir, a.fir.fir + a.fir.sec - a.sec.fir)}, {a.fir.fir + a.fir.sec - a.sec.fir, a.sec.sec}});
        }
        sort(ALL(v));
        int p = -1, lst;
        for (int i = 0; i < SZ(v); ++i) {
            auto x = v[i];
            if (x.fir.fir > p) {
                ++ans;
                for (int j = lst; j < i; ++j) {
                    int id = v[j].sec.sec;
                    Ans[id] = {a[id].fir - p, a[id].sec - (v[j].sec.fir - p)};
                }
                lst = i;
                p = x.fir.sec;
            } else if (x.fir.sec < p) p = x.fir.sec;
        }
        for (int j = lst; j < SZ(v); ++j) {
            int id = v[j].sec.sec;
            Ans[id] = {a[id].fir - p, a[id].sec - (v[j].sec.fir - p)};
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; ++i) cout << Ans[i].fir << " " << Ans[i].sec << "\n";
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