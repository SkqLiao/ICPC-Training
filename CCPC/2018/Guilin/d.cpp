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

ll read() {
    ll ret = 0, f = 0; char c = getchar();
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

bitset<64> a, b;

int solve(int p) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = p; i < 63; i += 2) {
        if (a[i] != b[i] && a[i] == 0) {
            pq.push(i);
        }
    }
    int ans = 0;
    for (int i = p; i < 63; i += 2) {
        if (a[i] == b[i]) continue;
        if (!b[i]) {
            int j = pq.top(); pq.pop();
            ans += abs(j - i) / 2;
            a[j] = 1;
        }
    }
    return ans;
}

int main() {
    rep(_, 1, read()) {
        a = read(), b = read();
        int even = 0, odd = 0;
        for (int i = 0; i < 63; i += 2) even += a[i] - b[i];
        for (int i = 1; i < 63; i += 2) odd += a[i] - b[i];
        cout << "Case " << _ << ": ";
        if (even || odd) cout << -1 << "\n";
        else {
            cout << solve(1) + solve(0) << "\n";
        }
    }
    return 0;
}
