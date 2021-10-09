#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
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
    return f ? -ret : ret;
}
const int N = 1e5 + 5;
typedef long double db;
db f[N];
db ksm(db x, int p) {
    db ans = 1; for (; p; p >>= 1, x *= x) if (p & 1)ans *= x;
    return ans;
}
db p; int n, m;
db calc(int k) {
    return ((db)n * k + m) / (1 - ksm(p, k));
}
int main() {
    dwn(_, yh(), 1) {
        n = yh(), m = yh(); p = yh();
        p /= 10000; p = 1 - p;
        db ans = 1e100;
        int l = 1, r = 1e7;
        while (l + 9 < r) {
            int m1 = (l * 2 + r) / 3, m2 = (l + r * 2) / 3;
            if (calc(m1) < calc(m2)) {
                r = m2;
            } else l = m1;
        }
        rep(i, l, r) ans = min(ans, calc(i));
        cout << fixed << setprecision(12) << ans << endl;
    }
    return 0;
}