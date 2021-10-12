#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l,i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=l,i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
#define hvie '\n'
typedef long long ll;
typedef double db;
const int N = 2e5 + 10, inf = 0x3f3f3f3f;
int read() {
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
vector<int>v;
vector<int>ans;
int main() {
    int x = 0;
    while (scanf("%d", &x) == 1) {
        v.pb(x);
    }
    int n = v.size() - 2;
    rep(i, 0, n - 1) {
        if (abs(v[i] - v[n]) <= v[n + 1]) ans.pb(v[i]);
    }
    sort(ans.begin(), ans.end(), greater<int>());
    if (!ans.size())return puts(""), 0;
    for (int i : ans)cout << i << " ";

    return 0;
}
