#include<bits/stdc++.h>
#define int __int128_t
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
int n, m, k;

signed main() {
    rep(_, 1, yh()) {
        n = yh(), m = yh(), k = yh();
        cout << "Case #" << (ll)_ << ": ";
        if (m < k) {
            int p = n - m + 1;
            int ans = (k - 1) % p;
            while (p < n) ++p, ans = (ans + k) % p;
            cout << (ll)(ans + 1) << hvie;
        } else {
            int p = n - m + 1;
            int ans = (k - 1) % p;
            if (k == 1) {
                cout << (ll)m << hvie; continue;
            }
            while (p < n) {
                int x = (p - ans + k - 2) / (k - 1);
                x = min(x, n - p);
                p += x;
                ans = (ans + x * k) % p;
            }
            cout << (ll)(ans + 1) << hvie;
        }
    }
    return 0;
}
