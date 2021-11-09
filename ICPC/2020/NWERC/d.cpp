#include <bits/stdc++.h>

using namespace std;

#define Trav(x, v) for (auto &x : v)

template<class T, class G> bool chkMin(T &x, G y) {
	return x > y ? (x = y), 1 : 0;
}

template<class T, class G> bool chkMax(T &x, G y) {
	return x < y ? (x = y), 1 : 0;
}

#define int long long

int n;
int tms;

long long ask(int x, int y) {
	if (!(0 <= x && 0 <= y && x <= 1e6 && y <= 1e6)) return 1;
	assert(++tms <= 1000);
	cout << x << " " << y << endl;
	fflush(stdout);
	long long z;
	cin >> z;
	return z;
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		long long x = ask(0, 0);
		if (!x) continue;// x = j * j + z * z // j <= z
		bool ok=0;
		int up=min(1e6,sqrt(x));
		for (long long j = 0; j <= up; ++j) {
			long long y = x - j * j;
			long long z = sqrt(y);
			if (z * z == y) {
				if (!ask(j, z) || !ask(z, j)) {
					ok = 1;
					break;
				}
			}
		}
		assert(ok);
	}
	return 0;
}
