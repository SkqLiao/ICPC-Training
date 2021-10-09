/* Code Information
 * Author: SkqLiiiao
 * Time: 2021-10-08 20:48:35
 * Url:https://codeforces.com/gym/102431/problem/B
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
#define up(i, l, r) for (int i = l; i <= r; ++i)
#define dn(i, l, r) for (int i = l; i >= r; --i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Trav(i, x) for (auto &i : x)
#define pb push_back
template <class T, class G> bool chkMax(T &x, G y) {
    return y > x ? x = y, 1 : 0;
}
template <class T, class G> bool chkMin(T &x, G y) {
    return y < x ? x = y, 1 : 0;
}

const int N = 2000 + 10;
const int P = 1e9 + 7;

int n, m;
int W[N][N];
vi G[N][10];
vector<pii> g[N];
vi g2[N];
vector<pii> path[2];
int Val[N];
int Lst[N][N];
int Mark[N];

void bfs() {
    queue<int> q;
    q.push(1);
    Mark[1] = 1;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        Trav(v, g2[x]) {
            if (Mark[v]) continue;
            Mark[v] = 1;
            q.push(v);
        }
    }
}

int ksm(int a, int b, int p = P) {
    int s = 1;
    for (; b; b >>= 1, a = 1ll * a * a % p) if (b & 1) s = 1ll * s * a % p;
    return s;
}

string anss;
int ans;

pair<string, string> traceback(int f, int x) {
    string s, t;
    for (int i = f, p = x; i > 1; --i) {
        if (i != f && p == x) {
            t = s;
            s.clear();
        }
        s += char(W[Lst[i][p]][p] + '0');
        p = Lst[i][p];
    }
    reverse(ALL(s));
    if (x == 1) {
        if (anss.empty()) anss = s;
        else chkMin(anss, s);
    }
    reverse(ALL(t));
    if (x == 1 && anss == s) {
        ll cur = 0;
        Trav(c, s) {
            cur = (cur * 10 + c - '0') % P;
        }
        ans = cur * ksm(ksm(10, SZ(s)), P - 2) % P;
    }
    return {s, t};
}

void update(string s, string t) {
    ll ss = 0, tt = 0;
    Trav(c, s) {
        ss = (ss * 10 + c - '0') % P;
    }
    Trav(c, t) {
        tt = (tt * 10 + c - '0') % P;
    }
    ll p = ksm(10, SZ(s)), q = ksm(10, SZ(t));
    ans = (tt + ss * (q - 1)) % P * ksm(q - 1, P - 2) % P * ksm(p, P - 2) % P;
}

void init() {
    anss.clear();
    memset(Mark, 0, sizeof Mark);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            G[i][j].clear();
        }
    }
    memset(W, 0x3f, sizeof W);
    for (int i = 0; i < n; ++i) g[i].clear(), g2[i].clear();
    memset(Lst, -1, sizeof Lst);
    for (int i = 0; i <= 1; ++i) path[i].clear();
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        chkMin(W[u][v], w);
        g[u].pb({v, w});
        g2[v].pb(u);
    }
    bfs();
    for (int i = 0; i < n; ++i) {
        if (!Mark[i]) continue;
        Trav(e, g[i]) {
            if (Mark[e.fir] && W[i][e.fir] == e.sec) G[i][e.sec].pb(e.fir);
        }
    }
    path[1].pb({0, 0});
    for (int i = 1, ii = 1; i <= n; ++i, ii ^= 1) {
        memset(Val, 0x3f, sizeof Val);
        Trav(xx, path[ii]) {
            int x = xx.sec, y = xx.fir;
            for (int j = 0; j < 10; ++j) {
                Trav(v, G[x][j]) {
                    if (chkMin(Val[v], y * 10 + j)) {
                        Lst[i + 1][v] = x;
                    }
                }
            }
        }
        path[ii ^ 1].clear();
        for (int j = 0; j < n; ++j) {
            if (Val[j] < 1e9) {
                if (j == 1) traceback(i + 1, 1);
                else path[ii ^ 1].pb({Val[j], j});
            }
        }
        sort(ALL(path[ii ^ 1]));
        int lst = -1, cnt = -1;
        Trav(x, path[ii ^ 1]) {
            if (chkMax(lst, x.fir)) ++cnt;
            x.fir = cnt;
        }
    }
    Trav(x, path[(n + 1) & 1]) {
        auto p = traceback(n + 1, x.second);
        if (p.second.empty()) continue;
        string tmp = p.first;
        while (tmp.size() < 20000) tmp += p.second;
        if (chkMin(anss, tmp)) {
            update(p.first, p.second);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Case;
    cin >> Case;
    for (int t = 1; t <= Case; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}