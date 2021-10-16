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
const int N = 105, M = (1 << 16) | 233, K = 20;

int n, m, all;
int siz[M], fc[K], a[K], sum[M];
db f[N][M];//f[i][S]=shot i times,possiblility of die S
db g[N][M];//g[i][S]=shot i times in S,no death
db C[N][N];

db binom(int n, int m) {
    if (n < m) return 0;
    return C[n][m];
}

db choose(int x, int y) {
    return binom(x + y - 1, x - 1);
}

void dfs(int x, int S) { //las state=S,now check x
    if (x >= n) return;
    for (int i = 0; i <= m; ++i) { //tot shot i
        //printf("%d %d %d %d\n",i,x,S,S^fc[x]);
        for (int j = 0; j < min(i + 1, a[x]); ++j)
            g[i][S ^ fc[x]] += g[i - j][S] * choose(i - j + 1, j);
    }
    dfs(x + 1, S);
    dfs(x + 1, S ^ fc[x]);
}


void init() {
    fc[0] = 1;
    for (int i = 1; i < K; ++i) fc[i] = fc[i - 1] << 1;
    for (int i = 0; i < N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    for (int i = 1; i < M; ++i) siz[i] = siz[i >> 1] + (i & 1);

    n = read(); m = read();
    for (int i = 0; i < n; ++i) a[i] = read();

    for (int i = 0; i < fc[n]; ++i) for (int j = 0; j < n; ++j)
            if (i & fc[j]) sum[i] += a[j];
    all = fc[n] - 1;
}
void solve() {
    f[0][0] = 1;
    for (int S = 0; S < all; ++S) {
        for (int i = 0; i < m; ++i) {
            if (i + 1 >= sum[S]) f[i + 1][S] += f[i][S] / siz[all ^ S];
            if (i < sum[S]) continue;
            for (int j = 0; j < n; ++j) {
                if (!((all ^ S) & (fc[j])) || i + 1 < sum[S ^ fc[j]]) continue;
                f[i + 1][S ^ fc[j]] += f[i][S] * binom(i - sum[S], a[j] - 1) / siz[all ^ S];
            }

        }
    }

    g[0][0] = 1; dfs(0, 0);
    /*for(int S=0;S<=all;++S)
    {
        printf("%d : ",S);
        for(int i=0;i<=m;++i) printf("%lf ",g[i][S]);
        puts("");
    }
    printf("cgh:%lf\n",g[0][0]);
    for(int S=0;S<=all;++S)
    {
        printf("%d : ",S);
        for(int i=0;i<=m;++i) printf("%lf ",f[i][S]);
        puts("");
    }*/
    db ans = 0;
    for (int S = 0; S <= all; ++S) {
        //printf("%d %lf\n",S,f[m][S]);
        if (m >= sum[S])
            ans += f[m][S] * g[m - sum[S]][all ^ S] * siz[S];
    }
    printf("%.10lf\n", ans);
}

int main() {
    init(); solve();
    return 0;
}