#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int sx, sy;
char s[N];
int Map[256];
int b[4];

void solve() {
    scanf("%d%d%s", &sx, &sy, s);
    if (!sx && !sy) {
        puts("Impossible");
        return ;
    }
    int l = strlen(s);
    memset(b, 0, sizeof b);
    for (int i = 0; i < l; ++i) {
        ++b[Map[s[i]]];
    }
    if (sx == b[3] - b[2] && sy == b[0] - b[1]) {
        puts("Impossible");
        return ;
    }
    int a[] = {0, 1, 2, 3};
    do {
        int x = 0, y = 0, flag = 1;
        for (int step = 0; step < 4; ++step) {
            int cur = a[step];
            for (int i = 0; i < b[cur]; ++i) {
                switch (cur) {
                case 0: ++y; break;
                case 1: --y; break;
                case 2: --x; break;
                case 3: ++x; break;
                }
                if (x == sx && y == sy) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) {
            int l = 0;
            for (int step = 0; step < 4; ++step) {
                int cur = a[step];
                for (int i = 0; i < b[cur]; ++i) {
                    if (cur == 0) putchar('U');
                    else if (cur == 1) putchar('D');
                    else if (cur == 2) putchar('L');
                    else putchar('R');
                }
            }
            puts("");
            return ;
        }
    } while (next_permutation(a, a + 4));
    puts("Impossible");
}

int main() {
    Map['U'] = 0;
    Map['D'] = 1;
    Map['L'] = 2;
    Map['R'] = 3;
    int Case;
    scanf("%d", &Case);
    while (Case--) solve();
    return 0;
}