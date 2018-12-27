/**
 * File              : 15.cpp
 * Author            : recurze
 * Date              : 12:35 27.12.2018
 * Last Modified Date: 14:59 27.12.2018
 */

#include <cstdio>

const int MD = 1000000007;
inline void add(int& a, int b, int p = MD) { a += b; a -= (a >= p)*p; }

const int N = 1001;
int c[N][N];
void buildCTable(int n) {
    for (int i = 0; i <= n; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            add(c[i][j], c[i - 1][j    ]);
            add(c[i][j], c[i - 1][j - 1]);
        }
    }
}

int solve(int n, int m) {
    return c[n + m][n];
}

int main() {
    int t; scanf("%d", &t);
    int n, m;
    buildCTable(1000);
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d%d", &n, &m);
        printf("%d\n", solve(n, m));
    }
}
