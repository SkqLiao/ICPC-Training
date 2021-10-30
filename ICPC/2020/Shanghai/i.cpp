#include <bits/stdc++.h>

using namespace std;

#define db double

const db pi = acos(-1);
int n, m;

int get(int i, int j) {
    return min(abs(i - j), m - abs(i - j));
}

int main() {
    cin >> n >> m;
    m *= 2;
    db ans = 0, pim = pi / m;
    for (int i = 0; i < m; ++i) {
        for (int j = i; j < m; ++j) {
            db d1 = 2 * get(i, j) * pim;
            db d2 = 2;
            db d = min(d1, d2);
            int a = 1 + (i != j);
            //cout << i << " " << j << " : " << d << endl;
            for (int k = 1; k <= n; ++k) {
                ans += a * (n - k + 1) * (n - k + 2 * k * d) / 2;
                //cout << "add " << (n - k + 1) * (n - k + 2 * k * d) / 2 << endl;
            }
            for (int k = 1; k <= n; ++k) ans -= k * d;
        }
    }
    if (m != 2) ans += n * (n + 1) * m / 2;
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
