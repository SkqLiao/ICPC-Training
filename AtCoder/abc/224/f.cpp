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

const int P = 998244353;

string s;

void solve() {
    cin >> s;
    s = " " + s;
    int n = SZ(s);
    ll a = 0, b = s[1] - '0', two = 1;
    for (int i = 2; i < n; ++i) {
        a = (a + a + b) % P;
        two = two * 2 % P;
        b = (b * 10 % P + (s[i] - '0') * two % P) % P;
    }
    cout << (a + b) % P << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}