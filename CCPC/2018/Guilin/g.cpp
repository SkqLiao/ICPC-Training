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
const int N = 1e5 + 5;
int a[N];
int g, n;
ll calc(ll g, ll x) {
    ll ans = 0x3f3f3f3f3f3f3f3fll;
    for (int i = 1; i * i <= g; i++)if (g % i == 0) {
            ll d = i, k = (x + d - 1) / d;
            if (d > 1) ans = min(ans, k * d - x);
            d = g / i, k = (x + d - 1) / d;
            if (d > 1) ans = min(ans, k * d - x);
        }
    return ans;
}
int main() {
    rep(_, 1, yh()) {
        n = yh(); rep(i, 1, n) a[i] = yh();
        cout << "Case " << _ << ": ";
        if (n == 1) {
            cout << (a[1] == 1) << hvie; continue;
        }
        sort(a + 1, a + 1 + n);
        g = 0;
        rep(i, 2, n) g = __gcd(a[i] - a[1], g);
        if (g == 0) {
            cout << (a[1] == 1) << hvie;
        } else if (g == 1) {
            puts("-1");
        } else {
            if (__gcd(g, a[1]) > 1) {
                puts("0");
                continue;
            }
            ll ans = calc(g, a[1]);
            if (ans == 0x3f3f3f3f3f3f3f3fll) puts("-1");
            else cout << ans << hvie;
        }
    }
    return 0;
}
