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

int n, m;
string s;

void solve() {
    cin >> n >> m >> s;
    int x = 0, y = 0, ansx = 1, ansy = 1;
    int mnx = 0, mny = 0, mxx = 0, mxy = 0;
    Trav(c, s) {
        if (c == 'U') --x;
        if (c == 'D') ++x;
        if (c == 'L') --y;
        if (c == 'R') ++y;
        chkMin(mnx, x);
        chkMax(mxx, x);
        chkMin(mny, y);
        chkMax(mxy, y);
        if (mxx - mnx == n || mxy - mny == m) {
            cout << ansx << " " << ansy << "\n";
            return ;
        }
        chkMax(ansx, 1 - mnx);
        chkMax(ansy, 1 - mny);
    }
    cout << ansx << " " << ansy << endl;
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