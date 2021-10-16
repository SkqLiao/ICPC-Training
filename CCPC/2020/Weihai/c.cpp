#include<bits/stdc++.h>
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
const int maxn = 3e5 + 5;
int n, m;
vector<pii>adj[maxn];
ll sd[maxn][3], cnt[maxn][3];
int mark[maxn][3], tot[3];
ll Ans[3][3];
ll ans = 0;
void dfs(int x, int fa = 0) {
    rep(i, 0, 2) cnt[x][i] += mark[x][i], sd[x][i] = 0;

    for (pii e : adj[x])if (e.fi != fa) {
            int y = e.fi, w = e.se;
            dfs(y, x);
            rep(i, 0, 2) {
                int j = (i + 1) % 3, k = (i + 2) % 3;
                ans += (sd[y][i] + w * cnt[y][i]) * cnt[x][j] + sd[x][j] * cnt[y][i];
                Ans[i][j] += (sd[y][i] + w * cnt[y][i]) * cnt[x][j] + sd[x][j] * cnt[y][i];
                ans += (sd[y][i] + w * cnt[y][i]) * cnt[x][k] + sd[x][k] * cnt[y][i];
                Ans[i][k] += (sd[y][i] + w * cnt[y][i]) * cnt[x][k] + sd[x][k] * cnt[y][i];
            }

            rep(i, 0, 2) {
                sd[x][i] += sd[y][i] + cnt[y][i] * w;
                cnt[x][i] += cnt[y][i];
            }
        }
}
int main() {
    n = yh();
    rep(i, 2, n) {
        int x = yh(), y = yh(), w = yh();
        adj[x].pb(mkp(y, w));
        adj[y].pb(mkp(x, w));
    }
    rep(i, 0, 2) {
        tot[i] = yh();
        rep(j, 1, tot[i]) mark[yh()][i] = 1;
    }
    dfs(1);
    db ret = 0;
    rep(i, 0, 2) {
        rep(j, i + 1, 2) {
            ret += (db)(Ans[i][j] + Ans[j][i]) / tot[i] / tot[j];
        }
    }
    cout << fixed << setprecision(10) << ret / 2 << hvie;
    return 0;
}