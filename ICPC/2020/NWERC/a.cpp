#include <bits/stdc++.h>

using namespace std;

#define Trav(x, v) for (auto &x : v)

template<class T, class G> bool chkMin(T &x, G y) {
	return x > y ? (x = y), 1 : 0;
}

template<class T, class G> bool chkMax(T &x, G y) {
	return x < y ? (x = y), 1 : 0;
}

const int N = 1e5 + 5;

int n, q;
long long a[N];

int main() {
	scanf("%d%d", &n, &q);
	memset(a, 0x3f, sizeof a);
	double mx = 1e9;
	int p = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if (chkMin(mx, 1.0 * a[i] / i)) p = i;
	}
	a[0] = 0;
	int m = 1e5;
	for (int i = n + 1; i <= m; ++i) {
		for (int j = i - n; j < i; ++j) {
			chkMin(a[i], a[j] + a[i - j]);
		}
	}
	while (q--) {
		int w;
		scanf("%d", &w);
		if (w <= m) {
			printf("%lld\n", a[w]);
			continue;
		}
		int num = (w - m) / p;
		while (w - p * num > m) ++num;
		assert(w - p * num <= m);
		printf("%lld\n", a[p] * num + a[w - p * num]);
		//printf("%lld\nleft=%d %d*%d\n", a[p] * num + a[w - p * num], w - p * num, p, num);
	}
	return 0;
}
