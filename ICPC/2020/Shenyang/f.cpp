#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define mkp make_pair
#define pb push_back
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
    return ret;
}
const int maxn = 1e6 + 5;

int a[maxn];
int mn[maxn];
map<int, int> lst;

int main() {
    int n = read();
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        lst[a[i]] = i;
    }
    auto it = lst.begin();
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int l = i, mx = a[i];
        for (int r = i; i <= r; ++i) {
            mx = max(mx, a[i]);
            while (it != lst.end() && it->first <= mx) {
                r = max(r, it->second);
                ++it;
            }
        }
        --i;
        mn[i] = a[i];
        for (int j = i - 1; j >= l; --j) mn[j] = min(mn[j + 1], a[j]);
        mx = -1;
        for (int j = l; j < i; ++j) {
            if (mx == -1) mx = a[j];
            else mx = max(mx, a[j]);
            if (mx <= mn[j + 1]) {
                ++ans;
                mx = -1;
                l = j + 1;
            }
        }
        ++ans;
    }
    cout << ans << "\n";
    return 0;
}
// 4 4 4 5 6 4