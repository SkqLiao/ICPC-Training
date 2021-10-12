#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l,i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=l,i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
#define hvie '\n'
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, inf = 0x3f3f3f3f;
int read() {
    int ret = 0, f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        ret = ret * 10 + (c ^ 48);
        c = getchar();
    }
    return f ? -ret : ret;
}
int n, Q;
vector<int>G[N], ans;
int a[N];

int main() {
    //freopen("k.out","w",stdout);
    int TT = read();
    rep(cas, 1, TT) {
        printf("Case #%d: \n", cas);
        n = read(); Q = read();
        for (int i = 1; i <= n; ++i) G[i].clear();
        for (int i = 1; i <= n; ++i) {
            int t = read();
            for (int j = 0; j < t; ++j) G[i].pb(read());
        }
        while (Q--) {
            int S = read(), m = read();
            for (int i = 1; i <= m; ++i) a[i] = read();
            ans.clear();

            bool fg = 1;
            for (int i = 1; i <= m; ++i) {
                if (G[S].size() < a[i]) {
                    fg = 0;
                    break;
                }
                S = G[S][a[i] - 1];
            }
            if (fg) printf("%d", S);
            else printf("Packet Loss");
            if (Q) puts("");
        }
        if (cas < TT) puts("");
    }
    return 0;
}