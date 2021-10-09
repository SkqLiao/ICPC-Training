#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),i##ss=(b);i<=i##ss;i++)
#define dwn(i,a,b) for(int i=(a),i##ss=(b);i>=i##ss;i--)
#define deb(x) cerr<<(#x)<<":"<<(x)<<'\n'
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define hvie '\n'
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int yh() {
    int ret = 0; bool f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == EOF)return -1;
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c))ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
    return f ? -ret : ret;
}
const int maxn = 2e5 + 5;
int n, m;
int a[maxn];
struct seg {
    int min, mnn, sec;
    int cnt[31];
    int nim;
} s[maxn * 4];
#define ls (v<<1)
#define rs (v<<1|1)
#define mid ((l+r)>>1)
void push_up(int v) {
    rep(i, 0, 30) s[v].cnt[i] = s[ls].cnt[i] + s[rs].cnt[i];
    s[v].nim = s[ls].nim ^ s[rs].nim;
    if (s[ls].min < s[rs].min) {
        s[v].min = s[ls].min;
        s[v].mnn = s[ls].mnn;
        s[v].sec = min(s[ls].sec, s[rs].min);
    } else if (s[rs].min < s[ls].min) {
        s[v].min = s[rs].min;
        s[v].mnn = s[rs].mnn;
        s[v].sec = min(s[rs].sec, s[ls].min);
    } else {
        s[v].min = s[ls].min;
        s[v].mnn = s[ls].mnn + s[rs].mnn;
        s[v].sec = min(s[ls].sec, s[rs].sec);
    }
}
void change_cnt(int v, int key, int mdf) {
    rep(i, 0, 30)if ((key >> i) & 1)s[v].cnt[i] += mdf;
}
void build(int v, int l, int r) {
    if (l == r) {
        s[v].min = a[l]; s[v].mnn = 1; s[v].sec = 0x7fffffff;
        // cout<<l<<" "<<s[v].min<<endl;
        s[v].nim = a[l];
        change_cnt(v, a[l], 1);
        return;
    }
    build(ls, l, mid); build(rs, mid + 1, r);
    push_up(v);
}
void cmax(int v, int val) {
    change_cnt(v, s[v].min, -s[v].mnn);
    change_cnt(v,   val, s[v].mnn);
    if (s[v].mnn & 1) {
        s[v].nim ^= s[v].min ^ val;
    }
    s[v].min = val;
}
void push_down(int v) {
    if (s[v].min > s[ls].min)cmax(ls, s[v].min);
    if (s[v].min > s[rs].min)cmax(rs, s[v].min);
}
void mdf(int v, int l, int r, int al, int ar, int val) {
    // cout<<v<<" "<<l<<" "<<r<<" : "<<" "<<s[v].nim<<" "<<" "<<s[v].mnn<<" "<<s[v].sec<<" | "<<al<<" "<<ar<<" "<<val<<"\n";
    // cout<<s[v].min<<endl;
    if (s[v].min >= val) return;
    if (al <= l && ar >= r && s[v].sec > val) return cmax(v, val);
    push_down(v);
    if (al <= mid) mdf(ls, l, mid, al, ar, val);
    if (ar > mid) mdf(rs, mid + 1, r, al, ar, val);
    push_up(v);
}
seg ans;
void query(int v, int l, int r, int al, int ar) {
    // cout<<l<<" "<<r<<" "<<al<<" "<<ar<<" "<<s[v].nim<<hvie;
    if (al <= l && ar >= r) {
        ans.nim ^= s[v].nim;
        rep(i, 0, 30) ans.cnt[i] += s[v].cnt[i];
        return;
    }
    push_down(v);
    if (al <= mid) query(ls, l, mid, al, ar);
    if (ar > mid) query(rs, mid + 1, r, al, ar);
}
// void dfs(int v,int l,int r){
//  cout<<l<<" "<<r<<" : "<<s[v].min<<"!\n";
//  if(l==r)return;dfs(ls,l,mid);dfs(rs,mid+1,r);
// }
int main() {
#ifdef van
    freopen("my.in", "r", stdin);
#endif
    n = yh(), m = yh();
    rep(i, 1, n) a[i] = yh();
    build(1, 1, n);
    rep(_, 1, m) {
        int op = yh(), l = yh(), r = yh(), k = yh();
        if (op == 1) {
            mdf(1, 1, n, l, r, k);
        } else {
            ans.nim = 0; rep(i, 0, 30) ans.cnt[i] = 0;
            query(1, 1, n, l, r);
            int t = ans.nim ^ k, i = 30;
            if (t == 0) {
                puts("0");
                continue;
            }
            for (; i >= 0; i--)if ((t >> i) & 1)break;
            // cout<<ans.nim<<" "<<t<<" "<<i<<endl;
            cout << ans.cnt[i] + (k >> i & 1) << hvie;
            // exit(0);
        }
    }
    return 0;
}