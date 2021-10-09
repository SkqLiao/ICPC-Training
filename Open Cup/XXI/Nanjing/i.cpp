#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define hvie '\n'
int yh() {
    int ret = 0, f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
        c = getchar();
    }
    return f ? -ret : ret;
}
const int N = 1e3 + 5;
typedef long double db;
int n, m;
db vy;
struct vc {
    db x, y;
    vc() {}
    vc(db x, db y, int id = 0): x(x), y(y) {}
    void init() {
        x = yh(), y = yh();
    }
    bool operator<(const vc &A)const {
        return x < A.x || (x == A.x && y < A.y);
    }
} a[N];
vc operator-(const vc &a, const vc &b) {
    return vc(a.x - b.x, a.y - b.y);
}
db operator*(const vc &a, const vc &b) {
    return a.x * b.y - a.y * b.x;
}
db operator^(const vc &a, const vc &b) {
    return a.x * b.x + a.y * b.y;
}
const db eps = 1e-10;
int sgn(int x) {
    if (x - eps > 0) return 1;
    if (x + eps < 0)return -1;
    return 0;
}
bool inter(const vc &a, const vc &b, const vc &c, const vc &d) {
    return sgn((c - a) * (b - a)) * sgn((d - a) * (b - a)) < 0
           &&
           sgn((a - c) * (d - c)) * sgn((b - c) * (d - c)) < 0;
}
int Inter(const vc &a, const vc &b, const vc &c, const vc &d) {
    int d1 = sgn((b - a) * (c - a));
    int d2 = sgn((b - a) * (d - a));
    int d3 = sgn((d - c) * (a - c));
    int d4 = sgn((d - c) * (b - c));
    if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)return 2;
    return (d1 == 0 && sgn((c - a) ^ (c - b)) <= 0) ||
           (d2 == 0 && sgn((d - a) ^ (d - b)) <= 0) ||
           (d3 == 0 && sgn((a - c) ^ (a - d)) <= 0) ||
           (d4 == 0 && sgn((b - c) ^ (b - d)) <= 0);

}
struct seg {
    vc a, b;
    void init() {
        a.init();
        b.init();
    }
} s[N];
db dp[N];
int nxt[N];
int tot = 0;
bool cmp(const int &i, const int &j) {
    return a[i].y < a[j].y;
}
db on(vc a, vc b, db x) {
    if (a.x == b.x) {
        return max(a.y, b.y);
    }
    return (b.y - a.y) / (b.x - a.x) * (x - a.x) + a.y;
}
bool isMin(int u) {
    rep(i, 1, n)if (min(s[i].a.x, s[i].b.x) <= a[u].x && a[u].x <= max(s[i].a.x, s[i].b.x) && (u + 1) / 2 != i) {
        if (Inter(s[i].a, s[i].b, a[u], vc(a[u].x, -10001))) return 0;
    }
    return 1;
}
bool isMax(int u) {
    rep(i, 1, n)if (min(s[i].a.x, s[i].b.x) <= a[u].x && a[u].x <= max(s[i].a.x, s[i].b.x) && (u + 1) / 2 != i) {
        if (Inter(s[i].a, s[i].b, a[u], vc(a[u].x, 10001))) return 0;
    }
    return 1;
}
vector<int>adj[N];
int ind[N];
bool vis[N];
vector<int>st;
vector<int>ed;
bool check(db k) {
    queue<int>q;
    rep(i, 1, tot) vis[i] = 0;
    for (int i : st)if (fabs(a[i].x) < m) {
            q.push(i), vis[i] = 1;
        }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (fabs(a[u].x) >= m) continue;
        // cout<<u<<endl;
        for (int v : adj[u])if (!vis[v] && fabs((a[v].x - a[u].x) / (a[v].y - a[u].y)) <= k) {
                vis[v] = 1; q.push(v);
            }
    }
    for (int i : ed) if (vis[i]) return 1;
    return 0;
}

int main() {
    // while(1){
    //  s[1].init();s[2].init();
    //  cout<<Inter(s[1].a,s[1].b,s[2].a,s[2].b)<<endl;
    // }
    n = yh(), m = yh(), vy = yh();
    queue<int>q;
    rep(i, 1, n) {
        s[i].init();
        a[2 * i - 1] = s[i].a;
        a[2 * i] = s[i].b;
        nxt[2 * i - 1] = 2 * i;
        nxt[2 * i] = 2 * i - 1;
    }
    tot = 2 * n;
    rep(i, 1, tot) dp[i] = 1e18;
    rep(i, 1, tot)if (isMin(i)) {
        st.pb(i);
        dp[i] = fabs(a[i].x) < m ? 0 : 1e18;
    }
    rep(i, 1, tot)if (isMax(i)) {
        ed.pb(i);
    }
    rep(i, 1, tot) {
        rep(j, 1, tot)if (fabs(a[j].x) < m && a[j].y > a[i].y && nxt[i] != j) {
            bool ok = 1;
            rep(l, 1, n)if ((i + 1) / 2 != l && (j + 1) / 2 != l && Inter(a[i], a[j], s[l].a, s[l].b)) {
                ok = 0;
                break;
            }
            if (ok) {
                adj[i].pb(j);
                ind[j] += 1;
            }
        }
        if (a[nxt[i]].y > a[i].y) {
            adj[i].pb(nxt[i]);
            ind[nxt[i]] += 1;
        }
    }
    db L = 0, R = 1e9;
    db ans = 1e18;
    // cout<<Inter(a[7],a[5],s[1].a,s[1].b)<<endl;
    // check(0.5);exit(0);
    while (L + eps < R) {
        db mid = (L + R) / 2;
        if (check(mid)) {
            R = mid; ans = mid;
        } else L = mid;
    }
    // while(!q.empty()){
    //  int u=q.front();q.pop();
    //  for(int v:adj[u]){
    //      dp[v]=min(dp[v],max(dp[u],fabs((a[v].x-a[u].x)/(a[v].y-a[u].y))));
    //      if(--ind[v]==0) q.push(v);
    //  }
    // }
    // db ans=1e18;
    // rep(i,1,tot)if(isMax(i)){
    //  ans=min(ans,dp[i]);
    // }
    bool ck = 1;
    rep(i, 1, n) if (Inter(vc(0, -10001), vc(0, 10001), s[i].a, s[i].b)) {
        ck = 0;
        break;
    }
    if (ck) ans = 0;
    if (ans == 1e18)puts("-1");
    else cout << fixed << setprecision(12) << ans *vy << hvie;
    return 0;
}
/*
3 2 1
-2 0 1 0
-1 4 2 4
0 1 0 3

*/