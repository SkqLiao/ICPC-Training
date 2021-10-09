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
const int maxn = 1e6 + 5;
int n, m;

vector<int>conditions[maxn];
int tot;
int siz[maxn];
pii conseq[maxn];
char s[maxn], t[maxn];

queue<int>al;
int ans[maxn];
void expand(int x) {
    for (int i : conditions[x]) {
        siz[i]--;
        if (siz[i] == 0) {
            pii p = conseq[i];
            if (ans[p.fi] != -1) {
                if (ans[p.fi] != p.se) puts("conflict"), exit(0);
            } else {
                ans[p.fi] = p.se;
                if (p.se == 1)al.push(p.fi);
            }
        }
    }
}
void input() {
    char c; int ret = 0; bool res = 1;
    vector<int>vec;
    for (c = getchar(); c != '\n' && c != '\r' && c != EOF; c = getchar()) {
        if (isdigit(c)) ret = ret * 10 + (c - '0');
        else if (c == '!') res = 0;
        else if (ret != 0) {
            vec.pb(ret);
            ret = 0;
        }
    }
    if (!vec.size()) {
        al.push(ret);
        if (ans[ret] != -1 && ans[ret] != res) puts("conflict"), exit(0);
        ans[ret] = res;
    } else {
        siz[++tot] = vec.size();
        for (int i : vec) conditions[i].pb(tot);
        conseq[tot] = mkp(ret, res);
    }
}
int main() {
    // freopen("my.in","r",stdin);
    n = yh(), m = yh();
    memset(ans, -1, sizeof(ans));
    rep(i, 1, n)input();
    while (al.size()) {
        int x = al.front(); al.pop();
        expand(x);
    }
    rep(i, 1, m) {
        if (ans[i] == -1) {
            cout << "F";
        } else cout << (ans[i] ? "T" : "F");
    }
    cout << hvie;
    return 0;
}