#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l,i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=l,i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
#define hvie '\n'
typedef long long ll;
typedef double db;
const int inf = 0x3f3f3f3f, N = 40, M = 4e6 + 10;
int read() {
    int ret = 0, f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = 1;
        if (c == EOF)return -inf;
        c = getchar();
    }
    while (isdigit(c)) {
        ret = ret * 10 + (c ^ 48);
        c = getchar();
    }
    return f ? -ret : ret;
}

ll fc[40], nofind;

struct Trie {
    int cnt, nxt[M][2];
    ll goal[M];
    void init() {
        memset(goal, -1, sizeof(goal));
        cnt = 1;
    }
    void insert(ll x, ll y, int len) {
        int now = 1;
        for (int i = 31; i >= len; --i) {
            int p = (x >> i) & 1;
            if (!nxt[now][p]) nxt[now][p] = ++cnt;
            now = nxt[now][p];
        }
        goal[now] = y;
    }
    ll query(ll x) {
        ll ret = -1;
        int now = 1;
        for (int i = 31; i >= 0; --i) {
            int p = (x >> i) & 1;
            if (!nxt[now][p]) break;
            now = nxt[now][p];
            if (goal[now] != -1) ret = goal[now];
        }
        return ret == -1 ? nofind : ret;
    }
} T;

const long long BIT[] = {4278190080ll, 16711680, 65280, 255};

void print(ll x) {
    printf("%lld.%lld.%lld.%lld", (BIT[0]&x) >> 24, (BIT[1]&x) >> 16, (BIT[2]&x) >> 8, BIT[3]&x);
}

int n, Q;

int main() {
    T.init();
    fc[0] = 1;
    for (int i = 1; i < 35; ++i) fc[i] = fc[i - 1] << 1;
    n = read();
    for (int i = 1; i <= n; ++i) {
        ll x = 0, mask = (1ll << 32) - 1, y = 0;
        for (int j = 0; j < 4; ++j) x <<= 8, x += read();
        int t = 32 - read();
        mask ^= (1ll << t) - 1;
        for (int j = 0; j < 4; ++j) y <<= 8, y += read();
        if (!x) nofind = y;
        else T.insert(x & mask, y, t);
    }
    Q = read();
    while (Q--) {
        ll x = 0;
        for (int j = 0; j < 4; ++j) x <<= 8, x += read();
        ll ans = T.query(x);
        print(ans);
        if (Q) puts("");
    }
    return 0;
}
