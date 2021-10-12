#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l,i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=l,i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
#define hvie '\n'
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, inf = 0x3f3f3f3f;
int read() {
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
int n, m;
db dis(db x, db y) {
    return sqrt(x * x + y * y);
}
int main() {
    int TT = read();
    rep(cas, 1, TT) {
        db a = read(), b = read(), r = read();
        cout << "Case #" << cas << ": ";
        if (b <= r) {
            cout << fixed << setprecision(2) << 2 * a - r;
        } else {
            db X = a, Y = b - r;
            cout << fixed << setprecision(2) << dis(X, Y) * 2 - r;
        }
        if (cas < TT)cout << hvie;

    }
    return 0;
}