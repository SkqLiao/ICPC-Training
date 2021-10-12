#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),i##ss=(b);i<=i##ss;i++)
#define dwn(i,a,b) for(int i=(a),i##ss=(b);i>=i##ss;i--)
#define deb(x) cerr<<(#x)<<":"<<(x)<<'\n'
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define hvie '\n'
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
int yh() {
    int ret = 0; bool f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == EOF)return -1;
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c))ret = (ret << 3) + (ret << 1) + (c ^ 48), c = getchar();
    return f ? -ret : ret;
}
const int maxn = 3e5 + 5;
int n, m;
int cnt[5] = {
    0, 1, 4, 2, 3
};
string s[5] = {
    "imstupid", "1", "0001", "01", "001"
};
int main() {
    dwn(_, yh(), 1) {
        int n = yh();
        if (n == 1) {
            cout << ("1\n1\n");
        } else if (n == 2) {
            cout << ("4\n0001\n");
        } else if (n == 3) {
            cout << ("2\n01\n");
        } else if (n == 4) {
            cout << ("3\n001\n");
        } else {
            int r = n % 4; if (r == 0) r = 4;
            cout << cnt[r] + (n - r) << hvie;
            cout << s[r];
            rep(i, 1, (n - r) / 4) cout << "1001";
            cout << hvie;
        }


    }
    return 0;
}