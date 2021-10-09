#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define yh read
#define int long long
#define hvie '\n'

typedef long long ll;
typedef pair<int, int> pii;
const int LIM = 2048;

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
/*void print(__int128 x)
{
    if(x>9) print(x/10);
    putchar(x%10^48);
}*/

const int N = 1e5 + 5;
void fwt(int *a, int n) {
    for (int d = 1; d < n; d <<= 1) {
        for (int m = (d << 1), i = 0; i < n; i += m) {
            for (int j = 0; j < d; j++) {
                ll x = a[i + j], y = a[i + j + d];
                a[i + j] = x + y;
                a[i + j + d] = x - y;
            }
        }
    }
}
void ifwt(int *a, int n) {
    for (int d = 1; d < n; d <<= 1) {
        for (int m = (d << 1), i = 0; i < n; i += m) {
            for (int j = 0; j < d; j++) {
                int x = a[i + j], y = a[i + j + d];
                a[i + j] = (x + y) / 2;
                a[i + j + d] = (x - y) / 2;
            }
        }
    }
}

int lim[2][3], cnt[3][LIM + 5][LIM + 5];
int sum[3][LIM + 5], tmp[3][LIM + 5], f[LIM + 5][LIM + 5];

signed main() {
    for (int T = read(), cas = 1; cas <= T; ++cas) {
        for (int j = 0; j < 2; ++j) for (int i = 0; i < 3; ++i) lim[j][i] = read();
        memset(cnt, 0, sizeof(cnt)); memset(sum, 0, sizeof(sum)); memset(f, 0, sizeof(f));
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j <= lim[0][i]; ++j) for (int k = 0; k <= lim[1][i]; ++k) {
                    ++cnt[i][abs(j - k)][j ^ k];
                }
        }
        for (int M = 0; M < LIM; ++M) {
            for (int j = 0; j < 3; ++j)
                for (int i = 0; i < LIM; ++i)
                    sum[j][i] += cnt[j][M][i], tmp[j][i] = sum[j][i];
            for (int j = 0; j < 3; ++j) fwt(tmp[j], LIM);
            for (int j = 1; j < 3; ++j)
                for (int i = 0; i < LIM; ++i)
                    tmp[0][i] *= tmp[j][i];
            ifwt(tmp[0], LIM);
            for (int i = 0; i < LIM; ++i) f[M][i] += tmp[0][i];
        }
        unsigned long long ans = 0;
        for (int M = 0; M < LIM; ++M) {
            for (int i = 0; i < LIM; ++i) ans += (f[M][i] - (M > 0 ? f[M - 1][i] : 0)) * (M ^ i);
        }
        //printf("Case #%lld",cas);printf(": ");puts("");
        printf("Case #%lld: %llu\n", cas, ans);
    }
    return 0;
}
