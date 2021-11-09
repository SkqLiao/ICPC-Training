/* Code Information
 * Author: SkqLiiiao
 * Time: 2021-11-09 13:41:30
 * Url:
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
#define debug(...) fprintf(stderr, __VA_ARGS__)
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

const int N = 50 + 5;

const int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m, q;
string s[N], t;
int x, y, v, d;

bool legel(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && s[x][y] != '#';
}

void travel(char c) {
    if (c == 'L') d = (d + 7) % 8;
    else if (c == 'R') d = (d + 1) % 8;
    else if (c == 'U') ++v;
    else v = max(v - 1, 0);
    for (int i = 1; i <= v; ++i) {
        int nx = x + dx[d], ny = y + dy[d];
        //cout << "nxt " << nx << " " << ny << endl;
        //cout << "chk " << x + dx[d] << " " << y << endl;
        //cout << "chk " << x << " " << y + dy[d] << endl;
        bool f = legel(nx, ny) & (legel(x + dx[d], y) | legel(x, y + dy[d]));
        if (!f) {
            cout << "Crash! " << x << " " << y << "\n";
            v = 0;
            return ;
        } else {
            //cout << nx << " " << ny << "\n";
            x = nx, y = ny;
        }
    }
    cout << x << " " << y << endl;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        s[i] = " " + s[i];
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*') {
                x = i, y = j;
                s[i][j] = '.';
            }
        }
    }
    cin >> q >> t;
    for (auto c : t) travel(c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}