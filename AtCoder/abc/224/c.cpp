/*
 * @date:2021-10-26 16:43:15
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

int n;
vector<pii> p;

void solve() {
    cin >> n;
    p.resize(n);
    Trav(x, p) cin >> x.fir >> x.sec;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (1ll * (p[i].sec - p[j].sec) * (p[k].fir - p[j].fir) != 1ll * (p[k].sec - p[j].sec) * (p[i].fir - p[j].fir)) ++ans;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}