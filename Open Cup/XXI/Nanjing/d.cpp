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

const int N = 1e5 + 5;

int n, m;
vi G[N];
vector<pii> ans;
int nn;
int Vis[N], Degree[N], tot;

void dfs(int x) {
    Vis[x] = 1;
    ++tot;
    random_shuffle(ALL(G[x]));
    Trav(v, G[x]) {
        if (Degree[x] == nn) break;
        if (!Vis[v]) {
            ans.pb({x, v});
            ++Degree[v];
            ++Degree[x];
            dfs(v);
        }
    }
}

bool check() {
    memset(Vis, 0, sizeof(int) * (n + 1));
    memset(Degree, 0, sizeof(int) * (n + 1));
    tot = 0;
    ans.clear();
    dfs(rand() % n + 1);
    return tot == n;
}

void solve() {
    cin >> n >> m;
    nn = n / 2;
    for (int i = 1; i <= n; ++i) G[i].clear();
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        G[x].pb(y);
        G[y].pb(x);
    }
    for (int t = 1; t <= 100; ++t) {
        if (check()) {
            cout << "Yes\n";
            Trav(e, ans) cout << e.first << " " << e.second << "\n";
            return ;
        }
    }
    cout << "No\n";
}

int main() {
    srand((unsigned long long)(new char));
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Case;
    cin >> Case;
    while (Case--) solve();
    return 0;
}