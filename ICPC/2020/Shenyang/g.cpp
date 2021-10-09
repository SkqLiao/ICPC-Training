#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
const int maxn = 1e5 + 5;

long long a[maxn];
int main() {
    int n, k; scanf("%d%d", &n, &k);
    long long ans = 0;
    rep(i, 1, n) scanf("%lld", a + i);
    sort(a + 1, a + 1 + n, greater<int>());
    rep(i, 1, k) ans += a[i];
    cout << ans << endl;
    return 0;
}