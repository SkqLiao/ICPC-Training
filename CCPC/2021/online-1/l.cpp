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

const int MAXN = 2e6 + 5;
const int INF = 1e9;

int n, p;
vi Prime;
int R[MAXN];
int Ans[MAXN], Right[MAXN];

void solve() {
    scanf("%d%d", &n, &p);
    Prime.resize(p);
    Trav(p, Prime) scanf("%d", &p);
    memset(R, 0, sizeof R);
    int mx = 0;
    ll lcm = 1;
    Trav(p, Prime) {
        for (int i = p; i <= n; i += p) {
            chkMax(R[i], min(n, i + p - 1));
        }
        chkMax(mx, p);
        if (lcm <= n)
            lcm *= p;
    }
    memset(Right, 0, sizeof Right);
    memset(Ans, 0, sizeof Ans);
    Right[1] = min(n, mx - 1);
    int cur = 1;
    int nn = min((ll)n, lcm - 1);
    for (int i = 1; i <= nn; ++i) {
        if (i > Right[cur]) ++cur;
        Ans[i] = cur;
        chkMax(Right[cur + 1], R[i]);
    }
    unsigned long long ans = 0, base = 1;
    for (int i = n; i >= 1; --i) {
        ans = ans + base * Ans[i];
        base *= 23333;
        //cerr << i << " " << Ans[i] << endl;
    }
    printf("%llu\n", ans);
}

int main() {
    int Case;
    scanf("%d", &Case);
    while (Case--) solve();
    return 0;
}