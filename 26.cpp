/**
 * File              : 26.cpp
 * Author            : recurze
 * Date              : 14:37 28.12.2018
 * Last Modified Date: 14:42 28.12.2018
 */
#include <cstdio>

// 1/y = 0.000...0.cycle.cycle.cycle...
// 10^i/y = 0.cycle.cycle.cycle...
// (10^i/y)*10^c = cycle.cycle.cycle....
// (10^i)*(10^c - 1)/y = cycle
// y must divide 10^i or 10^c - 1

bool ifPowerof2and5(int n) {
    while (!(n&1)) {
        n >>= 1;
    }
    while (!(n%5)) {
        n /= 5;
    }
    return n == 1;
}

int findc(int n) {
    if (ifPowerof2and5(n)) {
        return 0;
    }
    int res = 10;
    for (int i = 1; i < n; ++i) {
        if (res == 1) {
            return i;
        }
        res = (res*10)%n;
    }
    return 0;
}

const int N = 10000;
int ans[N];
void pre() {
    for (int i = 2; i <= N; ++i) {
        ans[i] = findc(i);
    }
}
int solve(int n) {
    int max = -1, res = n - 1;
    for (int i = 2; i < n; ++i) {
        if (ans[i] > max) {
            max = ans[i];
            res = i;
        }
    }
    return res;
}

int main() {
    pre();
    int t; scanf("%d", &t);
    int n;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
}
