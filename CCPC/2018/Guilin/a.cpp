/*
 * @date:
 * @source:
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
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
#define Trav(i, x) for (auto & i : x)
#define pb push_back
template<class T, class G> bool chkMax(T &x, G y) {
    return y > x ? x = y, 1 : 0;
}
template<class T, class G> bool chkMin(T &x, G y) {
    return y < x ? x = y, 1 : 0;
}

const int N = 1e5 + 5;

int n, m;
vi v1, v2;
int l1[N], l2[N], r1[N], r2[N], sum1[N], sum2[N];

struct Node {
    int sum;
    int l, r;
    Node () {}
    Node (int a, int b, int c) {
        sum = a, l = b, r = c;
    }
    bool operator < (const Node &x) const {
        int a1 = sum * (x.r - x.l + 1);
        int a2 = x.sum * (r - l + 1) ;
        return a1 == a2 ? r > x.r : a1 < a2;
    }
};

priority_queue<Node> s1, s2;
//set<Node> s1, s2;

void solve() {
    cin >> n >> m;
    v1.resize(n);
    v2.resize(m);
    Trav(x, v1) cin >> x;
    Trav(x, v2) cin >> x;
    sum1[0] = v1[0];
    sum2[0] = v2[0];
    while (!s1.empty()) s1.pop();
    while (!s2.empty()) s2.pop();
    for (int i = 0; i < n; ++i) {
        if (i) sum1[i] = sum1[i - 1] + v1[i];
        s1.push((Node) {
            v1[i], i, i
        });
        l1[i] = r1[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        if (i) sum2[i] = sum2[i - 1] + v2[i];
        s2.push((Node) {
            v2[i], i, i
        });
        l2[i] = r2[i] = i;
    }
    int c1 = 0, c2 = 0, pp = 1, ans = 0;
    while (c1 < n || c2 < m) {
        //printf("%lld %lld\n", c1, c2);
        if (!s1.empty()) {
            while (!s1.empty()) {
                auto x = s1.top();
                //printf("s1 now %lld %lld\n", x.l, x.r);
                assert(!((l1[x.l] != x.r) ^ (r1[x.r] != x.l)));
                if (l1[x.l] != x.r || r1[x.r] != x.l) {
                    s1.pop();
                    continue;
                }
                if (x.l == c1) {
                    break;
                } else {
                    s1.pop();
                    //printf("s1 old %lld %lld\n", x.l, x.r);
                    int p = x.l - 1;
                    assert(p >= 0);
                    x.sum += sum1[p] - (!r1[p] ? 0 : sum1[r1[p] - 1]);
                    x.l = r1[p];
                    r1[x.r] = r1[p];
                    l1[r1[p]] = x.r;
                    r1[p] = -1;
                    s1.push(x);
                    //printf("s1 new %lld %lld\n", x.l, x.r);
                }
            }
        }
        //puts("haha");
        if (!s2.empty()) {
            while (!s2.empty()) {
                auto x = s2.top();
                assert(!((l2[x.l] != x.r) ^ (r2[x.r] != x.l)));
                if (l2[x.l] != x.r || r2[x.r] != x.l) {
                    s2.pop();
                    continue;
                }
                if (x.l == c2) {
                    break;
                } else {
                    s2.pop();
                    //printf("s2 old %d %d\n", x.l, x.r);
                    int p = x.l - 1;
                    assert(p >= 0);
                    x.sum += sum2[p] - (!r2[p] ? 0 : sum2[r2[p] - 1]);
                    x.l = r2[p];
                    r2[x.r] = r2[p];
                    l2[r2[p]] = x.r;
                    r2[p] = -1;
                    s2.push(x);
                    //printf("s2 new %d %d\n", x.l, x.r);
                }
            }
        }
        //puts("hahaha");
        auto aver1 = -1e9, aver2 = -1e9;
        Node a1(-1, -1, -1), a2(-1, -1, -1);
        if (!s1.empty()) a1 = s1.top();
        if (!s2.empty()) a2 = s2.top();
        //printf("s1 max : %lld ,%lld\n", a1.l, a1.r);
        //printf("s2 max : %lld ,%lld\n", a2.l, a2.r);
        if (!s1.empty()) aver1 = 1.0 * a1.sum / (a1.r - a1.l + 1);
        if (!s2.empty()) aver2 = 1.0 * a2.sum / (a2.r - a2.l + 1);
        //printf("%lf %lf\n", aver1, aver2);
        //exit(0);
        if (aver1 > aver2) {
            for (int i = a1.l; i <= a1.r; ++i) ans += pp++ * v1[i];
            c1 = a1.r + 1;
            s1.pop();
        } else {
            for (int i = a2.l; i <= a2.r; ++i) ans += pp++ * v2[i];
            c2 = a2.r + 1;
            s2.pop();
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Case;
    cin >> Case;
    for (int i = 1; i <= Case; ++i) {
        cout << "Case " << i << ": ";
        solve();
    }
    return 0;
}