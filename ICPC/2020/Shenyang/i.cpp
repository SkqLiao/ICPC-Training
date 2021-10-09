#include<bits/stdc++.h>
#define int long long
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
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
    return ret;
}
const int maxn = 1e5 + 5;
int f(int a, int b, int c, int n) {
    if (a == 0) return ((b / c) * (n + 1));
    if (a >= c || b >= c) {
        return f(a % c, b % c, c, n) + (a / c) * (n + 1) * n / 2 + (b / c) * (n + 1);
    }
    int m = (a * n + b) / c;
    int v = f(c, c - b - 1, a, m - 1);
    return n * m - v;
}
int bf(int a, int b, int c, int n) {
    int ans = 0;
    for (int i = 0; i <= n; i++) ans += (a * i + b) / c;
    return ans;
}
int H, M, A;
int cl(int x, int y) {
    return (x - 1) / y + 1;
}

int F(int H, int M, int A) {
    cout << H << " " << M << " " << A << endl;
    H--;
    int ret = 0;
    rep(i, 0, H) {
        int r = min((A + i * M) / H, M - 1);
        int l = max(cl(-A + i * M, H), 0ll);
        cout << l << " " << r << " " << endl;
        ret += max(r - l + 1, 0ll);
    }
    cout << ": " << ret << endl;
    return ret;
}
signed main() {
    H = yh(), M = yh(), A = yh();
    if (2 * A == H * M) {
        cout << H *M << endl; return 0;
    }
    int g = __gcd(H - 1, H * M);
    cout << g*(2 * (A / g) + 1) << endl;
    return 0;
}