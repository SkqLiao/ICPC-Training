#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a),i##ss=(b);i<=i##ss;i++)
#define dwn(i,a,b) for(int i=(a),i##ss=(b);i>=i##ss;i--)
#define deb(x) cerr<<(#x)<<":"<<(x)<<'\n'
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define hvie '\n'
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int yh() {
    int ret = 0; bool f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == EOF)return -1;
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c))ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
    return f ? -ret : ret;
}
const int maxn = 3e5 + 5, inf = 1e18;
int n, m;
int s[maxn];
map<int, set<pii> >pos;
void solve() {
    pos[0].insert(mkp(0, 0));
    rep(i, 1, n) {
        int d = s[i] / s[n];
        int m = s[i] % s[n];
        if (m < 0) d--, m += s[n];

        auto it = pos[m].lower_bound(mkp(d, -1));
        if (it == pos[m].end() || it->fi != d) pos[m].insert(mkp(d, i));
    }
    for (auto x : pos) {
        pos[x.fi].insert(mkp(inf, inf));
    }
    rep(i, 1, ::m) {
        int x = yh();
        int d = x / s[n], m = x % s[n];
        if (m < 0) d--, m += s[n];
        if (!pos.count(m)) puts("-1");
        else {
            auto it = pos[m].upper_bound(mkp(d, inf));
            if (it == pos[m].begin()) {
                puts("-1");
                continue;
            }
            --it;
            int D = d - it->fi;
            int M = it->se;
            cout << D *n + M << hvie;
        }
    }
}
void solve_neg() {
    pos[0].insert(mkp(0, 0));
    rep(i, 1, n) s[i] = -s[i];
    rep(i, 1, n) {
        int d = s[i] / s[n];
        int m = s[i] % s[n];
        if (m < 0) d--, m += s[n];

        auto it = pos[m].lower_bound(mkp(d, -1));
        if (it == pos[m].end() || it->fi != d) pos[m].insert(mkp(d, i));
    }
    for (auto x : pos) {
        pos[x.fi].insert(mkp(inf, inf));
    }
    rep(i, 1, ::m) {
        int x = -yh();
        int d = x / s[n], m = x % s[n];
        if (m < 0) d--, m += s[n];
        if (!pos.count(m)) puts("-1");
        else {
            auto it = pos[m].upper_bound(mkp(d, inf));
            if (it == pos[m].begin()) {
                puts("-1");
                continue;
            }
            --it;
            int D = d - it->fi;
            int M = it->se;
            cout << D *n + M << hvie;
        }
    }
}
void solve_0() {
    map<int, int>vis;
    vis[0] = 0;
    rep(i, 1, n) if (!vis.count(s[i])) vis[s[i]] = i; //,cout<<s[i]<<" - "<<i<<hvie;
    rep(i, 1, m) {
        int x = yh();
        if (!vis.count(x))puts("-1");
        else cout << vis[x] << hvie;
    }
}
signed main() {
    dwn(_, yh(), 1) {
        pos.clear();
        n = yh(), m = yh();
        rep(i, 1, n) s[i] = s[i - 1] + yh();
        // cout<<s[n]<<hvie;
        if (s[n] < 0) solve_neg();
        else if (s[n] > 0) solve();
        else solve_0();
    }
    return 0;
}
/*
1
12 13
 75 -69 -47  8  68 -28 -28 -50  28  42  10 -9
-41
 427
 68
-379
 135
 475
-534
-561
-164
 459
-284
-166
-27

*/
