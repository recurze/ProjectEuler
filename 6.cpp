/**
 * File              : 6.cpp
 * Author            : recurze
 * Date              : 14:00 26.12.2018
 * Last Modified Date: 14:03 26.12.2018
 */

#include <cstdio>

inline long long solve(int n) {
    return 1L*n*(n + 1)*(n*(3*n - 1) - 2)/12;
}

int main() {
    int t = 0;
    scanf("%d", &t);
    int n = 0;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        printf("%ld\n", solve(n));
    }
}
