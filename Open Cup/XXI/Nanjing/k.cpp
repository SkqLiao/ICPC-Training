#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define hvie '\n'
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
const int N = 1e6 + 5;
int n, k;
int main() {
    n = read(), k = read();
    if (k == 0) {
        puts("-1"); return 0;
    }
    rep(i, 1, k - 1) {
        cout << i + 1 << " ";
    }
    cout << 1 << " ";
    rep(i, k + 1, n) {
        cout << i << " ";
    }
    cout << hvie;
    return 0;
}
/*
1 2 3 4 5 6 7 8 9
2 3 4 1 5 6 7 8 9

*/
