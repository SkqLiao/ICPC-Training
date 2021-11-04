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

int P[200];
string s, t;

void solve() {
    cin >> s;
    for (int i = 0; i < 26; ++i) P[s[i]] = i;
    cin >> t;
    int ans = 0;
    for (int i = 1; i < SZ(t); ++i) {
        ans += abs(P[t[i]] - P[t[i - 1]]);
    }
    cout << ans << "\n";
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