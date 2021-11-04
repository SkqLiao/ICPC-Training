/* Code Information
 * Author: SkqLiiiao
 * Time: 2021-11-03 15:21:06
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

const int N = 2000 + 5;

int n, m;
string s[N];
bitset<N> Vis[N];
int f[N][N];
stack<pii> stk;
queue<pii> q;

void run(int x, int y) {
    int step = 0;
    while (true) {
        stk.push({x, y});
        Vis[x][y] = 1;
        int nx = x, ny = y;
        if (s[x][y] == 'L') --ny;
        if (s[x][y] == 'R') ++ny;
        if (s[x][y] == 'U') --nx;
        if (s[x][y] == 'D') ++nx;
        if (nx < 0 || ny < 0 || nx == n || ny == m) {
            step = 0;
            break;
        } else if (f[nx][ny] != -1) {
            step = f[nx][ny];
            break;
        } else if (Vis[nx][ny]) {
            auto p = make_pair(nx, ny);
            while (stk.top() != p) {
                q.push(stk.top());
                stk.pop();
            }
            q.push(stk.top());
            stk.pop();
            step = SZ(q);
            while (!q.empty()) {
                f[q.front().fir][q.front().sec] = step;
                q.pop();
            }
            break;
        }
        x = nx, y = ny;
    }
    while (!stk.empty()) {
        f[stk.top().fir][stk.top().sec] = ++step;
        stk.pop();
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            f[i][j] = -1;
            Vis[i][j] = 0;
        }
    }
    int ans = 0, ansx = 0, ansy = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (f[i][j] == -1) run(i, j);
            if (chkMax(ans, f[i][j])) {
                ansx = i, ansy = j;
            }
        }
    }
    cout << ansx + 1 << " " << ansy + 1 << " " << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Case;
    cin >> Case;
    while (Case--)
        solve();
    return 0;
}