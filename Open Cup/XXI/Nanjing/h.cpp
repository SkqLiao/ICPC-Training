#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=(l),i##end=(r);i<=i##end;i++)
#define dwn(i,l,r) for(int i=(l),i##end=(r);i>=i##end;i--)
#define pb push_back
#define mkp make_pair
#define hvie '\n'
#define read yh
int yh() {
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
const int N = 1e5 + 5, mod = 1e9 + 7;


int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int qpow(int x, int y) {
    int ret = 1;
    for (; y; y >>= 1, x = mul(x, x))
        if (y & 1) ret = mul(ret, x);
    return ret;
}
int n, m, f[10][10];

int main() {
    f[2][2] = 15;
    f[2][3] = 339;
    f[2][4] = 4761;
    f[2][5] = 52929;
    f[2][6] = 517761;
    f[2][7] = 4767849;
    f[2][8] = 43046721;
    f[2][9] = 387420489;
    f[3][3] = 16485;
    f[3][4] = 518265;
    f[3][5] = 14321907;
    f[3][6] = 387406809;
    f[3][7] = 460338013;
    f[3][8] = 429534507;
    f[3][9] = 597431612;
    f[4][4] = 43022385;
    f[4][5] = 486780060;
    f[4][6] = 429534507;
    f[4][7] = 792294829;
    f[4][8] = 175880701;
    f[4][9] = 246336683;
    f[5][5] = 288599194;
    f[5][6] = 130653412;
    f[5][7] = 748778899;
    f[5][8] = 953271190;
    f[5][9] = 644897553;
    f[6][6] = 246336683;
    f[6][7] = 579440654;
    f[6][8] = 412233812;
    f[6][9] = 518446848;
    f[7][7] = 236701429;
    f[7][8] = 666021604;
    f[7][9] = 589237756;
    f[8][8] = 767713261;
    f[8][9] = 966670169;
    f[9][9] = 968803245;
    dwn(_, yh(), 1) {
        n = read(); m = read();
        if (n == 1 || m == 1) {
            puts("0");
            continue;
        }
        if (n > 9 || m > 9) {
            printf("%d\n", qpow(3, n * m));
            continue;
        }
        if (n > m) swap(n, m);
        printf("%d\n", f[n][m]);
    }
    return 0;
}
