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
typedef long long ll;
const int maxn = 205, inf = 0x3f3f3f3f;
inline int yh() {
    char c = getchar(); int f = 1, ret = 0;
    while (!isdigit(c)) {
        if (c == '-')f = -1;
        c = getchar();
    }
    while (isdigit(c)) {
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return ret * f;
}
int n, m, k, ans = 0;
int a[maxn][maxn], s1[maxn][maxn], s2[maxn][maxn], cur[maxn], tot[maxn][maxn];
int dp[maxn][maxn][2];
bool b[maxn][maxn];
void cmax(int &x, int y) {
    x = x > y ? x : y;
}
int main() {
    dwn(_, yh(), 1) {
        n = yh(), m = yh(), k = yh();
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        memset(cur, 0, sizeof(cur));
        memset(tot, 0, sizeof(tot));
        memset(dp, 0, sizeof(dp));
        ans = 0;
        if (k == 0) {
            puts("0");
            return 0;
        }
        for (int i = n; i; i--) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = yh();
                char c = getchar(); while (!isupper(c))c = getchar();
                b[i][j] = c == 'Y';
            }
        }
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                if (!b[i][j]) {
                    cur[j] = i;
                    break;
                }
                ans += a[i][j];
            }
        }
        for (int j = 1; j <= m; j++) {
            for (int i = cur[j]; i <= n; i++) {
                s2[j][i] = s1[j][i] = s1[j][i - 1] + a[i][j];
            }
        }
        for (int j = 1; j <= m; j++) {
            tot[j][cur[j]] = 1;
            for (int i = cur[j]; i <= n; i++) {
                int id = i;
                while (b[id + 1][j])id++;
                s2[j][i] += s1[j][id] - s1[j][i];
                tot[j][id + 1] = tot[j][i] + 1;
                i = id;
            }
        }
        for (int j = 0; j <= m; j++)
            dp[j][0][0] = -inf;
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= k; i++) {
                dp[j][i][0] = dp[j - 1][i][0];
                dp[j][i][1] = dp[j - 1][i][1];
                for (int r = 1; r <= n && tot[j][r] <= i; r++)if (!b[r][j]) {
                        cmax(dp[j][i][0], dp[j - 1][i - tot[j][r]][0] + s2[j][r]);
                        cmax(dp[j][i][0], dp[j - 1][i - tot[j][r]][1] + s1[j][r]);
                        cmax(dp[j][i][1], dp[j - 1][i - tot[j][r]][1] + s2[j][r]);
                    }
            }
        }
        cout << ans + dp[m][k][0] << "\n";
    }
    return 0;
}