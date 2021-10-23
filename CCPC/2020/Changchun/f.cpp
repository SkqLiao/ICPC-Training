#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define yh read
#define hvie '\n'

typedef double db;
typedef long long ll;
typedef pair<int, int> pii;

int read() {
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
const int maxn = 1e5 + 5, maxm = 1e6 + 5;


int sum[maxm][18][2];
int a[maxn];
vector<int>adj[maxn];
int fa[maxn], sz[maxn], son[maxn];
int L[maxn], R[maxn], ord[maxn], sign;
ll ans = 0;
void dfs(int x) {
    L[x] = ++sign;
    ord[sign] = x;
    sz[x] = 1;
    for (int y : adj[x]) {
        if (y != fa[x]) {
            fa[y] = x;
            dfs(y);
            sz[x] += sz[y];
            if (sz[y] > sz[son[x]]) son[x] = y;
        }
    }
    R[x] = sign;
}
void dsu(int x, bool del) {
    for (int y : adj[x])if (y != fa[x] && y != son[x]) {
            dsu(y, 1);
        }
    if (son[x]) dsu(son[x], 0);
//  cout<<"stat "<<x<<":\n";
    for (int y : adj[x])if (y != son[x] && y != fa[x]) {
            rep(t, L[y], R[y]) {
                int j = ord[t];
//          ll tmp=0;
                if ((a[j]^a[x]) > 1e6)continue;
                rep(b, 0, 17) {
                    ans += (1ll << b) * sum[a[j] ^ a[x]][b][((j >> b) & 1) ^ 1];
//              tmp+=(1ll<<b)*sum[a[j]^a[x]][b][((j>>b)&1)^1];
//              cout<<"    "<<y<<','<<j<<" : "<<b<<": "<<sum[a[j]^a[x]][((j>>b)&1]
                }
//          cout<<"   "<<y<<','<<j<<" : "<<tmp<<hvie;
            }
            rep(t, L[y], R[y]) {
                int j = ord[t];
                rep(b, 0, 17) sum[a[j]][b][j >> b & 1]++;
            }
        }
    rep(b, 0, 17) sum[a[x]][b][(x >> b) & 1]++;
    if (del) {
        rep(t, L[x], R[x]) {
            int j = ord[t];
            rep(b, 0, 17) sum[a[j]][b][(j >> b) & 1]--;
        }
    }

}
int n;
int main() {
    n = yh();
    rep(i, 1, n) a[i] = yh();
    rep(i, 1, n - 1) {
        int x = yh(), y = yh();
        adj[x].pb(y); adj[y].pb(x);
    }
    dfs(1);
    dsu(1, 1);
//  rep(i,1,n) rep(b,0,17) cout<<sum[a[i]][b]<<" \n"[b==17];
    cout << ans << hvie;
    return 0;
}
