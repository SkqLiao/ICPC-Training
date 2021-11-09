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

const int N = 200000 + 5;
const int M = 26 + 5;
const int LG = 20;

string s;
int n, m, q;
vector<int> pos[M];
int Nxt[N][LG];
int Lg[N], Bin[LG];

void solve() {
    cin >> m >> n >> s;
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].pb(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            auto it = lower_bound(ALL(pos[j]), i);
            if (it == pos[j].end()) {
                Nxt[i][0] = n;
                break;
            } else chkMax(Nxt[i][0], *it);
        }
    }
    Bin[0] = 1;
    for (int i = 2; i < N; ++i) Lg[i] = Lg[i / 2] + 1;
    for (int i = 1; i <= Lg[n]; ++i) Bin[i] = Bin[i - 1] * 2;
    for (int j = 1; j <= Lg[n]; ++j) {
        for (int i = 0; i < n; ++i) {
            if (Nxt[i][j - 1] >= n - 1) Nxt[i][j] = n;
            else Nxt[i][j] = Nxt[Nxt[i][j - 1] + 1][j - 1];
        }
    }
    cin >> q;
    for (int i = 1, l, r; i <= q; ++i) {
        cin >> l >> r;
        --l, --r;
        int ans = 1;
        for (int i = Lg[n]; i >= 0; --i) {
            if (l < n && Nxt[l][i] <= r) {
                l = Nxt[l][i] + 1;
                ans += 1 << i;
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}