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
const int N = 1005;

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
const db eps = 1e-8;

db n, p1, p2, v1, v2, V1, V2;
db ans;
db t1, t2;

int main() {
    rep(_, 1, yh()) {
        scanf("%lf%lf%lf%lf%lf", &n, &p1, &v1, &p2, &v2);
        if (p1 > p2) swap(p1, p2), swap(v1, v2);
        ans = 1e10;
        db l = 0, r = 2e7;
        while (r - l > eps) {
            db mid = (l + r) / 2.0; bool fg = 0;
            db f1 = v1 * mid, f2 = v2 * mid;
            if (f1 >= (n - p1) && f2 >= p2) fg = 1; // cross

            if (f1 >= n + p1 || f1 >= 2 * n - p1) fg = 1;
            if (f2 >= n + p2 || f2 >= 2 * n - p2) fg = 1; //single can

            if (f1 >= p1 && f2 >= (n - p2)) {
                db tl = max(f1 - 2 * p1 + p1, (f1 - p1) / 2 + p1);
                db tr = min(p2 - (f2 - 2 * (n - p2)), p2 - (f2 - (n - p2)) / 2);
                tl = max(p1, tl); tr = min(p2, tr);
                if (tl >= tr) fg = 1;
            }
            if (fg) r = mid - eps, ans = mid;
            else l = mid + eps;
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}
