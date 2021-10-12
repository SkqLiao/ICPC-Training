#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define dwn(i,a,b) for(int i=(a),i##end=(b);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define hvie '\n'

int yh() {
    int ret = 0, f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        ret = ret * 10 + (c ^ 48);
        c = getchar();
    }
    return f ? -ret : ret;
}

#define int long long
const int N = 1e5 + 5;

int n, t;

int a[N], b[N];
int co[50] = {0, 1, -1, 2, -6, 24};
int fac[50] = {1, 1, 2, 6, 24, 120};
int ksm(int x, int k) {
    int ans = 1;
    rep(i, 1, k)ans *= x;
    return ans;
}
signed main() {
    n = yh(), t = yh();

    if (t == 0) {
        return cout << 0, 0;
    }

    rep(i, 1, n) {
        a[i] = yh(), b[i] = yh();
    }
    rep(i, 1, t) {
        int sum = 0;
        rep(j, 1, n) {
            sum += a[j] * ksm(b[j], i) * co[i];
        }
        if (sum != 0) {
            if (t == i) {
                int g = __gcd(sum, fac[t]);
                if (abs(fac[t] / g) != 1) {
                    if (fac[t]*sum < 0) cout << '-' << abs(sum / g) << '/' << abs(fac[t]) / g;
                    else cout << abs(sum / g) << '/' << abs(fac[t] / g);
                } else {
                    cout << sum / g;
                }
            } else {
                cout << "infinity";
            }
            return 0;
        }
    }
    cout << 0;
    return 0;
}
