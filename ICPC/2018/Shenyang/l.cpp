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
typedef long double db;
const db pi = acos(-1), eps = 1e-12;
int n, m;
struct vc {
    db x, y;
    vc() {}
    vc(db x, db y): x(x), y(y) {}
    db len() {
        return hypot(x, y);
    }
    vc operator+(const vc &b)const {
        return vc(x + b.x, y + b.y);
    }
    vc operator-(const vc &b)const {
        return vc(x - b.x, y - b.y);
    }
    vc operator*(const db &k)const {
        return vc(x * k, y * k);
    }
    void input() {
        x = yh(), y = yh();
    }
};
db Deg(db a) {
    return a / pi * 180;
}
pair<db, db>sg[155], s[155];
db R;
void inter(vc a, db r, db &L, db &Ri) {
    db d = sqrt(a.x * a.x + a.y * a.y);
    if (d >= r + R || (r < R && d <= R - r)) {
        L = -1;
        return;
    }
    db H = acos((d * d + R * R - r * r) / (2 * d * R));
    // cout<<H<<endl;
    db mid = acos(a.x / d);
    if (a.y < 0) mid = 2 * pi - mid;
    L = mid - H; Ri = mid + H;
    // cout<<mid<<" - "<<H<<" "<<L<<" "<<Ri<<endl;
    if (L < 0) L += 2 * pi;
    if (Ri >= 2 * pi) Ri -= 2 * pi;
}
bool in(db l, db r, db m) {
    if (l <= r && l <= m && m <= r) return 1;
    if (l > r && (m >= l || m <= r))return 1;
    return 0;
}
db to(db x) {
    if (x < pi) return x + pi;
    else return x - pi;
}
db Ra(db l, db r) {
    return min(fabs(l - r), 2 * pi - fabs(l - r));
}
bool check(db t) {
    rep(i, 1, m)if (in(s[i].fi, s[i].se, t))return 0;
    return 1;
}
int main() {
    rep(_, 1, yh()) {
        cout << "Case #" << _ << ": ";
        n = yh(), R = yh();
        rep(i, 1, n) {
            vc t; t.input(); db r = yh();
            inter(t, r, sg[i].fi, sg[i].se);
        }
        sort(sg + 1, sg + 1 + n);
        m = 0;
        rep(i, 1, n)if (sg[i].fi > -1) {
            s[++m] = sg[i];
            // cout<<(s[i].fi)<<" "<<(s[i].se)<<hvie;
        }
        if (!m) {
            // cout<<"?";
            cout << fixed << setprecision(12) << 2.*R << hvie;
            continue;
        }
        db ans = 0;
        rep(i, 1, m) {
            if (check(to(s[i].fi))) {
                ans = pi;
                break;
            }
            if (check(to(s[i].se))) {
                ans = pi;
                break;
            }
        }
        if (ans == pi) {
            // cout<<"?"<<hvie;
            cout << fixed << setprecision(12) << 2.*R << hvie;
            continue;
        }
        rep(i, 1, m) {
            ans = max(ans, Ra(s[i].fi, s[i].se));
            rep(j, i + 1, m) {
                // cout<<i<<" "<<j<<" : ";
                ans = max(ans, Ra(s[i].fi, s[j].fi));
                // cout<<Ra(s[i].fi,s[j].fi)<<" ";
                ans = max(ans, Ra(s[i].fi, s[j].se));
                // cout<<Ra(s[i].fi,s[j].se)<<" ";
                ans = max(ans, Ra(s[i].se, s[j].fi));
                // cout<<Ra(s[i].se,s[j].fi)<<" ";
                ans = max(ans, Ra(s[i].se, s[j].se));
                // cout<<Ra(s[i].se,s[j].se)<<" \n";
            }
        }
        // cout<<ans<<hvie;
        // cout<<"!"<<ans<<endl;
        cout << fixed << setprecision(12) << 2.*R *sin(ans / 2) << hvie;

    }
    return 0;
}
/*
1
1 10
8 -6 15

426 -568 994

*/