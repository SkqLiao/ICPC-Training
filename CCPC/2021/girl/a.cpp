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

const int N = 10 + 5;

int n, m, x, y;
int a[N], b[N];

void solve() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    bool p1 = 0, p2 = 0;
    if (x < y) {
        for (int i = x + 1, p = 1; i <= y; ++i) {
            if (a[i] == b[p]) {
                if (++p > m) p1 = 1;
            }
        }
        for (int i = x - 1, p = 1; i >= 1; --i) {
            if (a[i] == b[p]) {
                if (++p > m) p2 = 1;
            }
        }
    } else {
        for (int i = x - 1, p = 1; i >= y; --i) {
            if (a[i] == b[p]) {
                if (++p > m) p1 = 1;
            }
        }
        for (int i = x + 1, p = 1; i <= n; ++i) {
            if (a[i] == b[p]) {
                if (++p > m) p2 = 1;
            }
        }
    }
    if (!p1 && p2) {
        cout << "Wrong\n";
    } else if (p1 && !p2) {
        cout << "Right\n";
    } else cout << "Unsure\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}