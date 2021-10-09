#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, lim, tot;
char s[N];

void dfs(int cnt0, int cnt1, int len, int now) {
    if (cnt0 > lim || cnt1 > lim) return;
    if (len == n) {
        ++tot;
        printf("%s\n", s);
        if (tot >= 100) exit(0);
        return;
    }
    s[len] = 'b';
    dfs(cnt0 + (now ^ 1), cnt1 + now, len + 1, now);
    s[len] = 'r';
    dfs(cnt0 + now, cnt1 + (now ^ 1), len + 1, now ^ 1);
}

int main() {
    scanf("%d", &n); lim = (n + 2) >> 1;
    printf("%lld\n", 1ll * ((n + 1) >> 1) * ((n + 2) >> 1));
    dfs(1, 0, 0, 0);
    return 0;
}