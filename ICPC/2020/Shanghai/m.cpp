#include <bits/stdc++.h>

using namespace std;

#define Trav(x, v) for (auto &x : v)

const int N = 10000 + 5;

int n, m;
string s[N], t[N];
map<string, int> Name;
set<int> G[N];
int Color[N];
int cnt;

void trans(string s, int val) {
    string ss = "";
    s += '/';
    int x = 1;
    //cout << s << " : 1";
    Trav(c, s) {
        ss.push_back(c);
        if (c == '/') {
            if (!Name.count(ss)) Name[ss] = ++cnt;
            int p = Name[ss];
            //cout << "->" << p;
            G[x].insert(p);
            x = p;
        }
    }
    //cout << endl;
    Color[x] = val;
}

// Color[x]
// 1 all black
// 2 white
// 3 white & black

void dfs(int x) {
    //cout << x << " : " << Color[x] << endl;
    int val = 0, flag = 0;
    Trav(v, G[x]) {
        dfs(v);
        val = max(val, Color[v]);
        flag |= Color[v] == 1;
    }
    if (Color[x]) return ;
    if (val == 2 && flag) Color[x] = 3;
    else Color[x] = val;
    //cout << x << " : " << Color[x] << endl;
}

int dfs2(int x) {
    //cout << x << " : " << Color[x] << endl;
    if (!Color[x] || Color[x] == 2) return 0;
    if (Color[x] == 1) return 1;
    int ans = 0;
    Trav(v, G[x]) {
        ans += dfs2(v);
    }
    return ans;
}

void solve() {
    cin >> n >> m;
    Name.clear();
    for (int i = 1; i <= cnt; ++i) {
        Color[i] = 0;
        G[i].clear();
    }
    cnt = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        trans(s[i], 1);
    }
    for (int i = 1; i <= m; ++i) {
        cin >> t[i];
        trans(t[i], 2);
    }
    dfs(1);
    Color[1] = 3;
    cout << dfs2(1) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
