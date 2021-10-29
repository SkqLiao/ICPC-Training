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

const int N = 2e5 + 5;

int n, m, k;
map<int, vector<pii>> A;
int cmx[N], rmx[N];
map<pii, int> B;
int f[N];

void solve() {
    cin >> n >> m >> k;
    for (int i = 0, x, y, z; i < k; ++i) {
        cin >> x >> y >> z;
        A[-z].pb({x, y});
        B[ {x, y}] = i;
    }
    memset(cmx, -1, sizeof cmx);
    memset(rmx, -1, sizeof rmx);
    for (auto a : A) {
        Trav(p, a.second) {
            f[B[p]] = 1 + max(cmx[p.fir], rmx[p.sec]);
        }
        Trav(p, a.second) {
            chkMax(cmx[p.fir], f[B[p]]);
            chkMax(rmx[p.sec], f[B[p]]);
        }
    }
    for (int i = 0; i < k; ++i) cout << f[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}