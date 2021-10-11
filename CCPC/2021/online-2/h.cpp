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

const int N = 1e6 + 5;
const int P = 1e9 + 7;

int Fac[N], Inv[N], Sum[N];

int ksm(int a, int b, int p = P) {
    int s = 1;
    for (; b; b >>= 1, a = 1ll * a * a % p) if (b & 1) s = 1ll * s * a % p;
    return s;
}

ll solve(int n, int m) {
    ll tmp = (Fac[n - m] * (m - 1) % P - Sum[m - 1] + P) % P;
    return (Fac[m] * (Fac[n - m + 1] + tmp) % P + P) % P;
}

signed main() {
    Fac[0] = 1;
    int t, n, m;
    for (int i = 1; i <= 1e6; ++i) Fac[i] = Fac[i - 1] * i % P;
    for (int i = 0; i <= 1e6; ++i) Inv[i] = ksm(Fac[i], P - 2);
    for (int i = 1; i <= 1e6; ++i) Sum[i] = (Sum[i - 1] + Inv[i]) % P;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << solve(n, m) << endl;
    }
    return 0;
}