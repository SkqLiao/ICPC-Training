#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define dwn(i,a,b) for(int i=(a),i##end=(b);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
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
        ret = ret * 10 + (c ^ 48);
        c = getchar();
    }
    return f ? -ret : ret;
}
const int N = 1e5 + 5, mod = 998244353;
int n, m;

int cnt[30][N << 2];
int len[N << 2];
ll sum[N << 2];
bool isleaf[N << 2];
bool cov[30][N << 2];
ll tag[N << 2];

#define ls (v<<1)
#define rs (v<<1|1)
#define mid ((l+r)>>1)
bool __vis[1000];
int p[100], tot = 0, id[101];
void push_up(int v) {
    sum[v] = (sum[ls] + sum[rs]) % mod;
    rep(i, 1, tot) cnt[i][v] = (cnt[i][ls] + cnt[i][rs]);
}
void push_up(int v, int i) {
    sum[v] = (sum[ls] + sum[rs]) % mod;
    cnt[i][v] = (cnt[i][ls] + cnt[i][rs]);
}
// void COV(int v,int i){
//  cout<<">>";
//  cov[i][v]=1;
//  cnt[i][v]=len[v];
//  cout<<i<<" "<<cnt[i][v]<<" "<<len[v]<< " "<<sum[v]<<hvie;
// }
void MUL(int v, int P) {
    sum[v] = sum[v] * P % mod;
    tag[v] = tag[v] * P % mod;
}
void push_down(int v) {
    if (tag[v] != 1) {
        MUL(ls, tag[v]);
        MUL(rs, tag[v]);
        tag[v] = 1;
    }
}
void BF(int v, int i, int l, int r) {
    if (cnt[i][v] == len[v]) {
        MUL(v, p[i]); return;
    }
    if (isleaf[v]) {
        sum[v] = cnt[i][v] ? sum[v] * p[i] % mod : sum[v] * (p[i] - 1) % mod;
        cnt[i][v] = len[v];
        return;
    }
    push_down(v);
    BF(ls, i, l, mid); BF(rs, i, mid + 1, r);
    push_up(v, i);
}
vector<int>prms;
void cover(int v, int l, int r, int al, int ar) {
    if (al <= l && ar >= r) {
        for (int t : prms) {
            BF(v, id[t], l, r);
        }
        return;
    }
    push_down(v);
    if (al <= mid) cover(ls, l, mid, al, ar);
    if (ar > mid) cover(rs, mid + 1, r, al, ar);
    push_up(v);
}
ll ans = 0;
void ask(int v, int l, int r, int al, int ar) {
    if (al <= l && ar >= r) {
        return (ans += sum[v]) %= mod, void();
    }
    push_down(v);
    if (al <= mid) ask(ls, l, mid, al, ar);
    if (ar > mid) ask(rs, mid + 1, r, al, ar);
}
void build(int v, int l, int r) {
    len[v] = r - l + 1;
    tag[v] = 1;
    if (l == r) {
        isleaf[v] = 1;
        int x = read();
        int phi = x;
        for (int i = 1; i <= tot && p[i] <= x; i++)if (x % p[i] == 0) {
                phi = phi / p[i] * (p[i] - 1);
                while (x % p[i] == 0) {
                    cnt[i][v] = 1;
                    x /= p[i];
                }
            }
        sum[v] = phi;
        return;
    }
    build(ls, l, mid); build(rs, mid + 1, r);
    push_up(v);
}

int main() {
    for (int i = 2; i <= 100; i++) {
        if (!__vis[i]) {
            p[++tot] = i;
            id[i] = tot;
            for (int j = i * 2; j <= 100; j += i) __vis[j] = 1;
        }
    }
    n = read(), m = read();
    build(1, 1, n);
    int op, l, r, x;
    vector<int>rec;
    rep(i, 1, m) {
        op = read(), l = read(), r = read();
        if (op == 0) {
            x = read(); prms.clear();
            for (int i = 1; i <= tot && p[i] <= x; i++)while (x % p[i] == 0)prms.pb(p[i]), x /= p[i];
            cover(1, 1, n, l, r);
        } else {
            ans = 0;
            ask(1, 1, n, l, r);
            rec.pb(ans);
        }
    }
    if (rec.size()) {
        cout << rec[0];
        rep(i, 1, rec.size() - 1)cout << "\n" << rec[i];
    }
    return 0;
}
