#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000 + 5;
const int P = 1e9 + 7;

int n, k;
bitset<N> ban[N], cover[N];
ll f[N][N];
ll g[N][N];

void add(ll &x, ll y) {
    x = (x + y) % P;
}

int main() {
    cin >> n >> k;
    for (int i = 1, c, r; i <= k; ++i) {
        cin >> c >> r;
        cover[c - r][c + r] = 1;
        for (int a = 0; a < c - r; ++a) {
            for (int b = c - r + 1; b < c + r; ++b) {
                ban[a][b] = 1;
            }
        }
        for (int a = c - r + 1; a < c + r; ++a) {
            for (int b = c + r + 1; b <= n; ++b) {
                ban[a][b] = 1;
            }
        }
    }
    for (int i = 0; i <= n - 1; ++i) f[i][i + 1] = 1;
    for (int i = 0; i <= n - 2; ++i) {
        if (ban[i][i + 2]) continue;
        if (cover[i][i + 2]) f[i][i + 2] = 1;
        else f[i][i + 2] = 2;
        g[i][i + 2] = 1;
    }
    for (int i = 3; i <= n; ++i) {
        for (int l = 0; l <= n; ++l) {
            int r = l + i;
            if (r > n) break;
            if (ban[l][r]) continue;
            //printf("%d,%d:\n", l, r);
            f[l][r] = f[l][r - 1];
            if (i % 2 == 0) g[l][r] = f[l][r - 1];
            for (int m = r - 2; m >= max(l + 1, r - 10); m -= 2) {
                add(f[l][r], f[l][m] * g[m][r] % P);
                //printf("add %d : %lld * %lld\n", m, f[l][m], g[m][r]);
            }
            if (i % 2 == 0 && i <= 10) {
                for (int m = r - 2; m >= l + 1; m -= 2) {
                    add(g[l][r], f[l][m] * g[m][r] % P);
                }
            }
            if (i % 2 == 0 && !cover[l][r] && i <= 10) f[l][r] = f[l][r] * 2 % P;
            //printf("[%d][%d] f=%lld g=%lld\n", l, r, f[l][r], g[l][r]);
        }
    }
    cout << f[0][n] << endl;
    return 0;
}