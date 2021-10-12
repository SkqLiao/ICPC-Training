#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l,i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=l,i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
#define hvie '\n'
typedef long long ll;
typedef double db;
const int inf = 0x3f3f3f3f;
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
struct pt {
    int x, y;
    pt() {}
    pt(int x, int y): x(x), y(y) {}
    bool operator<(const pt &A)const {
        return (y < A.y) || (y == A.y && x < A.x);
    }
} p[555], a[555];
pt S;
int crs(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}
pt operator-(const pt &A, const pt &B) {
    return pt(A.x - B.x, A.y - B.y);
}
bool cmp(pt a, pt b) {
    return crs(a - S, b - S) > 0;
}
int dis(pt p) {
    return p.x * p.x + p.y * p.y;
}
int n;
vector<pt>ans;
int main() {
    S.y = inf;
    while (1) {
        int x = read(); if (x < -10000) break;
        int y = read();
        p[++n] = pt(x, y);
        if (y < S.y) S = p[n];
    }
    if (n <= 2) {
        cout << "ERROR";
        return 0;
    }
    sort(p + 1, p + 1 + n);
    S = p[1];
    sort(p + 2, p + 1 + n, cmp);
    bool bad = 0;
    rep(i, 2, n - 1) {
        if (crs(p[i] - p[i - 1], p[i + 1] - p[i]) <= 0) {
            bad = 1; break;
        }
    }
    if (bad)return cout << "ERROR", 0;
    ans.pb(p[1]);
    dwn(i, n, 2)ans.pb(p[i]);
    int k = 0;
    rep(i, 0, n - 1) {
        if (dis(ans[i]) < dis(ans[k]))k = i;
    }
    // cout<<k<<" "<<dis(p[0])
    for (int cnt = 1; cnt <= n; cnt++, k = (k + 1) % n) {
        cout << ans[k].x << ',' << ans[k].y;

        if (cnt < n)cout << ',';
    }
    return 0;
}
/*
2,3,3,2,1,3,3,1,0,2,2,0,0,1,1,0,
*/
/*
-1,-5,0,-5,0,-4
*/