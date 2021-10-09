/* Code Information
 * Author: SkqLiiiao
 * Time: 2021-10-08 17:51:17
 * Url: https://codeforces.com/gym/102956/problem/H
 **/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define fir first
#define sec second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define up(i, l, r) for (int i = l; i <= r; ++i)
#define dn(i, l, r) for (int i = l; i >= r; --i)
#define Trav(i, x) for (auto &i : x)
#define pb push_back
template <class T, class G> bool chkMax(T &x, G y) {
    return y > x ? x = y, 1 : 0;
}
template <class T, class G> bool chkMin(T &x, G y) {
    return y < x ? x = y, 1 : 0;
}

#define int long long

const int P = 998244353;
const int INV6 = 166374059;

int sx, sy, tx, ty;

void add(int &x, int y) {
    x = (x + y % P) % P;
}

void mul(int x, int y) {
    x = (x % P) * (y % P) % P;
}

int sqr(int x) {
    x %= P;
    return x * x % P;
}

int sum(int n) {
    return n * (n + 1) % P * (2 * n + 1) % P * INV6 % P;
}

int sum(int l, int r) {
    return r >= l ? (sum(r) - sum(l - 1) + P) % P : 0;
}

void solve() {
    cin >> sx >> sy >> tx >> ty;
    int res = (sqr(tx * ty) - sqr(sx * sy) + P) % P;
    add(res, -sqr(tx) - sqr(ty));
    if (sx > tx) swap(sx, tx), swap(sy, ty);
    if (ty > sy) {
        if (sx < sy) {
            int nx = min(sy, tx);
            add(res, (nx - sx) * sqr(sy));
            add(res, sum(sx, nx - 1));
            if (nx == tx) {
                add(res, (ty - sy + 1) * sqr(tx));
                add(res, sum(sy, ty));
            } else {
                int nxt = min(tx, ty);
                add(res, sum(nx, nxt - 1) * 3 + sum(nx + 1, nxt));
                if (nxt == ty) {
                    add(res, sqr(ty) * (tx - nxt + 1));
                    add(res, sum(nxt, tx));
                } else {
                    add(res, sqr(tx) * (ty - nxt + 1));
                    add(res, sum(nxt, ty));
                }
            }
        } else {
            int ny = min(sx, ty);
            add(res, (ny - sy) * sqr(sx));
            add(res, sum(sy, ny - 1));
            if (ny == ty) {
                add(res, (tx - sx + 1) * sqr(ty));
                add(res, sum(sx, tx));
            } else {
                int nxt = min(tx, ty);
                add(res, sum(ny, nxt - 1) * 2);
                add(res, sum(ny, nxt - 1) + sum(ny + 1, nxt));
                if (nxt == tx) {
                    add(res, sqr(tx) * (ty - nxt + 1));
                    add(res, sum(nxt, ty));
                } else {
                    add(res, sqr(ty) * (tx - nxt + 1));
                    add(res, sum(nxt, tx));
                }
            }
        }
    } else {
        add(res, (sy - ty) * sqr(sx));
        add(res, sum(ty + 1, sy));
        add(res, (tx - sx + 1) * sqr(ty));
        add(res, sum(sx, tx));
    }
    cout << (res + P) % P << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Case;
    cin >> Case;
    while (Case--)
        solve();
    return 0;
}