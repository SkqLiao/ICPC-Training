#include <bits/stdc++.h>

#define Trav(x, v) for (auto &x : v)

using namespace std;

const int N = 4e5 + 5;

int n, m;
int a[N];
vector<int> v[N];
unordered_set<int> s[N];

int gcd(int x, int y) {
    return !y ? x : gcd(y, x % y);
}

void check(int a, int b) {
    if (b < 1 || b > 2e5) return ;
    int c = a xor b, d = gcd(a, b);
    if (c == d && c == abs(a - b)) s[a].insert(b);
}

unordered_map<int, int> Cnt[N];
long long ans;
int Fa[N];

int findFa(int x) {
    return Fa[x] == x ? x : Fa[x] = findFa(Fa[x]);
}

void add(int x, int y) {
    a[x] = y;
    Fa[x] = x;
    Cnt[x][y] = 1;
}

void merge(int x, int y) {
    x = findFa(x), y = findFa(y);
    if (x == y) return ;
    if (Cnt[x].size() > Cnt[y].size()) swap(x, y);
    Trav(a, Cnt[x]) {
        Trav(b, s[a.first]) {
            if (Cnt[y].count(b)) ans += 1ll * a.second * Cnt[y][b];
        }
    }
    Trav(a, Cnt[x]) Cnt[y][a.first] += a.second;
    Cnt[x].clear();
    Fa[x] = y;
}

void modify(int x, int y) {
    int p = x;
    x = findFa(x);
    Trav(b, s[a[p]]) {
        if (Cnt[x].count(b)) ans -= Cnt[x][b];
    }
    --Cnt[x][a[p]];
    a[p] = y;
    Trav(b, s[a[p]]) {
        if (Cnt[x].count(b)) ans += Cnt[x][b];
    }
    ++Cnt[x][a[p]];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        Cnt[i][a[i]] = 1;
        Fa[i] = i;
    }
    for (int i = 1; i <= 2e5; ++i) {
        for (int j = 1; j * i <= 2e5; ++j) v[i * j].push_back(i);
    }
    for (int a = 1; a <= 2e5; ++a) {
        for (auto x : v[a]) {
            check(a, a + x);
            check(a, a - x);
        }
    }
    int opt, x, y;
    while (m--) {
        scanf("%d%d%d", &opt, &x, &y);
        if (opt == 1) {
            add(x, y);
        } else if (opt == 2) {
            merge(x, y);
        } else {
            modify(x, y);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
