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
const int N = 3005, mod = 1e9 + 7;
int a[N], pwc[N], cnt[N], C[N][N];
char s[N];
int n, c;

int upm(int x) {
    return (x % mod + mod) % mod;
}
void up(int &x, int y) {
    x = upm(x + y);
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}

signed main() {
    scanf("%s", s + 1); n = strlen(s + 1); c = yh();
    pwc[0] = 1;
    for (int i = 1; i < N; ++i) pwc[i] = mul(pwc[i - 1], c);
    for (int i = 0; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) C[i][j] = upm(C[i - 1][j - 1] + C[i - 1][j]);
    }

    for (int i = 1, now = 0; i <= n; ++i) {
        if (s[i] == '1') {
            for (int j = 0; j <= n - i; ++j) {
                up(cnt[j + now], C[n - i][j]);
            }
            ++now;
        }
        if (i == n) up(cnt[now], 1);
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) up(ans, mul(cnt[i], pwc[i]));
    printf("%lld\n", ans % mod);


    return 0;
}
