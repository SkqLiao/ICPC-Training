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

int n;
vi g[N];
int Dfn[N], Nfd[N], Sz[N], cntD;
int Fa[N][20];
pii a[N];

void dfs(int x, int fa) {
    Sz[x] = 1;
    Dfn[x] = ++cntD;
    Nfd[cntD] = x;
    Fa[x][0] = fa;
    for (int i = 1; i < 20; ++i) {
        Fa[x][i] = Fa[Fa[x][i - 1]][i - 1];
    }
    Trav(v, g[x]) {
        if (v == fa) continue;
        dfs(v, x);
        Sz[x] += Sz[v];
    }
}

int Color[N * 5];

void pushDown(int rt) {
    chkMax(Color[rt << 1], Color[rt]);
    chkMax(Color[rt << 1 | 1], Color[rt]);
}

void update(int rt, int l, int r, int a, int b, int x) {
    if (a <= l && r <= b) {
        chkMax(Color[rt], x);
        return ;
    }
    int m = (l + r) >> 1;
    pushDown(rt);
    if (a <= m) update(rt << 1, l, m, a, b, x);
    if (m < b) update(rt << 1 | 1, m + 1, r, a, b, x);
}

int query(int rt, int l, int r, int p) {
    if (l == r) return Color[rt];
    int m = (l + r) >> 1;
    pushDown(rt);
    if (p <= m) return query(rt << 1, l, m, p);
    else return query(rt << 1 | 1, m + 1, r, p);
}

int Ans[N];

struct SegmentTree {
    static const int N = ::N * 40;
    static const int INF = 1e9;
    struct Node {
        int ls, rs, mx;
    } A[N];
    int tot;
    int newNode() {
        auto &a = A[tot];
        a.ls = a.rs = a.mx = 0;
        return tot++;
    }
    void init() {
        tot = 1;
        newNode();
    }
    void pushUp(int rt) {
        auto &x = A[rt], &ls = A[A[rt].ls], &rs = A[A[rt].rs];
        x.mx = max(ls.mx, rs.mx);
    }
    int query(int rt, int l, int r, int a, int b) {
        if (!rt) return 0;
        if (a <= l && r <= b) return A[rt].mx;
        int m = (l + r) >> 1, ans = 0;
        if (a <= m) chkMax(ans, query(A[rt].ls, l, m, a, b));
        if (m < b) chkMax(ans, query(A[rt].rs, m + 1, r, a, b));
        return ans;
    }
    void update(int &rt, int l, int r, int p, int x) {
        if (!rt) rt = newNode();
        if (l == r) {
            A[rt].mx = x;
            return ;
        }
        int m = (l + r) >> 1;
        if (p <= m) update(A[rt].ls, l, m, p, x);
        else update(A[rt].rs, m + 1, r, p, x);
        pushUp(rt);
    }
    void copy(int &u, int &v, int l, int r, int a, int b) {
        if (!u) return ;
        if (a <= l && r <= b) {
            v = u;
            u = 0;
            return ;
        }
        if (!v) v = newNode();
        int m = (l + r) >> 1;
        if (a <= m) copy(A[u].ls, A[v].ls, l, m, a, b);
        if (m < b) copy(A[u].rs, A[v].rs, m + 1, r, a, b);
        pushUp(u);
        pushUp(v);
    }
} T;
int Rt[N];

int get(int p, int x) {
    for (int i = 19; i >= 0; --i) {
        if (Dfn[Fa[p][i]] > Dfn[x]) p = Fa[p][i];
    }
    return p;
}

void update(int p) {
    int fa = query(1, 1, n, Dfn[p]);
    //printf("query %d=%d\n", Dfn[p], fa);
    if (fa) fa = Nfd[fa];
    //printf("Fa[%d]=%d\n", p, fa);
    int ffa = get(p, fa);
    //printf("ffa=%d\n", ffa);
    if (!fa) Ans[p] = T.A[Rt[fa]].mx;
    else Ans[p] = T.query(Rt[fa], 1, n, Dfn[ffa], Dfn[ffa] + Sz[ffa] - 1);
    //printf("query [%d, %d]\n", Dfn[ffa], Dfn[ffa] + Sz[ffa] - 1);
    if (fa) chkMax(Ans[p], Ans[fa]);
    //printf("mx=%d\n", Ans[p]);
    ++Ans[p];
    //printf("Ans[%d]=%d\n", p, Ans[p]);
    T.copy(Rt[fa], Rt[p], 1, n, Dfn[p], Dfn[p] + Sz[p] - 1);
    T.update(Rt[fa], 1, n, Dfn[p], Ans[p]);
    //printf("update %d<-(%d) - %d\n", fa, Dfn[p], Ans[p]);
    //T.update(Rt[p], 1, n, Dfn[p], Ans[p]);
    //printf("update [%d,%d]=%d\n", Dfn[p], Dfn[p] + Sz[p] - 1, Dfn[p]);
    update(1, 1, n, Dfn[p], Dfn[p] + Sz[p] - 1, Dfn[p]);
}

void solve() {
    cin >> n;
    cntD = 0;
    fill(Rt, Rt + n + 1, 0);
    T.init();
    for (int i = 0; i <= n; ++i) g[i].clear();
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fir;
        a[i].sec = i;
    }
    dfs(1, 0);
    sort(a + 1, a + n + 1);
    memset(Color, 0, sizeof(int) * (n * 4 + 100));
    for (int i = n; i >= 1; --i) {
        update(a[i].sec);
    }
    for (int i = 1; i <= n; ++i) cout << Ans[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Case;
    cin >> Case;
    while (Case--) solve();
    return 0;
}