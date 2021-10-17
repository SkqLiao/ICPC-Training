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
const int N = 526666, mod = 998244353, G = 3;

namespace Math {
int inv[N];
int upm(int x) {
    return x >= mod ? x - mod : (x < 0 ? x + mod : x);
}
void up(int &x, int y) {
    x = upm(x + y);
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int qpow(int x, int y) {
    int ret = 1;
    for (; y; y >>= 1, x = mul(x, x))if (y & 1)ret = mul(ret, x);
    return ret;
}
int getinv(int x) {
    return qpow(x, mod - 2);
}
void initinv() {
    inv[1] = 1;
    for (int i = 2; i < N; ++i) inv[i] = mod - mul(mod / i, inv[mod % i]);
}
}
using namespace Math;


namespace Poly {
int m, L, rev[N];
void ntt(int *a, int n, int f) {
    for (int i = 0; i < n; ++i) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int i = 1; i < n; i <<= 1) {
        int wn = qpow(G, (mod - 1) / (i << 1));
        if (!~f) wn = getinv(wn);
        for (int j = 0; j < n; j += i << 1) {
            int w = 1;
            for (int k = 0; k < i; ++k, w = mul(w, wn)) {
                int x = a[j + k], y = mul(w, a[i + j + k]);
                a[j + k] = upm(x + y); a[i + j + k] = upm(x - y);
            }
        }
    }
    if (!~f) for (int i = 0, inv = getinv(n); i < n; ++i) a[i] = mul(a[i], inv);
}
void reget(int n) {
    for (m = 1, L = 0; m <= n; m <<= 1, ++L);
    for (int i = 0; i < m; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
}
void polymul(int *a, int *b, int *c) {
    static int A[N], B[N];
    copy(a, a + m, A); copy(b, b + m, B);
    ntt(A, m, 1); ntt(B, m, 1);
    for (int i = 0; i < m; ++i) c[i] = mul(A[i], B[i]);
    ntt(c, m, -1);
    fill(A, A + m, 0); fill(B, B + m, 0);
}
void polymult(int *a, int *b, int *c, int dega, int degb) {
    reget(dega + degb); polymul(a, b, c);
}
void polyder(int *a, int deg) {
    for (int i = 0; i < deg - 1; ++i) a[i] = mul(a[i + 1], i + 1);
    a[deg - 1] = 0;
}
void polyint(int *a, int deg) {
    for (int i = deg - 1; i; --i) a[i] = mul(a[i - 1], inv[i]);
    a[0] = 0;
}
void polyinv(int *a, int *b, int deg) {
    if (deg == 1) {
        b[0] = getinv(a[0]);
        return;
    }
    polyinv(a, b, (deg + 1) >> 1);
    static int A[N], B[N];
    reget(deg * 2); copy(a, a + deg, A); fill(A + deg, A + m, 0); copy(b, b + deg, B); fill(B + deg, B + m, 0);
    ntt(A, m, 1); ntt(B, m, 1);
    for (int i = 0; i < m; ++i) A[i] = mul(A[i], mul(B[i], B[i]));
    ntt(A, m, -1);
    for (int i = 0; i < deg; ++i) b[i] = upm(mul(2, b[i]) - A[i]);
    fill(A, A + m, 0); fill(B, B + m, 0);
}
void polyln(int *a, int *b, int deg) {
    static int A[N], B[N];
    polyinv(a, A, deg); copy(a, a + deg, B); polyder(B, deg);
    reget(deg * 2); polymul(A, B, A);
    for (int i = 0; i < deg; ++i) b[i] = A[i];
    polyint(b, deg);
    fill(A, A + m, 0); fill(B, B + m, 0);
}
void polyexp(int *a, int *b, int deg) {
    if (deg == 1) {
        b[0] = 1;
        return;
    }
    polyexp(a, b, (deg + 1) >> 1);
    static int A[N], B[N];
    fill(A, A + deg * 2, 0); fill(B, B + deg * 2, 0);
    polyln(b, B, deg);
    for (int i = 0; i < deg; ++i) B[i] = upm(mod + (!i) - B[i] + a[i]);
    copy(b, b + deg, A); reget(deg * 2); polymul(A, B, A);
    for (int i = 0; i < deg; ++i) b[i] = A[i];
    fill(A, A + m, 0); fill(B, B + m, 0);
}
void polypow(int *a, int *b, int deg, int K) {
    static int A[N];
    polyln(a, A, deg);
    for (int i = 0; i < deg; ++i) A[i] = mul(A[i], K);
    polyexp(A, b, deg);
    fill(A, A + m, 0);
}
}
using namespace Poly;


int n, lim, k;
int a[N], b[N], c[N], d[N], ans[N];

int main() {
    initinv();
    rep(_, 1, read()) {
        n = read(); lim = read(); k = read();
        for (int i = 0; i < n; ++i) a[i] = read();
        reverse(a, a + n);

        for (int i = 0; i < lim; ++i) b[i] = 1;
        for (int i = lim; i < n; ++i) b[i] = 0;
        polypow(b, c, n, k);
        polymult(a, c, ans, n, n);

        printf("Case %d: ", _);
        //for(int i=0;i<20;++i) printf("%d ",c[i]);
        //puts("");
        for (int i = 0; i < n; ++i) printf("%d ", (ans[n - i - 1] % mod + mod) % mod);
        puts("");
        for (int i = 0; i < n * 4; ++i) a[i] = b[i] = c[i] = ans[i] = 0;
    }
    return 0;
}
