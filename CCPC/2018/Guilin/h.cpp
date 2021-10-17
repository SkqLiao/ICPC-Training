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
const int N = 1e6 + 5;
int n;
int f[N];
char a[N], b[N];

bool check(int now, int i, int t) {
    int tmp = now + (a[i] - 'a' != t) - (b[i] - 'a' != t);
    return abs(tmp) > f[i + 1];
}

int main() {
    rep(_, 1, read()) {
        scanf("%s%s", a + 1, b + 1); n = strlen(a + 1);
        f[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            f[i] = f[i + 1] + (a[i] != b[i]);
        }
        printf("Case %d: ", _);
        int now = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == b[i]) {
                putchar('a');
                continue;
            }
            for (int j = 0; j < 26; ++j) {
                if (!check(now, i, j)) {
                    putchar('a' + j);
                    now += (a[i] - 'a' != j) - (b[i] - 'a' != j);
                    break;
                }
            }
        }
        puts("");
    }
    return 0;
}
