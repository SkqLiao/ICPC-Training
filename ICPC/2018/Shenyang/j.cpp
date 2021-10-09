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

int n, k, mod;

int calc(int n, int mod) {
    int ret = 1;
    for (int i = 1; i <= n; ++i) ret = ret * i % mod;
    return ret;
}

signed main() {
    for (int tt = read(), T = 1; T <= tt; ++T) {
        n = read(), k = read(), mod = read();
        if (n - 1 <= k) printf("Case #%lld: %lld\n", T, calc(n, mod));
        else {
            int fir = calc(k, mod), dec = k * fir % mod, dectwo = 2 * fir % mod;
            (fir += dec) %= mod; (dec += dectwo) %= mod; (fir += dec) %= mod; (dec += dectwo) %= mod;
            for (int i = 4; i <= n - k + 1; ++i) {
                //printf("%lld ",fir);
                fir += dec; fir %= mod;
                dec += dectwo; dec %= mod;
            }
            printf("Case #%lld: %lld\n", T, fir);
        }
    }
    return 0;
}

/*
    1
    2     2
    5     6     6
   10    14    24    24
   17    26    54   120   120
   26    42    96   264   720   720
   37    62   150   456  1560  5040  5040
   50    86   216   696  2640 10800 40320 40320
   65   114   294   984  3960 18000 85680 362880 362880

*/

