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
typedef long long ll;
typedef unsigned long long ull;
typedef long long db;
typedef pair<db, db> pii;
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
const int maxn = 3e5 + 5;
const db inf = 1e18;
//int n,m;
db x0, y0, x1, x2, y1, y2;
db a, b, c;
db F(db x) {
    return a * x * x + b * x + c - y0;
}
int main() {
    dwn(_, yh(), 1) {
        a = yh(), b = yh(), c = yh();
        x0 = yh(), x1 = yh(); x2 = 2 * x1 - x0;
        y0 = yh(); y1 = yh(), y2 = yh();
        db delta = b * b - 4 * a * (c - y0);
        if (delta <= 0) {
            puts("No");
            continue;
        }
        // cout<<F(x0)<<" "<<F(x2)<<endl;
        if (F(x0) <= 0) {
            puts("No");
            continue;
        }
        if (F(x2) >= 0) {
            puts("No");
            continue;
        }
        db f = F(x1);
        // cerr<<f<<endl;
        if (f == 0) {
            puts("No"); continue;
        }
        if (f <= y2 - y0) {
            puts("Yes"); continue;
        } else puts("No");
    }
    return 0;
}
