/**
 * File              : 5.cpp
 * Author            : recurze
 * Date              : 13:52 26.12.2018
 * Last Modified Date: 13:56 26.12.2018
 */

#include <cstdio>
#include <algorithm>

inline long long lcm(int a, int b) {
    return 1L * a * b / std::__gcd(a, b);
}

inline long long solve(int n) {
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res = lcm(res, i);
    }
    return res;
}

int main() {
    int t = 0;
    scanf("%d", &t);
    int n = 0;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        printf("%ld\n", solve(n));
    }
    return 0;
}
