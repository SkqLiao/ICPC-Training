#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l,i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=l,i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
#define hvie '\n'
typedef long long ll;
typedef double db;
const int maxn = 1e5 + 10, inf = 0x3f3f3f3f;

int n, m;
set<int>p[maxn];
set<int>f[maxn];
db x[maxn], y[maxn], z[maxn];
void print(set<int> &s) {
    if (s.empty())return cout << "[]", void();
    cout << "[";
    auto i = s.begin(); cout << *i;
    for (i++; i != s.end(); i++) {
        cout << ',' << *i;
    }
    cout << ']';
}
int main() {
    // freopen("my.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 1, n) {
        int id;
        cin >> id;
        cin >> x[id] >> y[id] >> z[id];
    }
    rep(i, 1, m) {
        int I, fig; cin >> I >> fig;
        int x, y, z;
        if (fig == 102) {
            cin >> x >> y;
            p[x].insert(y);
            p[y].insert(x);
            f[x].insert(I);
            f[y].insert(I);
        } else {
            cin >> x >> y >> z;
            p[x].insert(y); p[x].insert(z);
            p[y].insert(x); p[y].insert(z);
            p[z].insert(x); p[z].insert(y);
            f[x].insert(I); f[y].insert(I); f[z].insert(I);
        }
    }
    int RES; cin >> RES;
    rep(_, 1, RES) {
        int x; cin >> x;
        cout << x << hvie;
        print(p[x]); cout << hvie;
        print(f[x]); if (_ < RES)cout << hvie;
    }
    return 0;
}