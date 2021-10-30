#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;

bitset<32> a, b;
long long F[32][2][2];

long long dfs(int p, bool f, bool g) {
    if (p < 0) return 1;
    if (F[p][f][g] != -1) return F[p][f][g];
    int ii = a[p] || f;
    int jj = b[p] || g;
    long long ans = 0;
    for (int i = 0; i <= ii; ++i) {
        for (int j = 0; j <= jj; ++j) {
            if (!(i & j)) {
                ans = (ans + dfs(p - 1, f || i < ii, g || j < jj)) % P;
            }
        }
    }
    return F[p][f][g] = ans;
}

void solve(int x, int y) {
    a = x, b = y;
    int hx = log2(x), hy = log2(y);
    long long ans = 0;
    memset(F, -1, sizeof F);
    for (int i = hx; i >= 0; --i) {
        ans = (ans + (i + 1) * dfs(i - 1, i < hx, i <= hy)) % P;
    }
    for (int i = hy; i >= 0; --i) {
        ans = (ans + (i + 1) * dfs(i - 1, i <= hx, i < hy)) % P;
    }
    printf("%lld\n", ans);
}

int main() {
    int x, y, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &x, &y);
        solve(x, y);
    }
    return 0;
}
