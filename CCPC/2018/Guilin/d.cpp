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

typedef long long ll;
typedef pair<int, int> pii;

ll read() {
    ll ret = 0, f = 0; char c = getchar();
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
bool issqr(ll x) {
    ll s = sqrt(x);
    return s * s == x;
}
int main() {
    rep(_, 1, yh()) {
        ll x = yh();
        bool ok = 0;
        for (ll i = 1; i <= 1000000; i++)if (x % i == 0) {
                if (x / i > 1 && issqr(x / i)) {

                    ok = 1; break;
                } else if (i > 1 &&   x % (i * i) == 0) {
                    ok = 1;
                    break;
                }
            }
        puts(ok ? "yes" : "no");
    }
    return 0;
}