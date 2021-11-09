#include <bits/stdc++.h>

using namespace std;

long long n, k, a, b;

int main() {
	cin >> n >> k >> a >> b;
	double ans = 1.0 * (n * a - k * b) / (n - k);
	if (ans > 100 || ans < 0) cout << "impossible" << endl;
	else cout << fixed << setprecision(8) << ans << endl;
	return 0;
}
