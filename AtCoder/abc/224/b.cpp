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

const int N = 50 + 5;

int n, m;
int a[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i1 = 1; i1 <= n; ++i1) {
        for (int j1 = 1; j1 <= m; ++j1) {
            for (int i2 = i1 + 1; i2 <= n; ++i2) {
                for (int j2 = j1 + 1; j2 <= m; ++j2) {
                    if (a[i1][j1] + a[i2][j2] > a[i1][j2] + a[i2][j1]) {
                        cout << "No" << endl;
                        return ;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}