#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, ax, ay, bx, by;
int x[N], y[N];
set<pair<int, int>> Exists;

bool legel(int x, int y) {
	return 1 <= x && 1 <= y && x <= n && y <= n;
}

bool check(int sx, int sy, int tx, int ty) {
	for (int i = 0; i < n; ++i) {
		int nx = sx + x[i], ny = sy + y[i];
		if (nx == tx && ny == ty) return 1;
		if (legel(nx, ny) && Exists.count({tx - nx, ty - ny})) {
			//cout << sx << " " << sy << " : " << tx << " " << ty << " by " << x[i] << " " << y[i] << endl;
			return 1;
		}
	}
	return 0;
}

int main() {
	srand(19491001);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> ax >> ay >> bx >> by;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		Exists.insert({x[i], y[i]});
	}
	if (check(ax, ay, bx, by)) {
		cout << "Alice wins" << endl;
		return 0;
	}
	if (!check(bx, by, ax, ay)) {
		cout << "tie " << ax << " " << ay << endl;
		return 0;
	}
	int T = 100;
	while (T--) {
		int xi = rand() % n + 1, yi = rand() % n + 1;
		if (xi == bx && yi == by) continue;
		if (!check(bx, by, xi, yi)) {
			cout << "tie " << xi << " " << yi << endl;
			return 0;
		}
	}
	cout << "Bob wins" << endl;
	return 0;
}
