#include <bits/stdc++.h>

using namespace std;

#define Trav(x, v) for (auto &x : v)

template<class T, class G> bool chkMin(T &x, G y) {
	return x > y ? (x = y), 1 : 0;
}

template<class T, class G> bool chkMax(T &x, G y) {
	return x < y ? (x = y), 1 : 0;
}

const int N = 5000 + 5;

int n, r, m;
int t[N], d[N];
double p[N], total[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> t[i] >> p[i] >> d[i];
	}
	for (int i = m; i >= 1; --i) {
		total[i] = total[i + 1] + d[i] * p[i];
	}
	double tme = 0, pos = 1, ans = 1e9;
	for (int i = 1; i <= m; ++i) {
		tme += t[i] / (pos * 。5p[i]);
		pos *= (1 - p[i]);
		if (n + total[i + 1] <= r) chkMin(ans, tme + total[i + 1] + n - t[i]);
	}
	cout << ans << endl;
	return 0;
}
