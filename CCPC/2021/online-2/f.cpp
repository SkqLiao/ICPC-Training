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
#define int long long

const int N = 1e5 + 5;
const int M = 10;
const int P = 998244353;
const string S = "nunhehheh";

string s;
int F[M], G[N], Pow[N];

void add(int &x, int y) {
    x = (x + y % P) % P;
}

void solve() {
    int ans = 0;
    cin >> s;
    int n = SZ(s), m = SZ(S);
    G[n] = 0;
    for (int i = n - 1; i >= 0; --i) G[i] = G[i + 1] + (s[i] == 'a');
    memset(F, 0, sizeof F);
    for (int i = 0; i < n; ++i) {
        int lst = F[m - 1];
        if (s[i] == S[0]) add(F[0], 1);
        for (int j = m - 1; j > 0; --j) {
            if (s[i] == S[j]) add(F[j], F[j - 1]);
        }
        int now = (F[m - 1] - lst + P) % P;
        if (!now) continue;
        add(ans, (Pow[G[i + 1]] - 1) * now % P);
    }
    cout << (ans % P + P) % P << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Pow[0] = 1;
    for (int i = 1; i < N; ++i) Pow[i] = Pow[i - 1] * 2 % P;
    int Case;
    cin >> Case;
    for (int t = 1; t <= Case; ++t) {
        solve();
    }
    return 0;
}