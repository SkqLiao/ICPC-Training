#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define yh read
#define hvie '\n'

typedef long double db;
typedef long long ll;
typedef pair<int, int> pii;
const db eps = 1e-10;
int read() {
    int ret = 0, f = 0; char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')f = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
        c = getchar();
    }
    return f ? -ret : ret;
}
const int N = 1e5 + 5;

int n, tot;
int sgn(db x) {
    if (fabs(x) < eps)return 0;
    if (x < 0)return -1;
    return 1;
}
int dcmp(db x, db y) {
    return sgn(x - y);
}
struct vc {
    db x, y;
    vc() {}
    vc(db x, db y): x(x), y(y) {}
    void input() {
        x = yh(), y = yh();
    }
};
vc operator-(const vc &a, const vc &b) {
    return vc(a.x - b.x, a.y - b.y) ;
}
db operator*(const vc &a, const vc &b) {
    return a.x * b.y - a.y * b.x;
}
db operator^(const vc &a, const vc &b) {
    return a.x * b.x + a.y * b.y;
}
bool operator==(const vc &a, const vc &b) {
    return dcmp(a.x, b.x) == 0 && dcmp(a.y, b.y) == 0;
}
ostream &operator<<(ostream &out, const vc &v) {
    cout << "(" << v.x << ',' << v.y << ')'; return out;
}
struct line {
    vc s, e;
    line() {}
    line(vc s, vc e): s(s), e(e) {}
    void input() {
        s.input();
        e.input();
    }
} w, b;

vc jd(line a, line b) {
    db a1 = (b.e-b.s) * (a.s - b.s);
    db a2 = (b.e-b.s) * (a.e-b.s);
    return vc((a.s.x * a2 - a.e.x * a1) / (a2 - a1), (a.s.y * a2 - a.e.y * a1) / (a2 - a1));
}
bool strict_inter(line a, line b) {
    int d1 = sgn((a.e-a.s) * (b.s - a.s));
    int d2 = sgn((a.e-a.s) * (b.e-a.s));
    int d3 = sgn((b.e-b.s) * (a.s - b.s));
    int d4 = sgn((b.e-b.s) * (a.e-b.s));
    return ((d1 ^ d2) == -2 && (d3 ^ d4) == -2);
}
int J(line a, line b) {
    int d1 = sgn((a.e-a.s) * (b.s - a.s));
    int d2 = sgn((a.e-a.s) * (b.e-a.s));
    int d3 = sgn((b.e-b.s) * (a.s - b.s));
    int d4 = sgn((b.e-b.s) * (a.e-b.s));

    if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
    return (d1 == 0 && sgn((b.s - a.s) ^ (b.s - a.e)) <= 0) ||
           (d2 == 0 && sgn((b.e-a.s) ^ (b.e-a.e)) <= 0) ||
           (d3 == 0 && sgn((a.s - b.s) ^ (a.s - b.e)) <= 0) ||
           (d4 == 0 && sgn((a.e-b.s) ^ (a.e-b.e)) <= 0);
}
bool para(line a, line b) {
    return sgn( (a.e-a.s) * (b.e-b.s) ) == 0;
}
bool on(vc a, line L) {
    bool d1 = sgn((L.s - a) * (L.e-a)) == 0;
    int d2 = sgn((L.s - a) ^ (L.e-a));
    return d1 && (d2 <= 0);
}
db S(vc a, vc b, vc c) {
    return fabs((b - a) * (c - a)) / 2.0;
}
int main() {

    rep(_, 1, read()) {
        cout << "Case " << _ << ": ";
        w.input(); b.input();
        line ac(b.s, w.s), ad(b.s, w.e), bc(b.e, w.s), bd(b.e, w.e);
        if (para(w, b) && para(ac, bd) && para(ad, bc) && para(ac, bc) && para(ad, bc)) {
            puts("0.0000");
            continue;
        }
        if (strict_inter(w, b)) {
            //puts("strictly intersect");
            puts("0.00000");
            continue;
        }
        if (w.s == b.s || w.s == b.e || w.e == b.s || w.e == b.e) {
            //puts("share common point");
            puts("inf");
            continue;
        }
        if (on(w.s, b) || on(w.e, b)) {
            //puts("w 's point is on b");
            puts("0.000000");
            continue;
        }
        if (on(b.s, w) || on(b.e, w)) {
            //puts("b 's point is on w");
            puts("inf");
            continue;
        }
        if (J(ac, bd) == 2) {
            //puts("ac j bd");
            if (para(ad, bc)) {
                puts("inf");
            } else {
                vc p = jd(ad, bc);
                if (sgn((p - b.e) ^ (w.s - b.e)) < 0) puts("inf");
                else cout << fixed << setprecision(10) << S(p, w.s, w.e) << hvie;
            }
            continue;
        }
        if (J(ad, bc) == 2) {
            //puts("ad j bc");
            if (para(ac, bd)) {
                puts("inf");
            } else {
                vc p = jd(ac, bd);
                if (sgn((p - b.e) ^ (w.e-b.e)) < 0) puts("inf");
                else cout << fixed << setprecision(10) << S(p, w.s, w.e) << hvie;
            }
            continue;
        }
        if (J(ad, bc) == 1) {
            vc p = jd(ad, bc);
            //puts("case b1");
            if (p == w.s || p == w.e) {
                puts("0.0000000");
            } else if (p == b.s || p == b.e) {
                puts("inf");
            }
            continue;
        }
        if (J(ac, bd) == 1) {
            //puts("case b2");
            vc p = jd(ac, bd);
            if (p == w.s || p == w.e) {
                puts("0.00000000");
            } else if (p == b.s || p == b.e) {
                puts("inf");
            }
            continue;
        }
        //puts("case 3");
        vc p = jd(w, b);
        if (on(p, w)) {
            puts("inf");
        } else puts("0.000000000");
    }
    return 0;
}
