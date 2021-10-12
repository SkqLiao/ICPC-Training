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

int yh() {
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
int n, m;
int d1, d2, x, r, k;
int L[100], R[100];
bool check() {
    rep(j, 1, k) {
        if (L[j] <= R[j]) assert(R[j] - L[j] + 1 <= x);
        else assert(256 - L[j] + R[j] + 1 <= x);
    }
    rep(i, 1, k - r + 1) {
        bitset<257>b;
        rep(j, i, i + r - 1) {
            if (L[j] <= R[j]) {
                rep(p, L[j], R[j]) b[p] = 1;
            } else {
                rep(p, 0, R[j]) b[p] = 1;
                rep(p, L[j], 255) b[p] = 1;
            }
        }
        // cout<<b.count()<<endl;
        if (b.count() < 128)return 0;
        // if(R[i+r-1]-L[i]+1<128)return 0;
        // assert(R[i+r-1]-L[i]+1>=128);
    }
    return 1;
}
signed main() {
    k = yh(), r = yh();
    x = (512 + r - 1) / r;
    // int A=(256-x)%(k);
    // d2=(256-x)/(k);
    // d1=(256-x+k-2)/(k);
    int up = 256 % k, dn = k - up;
    int d = 256 / k;
    int u = (256 + k - 1) / k;
    int cur = 0;

    rep(i, 1, k) {
        L[i] = cur;
        R[i] = (L[i] + x - 1) % 256;
        if (i < up) cur += u;
        else cur += d;
    }
    if (!check()) {
        cout << -1; return 0;
    }
    rep(i, 1, k)  {

        rep(j, 0, 255) {

            if (L[i] <= R[i])cout << (L[i] % 256 <= j && j <= R[i] % 256);
            else {
                cout << (j <= R[i] || j >= L[i]);
            }
        }
        if (i < k) cout << hvie;
    }
    return 0;
}
/*
3
19 26 8
17 19 49
100 1 7

*/
