#include <bits/stdc++.h>

using namespace std;

int main() {
    int Case;
    cin >> Case;
    long long n, x, t;
    while (Case--) {
        cin >> n >> x >> t;
        long long fir = x - (2 * n - 1) * t;
        long long sec = fir + t;
        if (sec <= 0) {
            cout << 4 * n *t << "\n";
        } else {
            cout << 4 * n *t + min(sec, t + max(0ll, fir - t)) << "\n";
        }
    }
    return 0;
}