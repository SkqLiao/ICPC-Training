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
const int N = 2e5 + 5;
int n, m, Q;
int room[N], guy[N];
set<int>st[N];

int main() {
    n = read(); m = read(); Q = read();
    while (Q--) {
        int op = read(), x = read(), y = read();
        if (op == 1) guy[x] -= room[y], st[x].insert(y);
        else if (op == 2) guy[x] += room[y], st[x].erase(y);
        else room[y]++, guy[x]--;
    }
    for (int i = 1; i <= m; ++i) {
        for (auto v : st[i]) guy[i] += room[v];
        printf("%d\n", guy[i]);
    }
    return 0;
}
/*
3 3 10
1 3 2
1 3 1
1 1 2
1 2 1
3 1 2
2 3 1
3 3 2
3 2 1
3 3 2
3 2 1


2 5 10
1 1 2
3 1 2
2 1 2
1 3 2
1 1 2
3 1 2
3 3 2
1 4 2
3 3 2
1 5 1


*/
