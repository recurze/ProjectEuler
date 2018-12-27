/**
 * File              : 9.cpp
 * Author            : recurze
 * Date              : 14:54 26.12.2018
 * Last Modified Date: 15:26 26.12.2018
 */

#include <cstdio>
#include <cmath>

#define sq(x) x*x
#define p4(x) sq(x)*sq(x)

int solve(int n) {
    if (n&1) return -1;
    int max = -1, res, b;
    for (int a = 1; a < n; ++a) {
        b = n * (n - 2*a);
        if (!(b%(2*(n - a)))) {
            b /= (n - a) << 1;
            if (a >= b) break;
            res = a * b * (n - a - b);
            fprintf(stderr, "%d %d %d %d\n", a, b, n - a - b, res);
            if (res > max) max = res;
        }
    }
    return max;
}

int main() {
    int t;
    scanf("%d", &t);
    int n;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}
