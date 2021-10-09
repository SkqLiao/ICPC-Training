#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;

int n;
pair<int, int> a[N];
vector<pair<double, double>> res;

int main() {
    scanf("%d", &n);
    char s[5];
    int x;
    int totala = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%s %d", s, &x);
        a[i] = {x, s[0] == '+'};
        totala += a[i].second;
    }
    int totalb = n - totala;
    sort(a + 1, a + n + 1);
    int numa = totala, numb = totalb;
    res.push_back({2.0, 1.0});
    res.push_back({1.0, 1.0});
    //printf("0 : %lf %lf\n", 1.0, 1.0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n + 1; ++j) {
            if (j > n || a[j].first != a[i].first) {
                i = j - 1;
                break;
            }
            if (a[j].second) --numa;
            else --numb;
        }
        double tpr = 1.0 * numa / totala;
        double fpr = 1.0 * numb / totalb;
        //printf("%d : %lf %lf\n", i, tpr, fpr);
        res.push_back({tpr, fpr});
    }
    double mx = 0, ans = 0;
    for (int i = res.size() - 1; i > 0; --i) {
        mx = max(mx, res[i].first);
        for (int j = i - 1; j >= 0; --j) {
            if (j == 0 || fabs(res[j].first - res[i].first) > 1e-7) {
                //printf("[%lf %lf]: %lf\n", res[i].second, res[j].second, res[i].first);
                ans += (res[j].second - res[i].second) * res[i].first;
                i = j + 1;
                break;
            }
        }
    }
    printf("%.9lf\n", ans);
    return 0;
}