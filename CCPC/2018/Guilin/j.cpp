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
const int N = 1e5 + 5;

int n, tot;
int a[N];
priority_queue<pii, vector<pii>, greater<pii> >q;

int main() {
    rep(_, 1, read()) {
        n = read(); tot = 0;
        for (int i = 1; i <= n; ++i) a[i] = read(), q.push(mkp(a[i], i));
        for (int i = 1; i <= n; ++i) {
            int x = q.top().se; q.pop();
            if (x != 1 && x != n) {
                if (min(a[x + 1], a[x - 1]) > a[x]) tot += a[x], a[x] = 0;
                else if (max(a[x + 1], a[x - 1]) > a[x]) tot += a[x] - min(a[x + 1], a[x - 1]) - 1, a[x] = min(a[x + 1], a[x - 1]) + 1;
                else tot += a[x] - max(a[x + 1], a[x - 1]) - 1, a[x] = max(a[x + 1], a[x - 1]) + 1;
            } else if (x == 1) {
                if (a[x + 1] > a[x]) tot += a[x], a[x] = 0;
                else tot += a[x] - a[x + 1] - 1, a[x] = a[x + 1] + 1;
            } else if (x == n) {
                if (a[x - 1] > a[x]) tot += a[x], a[x] = 0;
                else tot += a[x] - a[x - 1] - 1, a[x] = a[x - 1] + 1;
            }
            tot %= 2;
        }
        printf("Case %d: ", _);
        puts(tot ? "Alice" : "Bob");
    }
    return 0;
}
