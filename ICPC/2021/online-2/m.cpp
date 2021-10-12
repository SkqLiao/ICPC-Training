#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;i++)
#define dwn(i,a,b) for(int i=(a),i##end=(b);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second

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

const int N = 100 + 5;

int n;
int sgn[N], a[N], b[N], c[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> sgn[i];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) {
        c[i] += a[i] + b[i];
        while (c[i] < 0) {
            c[i] += 2;
            if (sgn[i + 1] == sgn[i]) c[i + 1] -= 1;
            else c[i + 1] += 1;
        }
        int add = c[i] / 2;
        c[i] %= 2;
        if (sgn[i + 1] == sgn[i]) c[i + 1] += add;
        else c[i + 1] -= add;
    }
    for (int i = 0; i < n - 1; ++i) cout << c[i] << " ";
    cout << c[n - 1];
    return 0;
}
