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
#define db double
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
const int N = 30000 + 5;
bool vis[N];
int tot, prm[N];
vector<pair<int, double>> f[N];
db v[N];
db g[N], g2[N];
int main() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prm[++tot] = i, v[tot] = log(i);
        for (int j = i << 1; j < N; j += i) vis[j] = 1;
    }
    for (int i = 1; i <= tot; ++i) {
        int x = prm[i];
        double y = v[i];
        for (int j = 1; x <= 30000; ++j) {
            f[i].push_back({x, y});
            x *= prm[i];
            y += v[i];
        }
    }
    for (int i = 1; i <= tot; ++i) {
        memcpy(g2, g, sizeof g);
        for (int j = 1; j <= 30000; ++j) {
            for (auto a : f[i]) {
                if (j >= a.first) g2[j] = max(g2[j], g[j - a.first] + a.second);
            }
        }
        memcpy(g, g2, sizeof g);
    }
    dwn(_, yh(), 1) {
        cout << fixed << setprecision(12) << g[yh()] << hvie;
    }
    return 0;
}