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

const int N = 2000 + 5;
const int P1 = 1e9 + 7, P2 = 998244353;
const int L1 = 11, L2 = 17;

int n, m;
string s[N];
ll C1[N][N], C2[N][N], R1[N][N], R2[N][N];
ll Pw1[N], Pw2[N];
ll f1[N << 1], f2[N << 1];

int kmp(int n) {
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && (f1[i] != f1[j] || f2[i] != f2[j])) j = pi[j - 1];
        if (f1[i] == f1[j] && f2[i] == f2[j]) j++;
        pi[i] = j;
    }
    return n - pi[n - 1];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    Pw1[0] = Pw2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        Pw1[i] = Pw1[i - 1] * L1 % P1;
        Pw2[i] = Pw2[i - 1] * L2 % P2;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            C1[i][j] = (C1[i][j - 1] * L1 + s[i][j] - 'a') % P1;
            C2[i][j] = (C2[i][j - 1] * L2 + s[i][j] - 'a') % P2;
            R1[i][j] = (R1[i - 1][j] * L1 + s[i][j] - 'a') % P1;
            R2[i][j] = (R2[i - 1][j] * L2 + s[i][j] - 'a') % P2;
        }
    }
    for (int i = 1, xa, xb, ya, yb; i <= m; ++i) {
        cin >> xa >> ya >> xb >> yb;
        for (int i = xa; i <= xb; ++i) {
            f1[i - xa] = (C1[i][yb] - C1[i][ya - 1] * Pw1[yb - ya + 1] % P1 + P1) % P1;
            f2[i - xa] = (C2[i][yb] - C2[i][ya - 1] * Pw2[yb - ya + 1] % P2 + P2) % P2;
        }
        int x = kmp(xb - xa + 1);
        for (int i = ya; i <= yb; ++i) {
            f1[i - ya] = (R1[xb][i] - R1[xa - 1][i] * Pw1[xb - xa + 1] % P1 + P1) % P1;
            f2[i - ya] = (R2[xb][i] - R2[xa - 1][i] * Pw2[xb - xa + 1] % P2 + P2) % P2;
        }
        int y = kmp(yb - ya + 1);
        cout << x *y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}