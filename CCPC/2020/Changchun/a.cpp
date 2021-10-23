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
const int N = 1e5 + 5;

int n;
const int A[] = {1, 6, 28, 88, 198, 328, 648};
const int B[] = {8, 18, 28, 58, 128, 198, 388};

int f[N];

int main() {
    cin >> n;
    for (int i = 0; i < 7; ++i) {
        for (int j = n; j >= 0; --j) {
            for (int k = 1; k <= j / A[i]; ++k) {
                f[j] = max(f[j], f[j - k * A[i]] + B[i] + k * A[i] * 10);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
