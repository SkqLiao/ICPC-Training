#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 5;

set<int> a;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int k, n;
vector<int> v;
int Ans[N];

int main() {
    scanf("%d%d", &k, &n);
    for (int i = 0; i < k; ++i) a.insert(i);
    for (int i = 0, s, t; i < n; ++i) {
        scanf("%d%d", &s, &t);
        while (!pq.empty() && pq.top().first <= s) {
            auto x = pq.top(); pq.pop();
            a.insert(x.second);
        }
        if (a.empty()) continue;
        auto it = a.lower_bound(i % k);
        if (it == a.end()) it = a.begin();
        ++Ans[*it];
        pq.push({s + t, *it});
        a.erase(*it);
    }
    int mx = Ans[0];
    for (int i = 0; i < k; ++i) {
        if (Ans[i] > mx) mx = Ans[i];
    }
    for (int i = 0; i < k; ++i) {
        if (Ans[i] == mx) v.push_back(i);
    }
    for (int i = 0; i < v.size() - 1; ++i) {
        printf("%d ", v[i]);
    }
    printf("%d", v.back());
    return 0;
}