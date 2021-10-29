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

const int N = 200 + 5;
const int INF = 0x3f3f3f3f;

int a[N], b[N], c[N][N];
int l, r;

struct Edge {
    int to, nxt, flow, cost;
} E[(N * N) << 1];
int H[N], cntE = 1;
inline void add(int u, int v, int f, int c) {
    E[++cntE] = (Edge) {
        v, H[u], f, c
    };
    H[u] = cntE;
    E[++cntE] = (Edge) {
        u, H[v], 0, -c
    };
    H[v] = cntE;
}
int Pe[N], Pv[N], Dis[N];
bool Vis[N];
struct cmp {
    inline bool operator () (const int &x, const int &y) const {
        return Dis[x] > Dis[y];
    }
};
queue<int> pq;
int spfa(int s, int t) {
    memset(Dis, 0x3f, sizeof Dis);
    memset(Vis, 0, sizeof Vis);
    Dis[s] = 0, pq.push(s);
    while (!pq.empty()) {
        int x = pq.front();
        Vis[x] = 0, pq.pop();
        for (int i = H[x]; i; i = E[i].nxt) {
            if (E[i].flow > 0 && Dis[E[i].to] > Dis[x] + E[i].cost) {
                Dis[E[i].to] = Dis[x] + E[i].cost;
                Pe[E[i].to] = i, Pv[E[i].to] = x;
                if (!Vis[E[i].to])
                    Vis[E[i].to] = 1, pq.push(E[i].to);
            }
        }
    }
    return Dis[t] < INF;
}
int cost, flow;
void mcmf(int s, int t) {
    cost = flow = 0;
    while (spfa(s, t)) {
        int f = INF;
        for (int i = t; i != s; i = Pv[i])
            f = min(f, E[Pe[i]].flow);
        cost += f * Dis[t];
        flow += f;
        for (int i = t; i != s; i = Pv[i])
            E[Pe[i]].flow -= f, E[Pe[i] ^ 1].flow += f;
    }
}

void solve() {
    cin >> l >> r;
    int s = l + r + 1, t = l + r + 2;
    for (int i = 1; i <= l; ++i) {
        cin >> a[i];
        add(s, i, a[i], 0);
    }
    for (int i = 1; i <= r; ++i) {
        cin >> b[i];
        add(i + l, t, b[i], 0);
    }
    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= r; ++j) {
            cin >> c[i][j];
            add(i, j + l, 1e9, -c[i][j]);
        }
    }
    mcmf(s, t);
    cout << -cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}