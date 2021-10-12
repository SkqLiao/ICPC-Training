#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
vector<pair<int, pair<int, int>>> v;
int Fa[N];
int R[N];

int findFa(int x) {
    return Fa[x] == x ? x : Fa[x] = findFa(Fa[x]);
}

void merge(int x, int y) {
    x = findFa(x), y = findFa(y);
    R[x] = R[y];
    Fa[y] = x;
}

void solve(int t) {
    scanf("%d%d", &n, &m);
    v.clear();
    long long sum = 0;
    for (int i = 1, l, r, w; i <= m; ++i) {
        scanf("%d%d%d", &l, &r, &w);
        v.push_back({w, {l, r}});
        sum += 1ll * w * (r - l + 1) * (r - l) / 2;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; ++i) {
        Fa[i] = i;
        R[i] = i + 1;
    }
    int num = 0;
    for (auto x : v) {
        int w = x.first;
        int l = x.second.first, r = x.second.second;
        int p = findFa(l);
        for (int i = R[findFa(p)]; i <= r; i = R[findFa(i)]) {
            sum -= w;
            merge(p, i);
            ++num;
        }
    }
    printf("Case #%d: ", t);
    if (num < n - 1) {
        printf("Gotta prepare a lesson");
    } else printf("%lld", sum);
}

int main() {
    //freopen("d.in", "r", stdin);
    int Case;
    scanf("%d", &Case);
    for (int i = 1; i <= Case; ++i) {
        solve(i);
        if (i < Case) puts("");
    }
    return 0;
}