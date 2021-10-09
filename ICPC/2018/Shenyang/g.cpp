#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int n, m;
map<pair<int, int>, int> Points;
unordered_map<int, vector<pair<int, int>>> Pre;
set<pair<int, int>> s;

void solve() {
    scanf("%d%d", &n, &m);
    Points.clear();
    for (int i = 1, x, y, w; i <= n; ++i) {
        scanf("%d%d%d", &x, &y, &w);
        Points[ {x, y}] = w;
    }
    long long lstans = 0;
    for (int i = 1, t, x, y, k, w; i <= m; ++i) {
        scanf("%d%d%d", &t, &x, &y);
        x = (x + lstans) % 6000 + 1;
        y = (y + lstans) % 6000 + 1;
        if (t != 2) scanf("%d", &k);
        if (t == 1) Points[ {x, y}] = k;
        else if (t == 2) Points.erase({x, y});
        else if (t == 3) {
            scanf("%d", &w);
            for (auto a : Pre[k]) {
                int xx = a.first, yy = a.second;
                int nx1 = x - xx, nx2 = x + xx;
                int ny1 = y - yy, ny2 = y + yy;
                s.clear();
                s.insert({nx1, ny1});
                s.insert({nx1, ny2});
                s.insert({nx2, ny1});
                s.insert({nx2, ny2});
                for (auto b : s) if (Points.count(b)) Points[b] += w;
            }
        } else if (t == 4) {
            long long total = 0;
            for (auto a : Pre[k]) {
                int xx = a.first, yy = a.second;
                int nx1 = x - xx, nx2 = x + xx;
                int ny1 = y - yy, ny2 = y + yy;
                s.clear();
                s.insert({nx1, ny1});
                s.insert({nx1, ny2});
                s.insert({nx2, ny1});
                s.insert({nx2, ny2});
                for (auto b : s) if (Points.count(b)) total += Points[b];
            }
            printf("%lld\n", total);
            lstans = total;
        }
    }
}

int main() {
    int val;
    for (int i = 0; i <= 6000; ++i) {
        Pre[i * i + i * i].push_back({i, i});
        for (int j = i + 1; j <= 6000 && (val = i * i + j * j) <= 1e7; ++j) {
            Pre[val].push_back({i, j});
            Pre[val].push_back({j, i});
        }
    }
    int Case;
    scanf("%d", &Case);
    for (int i = 1; i <= Case; ++i) {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}
