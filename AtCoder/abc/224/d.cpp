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

const int N = 10;

int n = 9, m;
vi g[N];
set<string> st;

void solve() {
    cin >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    string s(n, 'a');
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        s[x - 1] = i + '0';
    }
    string t = s;
    sort(ALL(t));
    st.insert(s);
    queue<pair<string, int>> q;
    q.push({s, 0});
    while (!q.empty()) {
        auto s = q.front().fir;
        auto b = q.front().sec;
        q.pop();
        if (s == t) {
            cout << b << endl;
            return ;
        }
        int p = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') p = i;
        }
        for (auto v : g[p]) {
            swap(s[p], s[v]);
            if (!st.count(s)) {
                st.insert(s);
                q.push({s, b + 1});
            }
            swap(s[p], s[v]);
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
