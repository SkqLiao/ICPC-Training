#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n;
char s[N];
map<ll, int>mp;
ll sum[N];

int turn(char c) {
    if (c == 'U') return 1;
    if (c == 'D') return -1;
    if (c == 'L') return N;
    return -N;
}
ll calc(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    int TT; scanf("%d", &TT);
    while (TT--) {
        scanf("%d%s", &n, s + 1); mp.clear(); ++mp[0];
        for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + turn(s[i]), ++mp[sum[i]];

        ll ans = 0;
        for (auto v : mp) {
            //printf("%d %lld\n",v.se,v.fi);
            ans += calc(v.se);
        }
        printf("%lld\n", ans);
    }

    return 0;
}