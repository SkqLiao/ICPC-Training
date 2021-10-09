#include<bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
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
    return ret;
}
const int maxn = 3e6 + 5, maxs = 1 << 20 | 7;
int n, m, k;
int a[maxn], cnt[maxn];
int f[maxn], g[maxn], h[maxn];
void fwt(int *a, int n) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = (x + y);
                a[i + j + d] = (x - y);
            }
}
void ifwt(int *a, int n) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = (x + y) / 2;
                a[i + j + d] = (x - y) / 2;
            }
}
int N;
char s[25];
signed main() {
    n = yh(), m = yh(), k = yh();
    rep(i, 1, n) {
        scanf("%s", s);
        for (int j = 0; s[j]; j++) a[i] = (a[i] << 1) | (s[j] - 'A');
        cnt[a[i]]++;
    }
    N = 1 << m;
    fwt(cnt, N);
    rep(i, 0, N - 1) f[i] = cnt[i] * cnt[i];
    ifwt(f, N);
    rep(i, 1, N - 1) h[i] = f[i] / 2;
    h[0] = (f[0] - n) / 2;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < N; i++) {
            if ((i >> j) & 1)h[i] += h[i ^ (1 << j)];
        }
    }
    int ans = 0;
    rep(i, 1, N - 1) {
        g[i] = n * (n - 1) / 2 - h[(N - 1)^i];
        if (g[i] >= k) ans++;
    }
    cout << ans << hvie;

    return 0;
}