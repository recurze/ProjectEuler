/**
 * File              : 3.cpp
 * Author            : recurze
 * Date              : 12:51 26.12.2018
 * Last Modified Date: 12:56 26.12.2018
 */

#include <cstdio>
#include <algorithm>

inline bool removeDinN(long long& n, long long d) {
    int count = 0;
    while (!(n%d)) {
        n /= d;
        ++count;
    }
    return count;
}

inline long long solve(long long n) {
    long long res = n;
    if (removeDinN(n, 2)) res = 2;
    if (removeDinN(n, 3)) res = 3;

    for (int i = 5, j = 7; 1L*i*i <= n; i += 6, j += 6) {
        if (removeDinN(n, i)) res = i;
        if (removeDinN(n, j)) res = j;
    }

    if (n - 1) res = std::max(res, n);
    return res;
}

int main() {
    int t = 0;
    scanf("%d", &t);
    long long n = 0, ans;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%ld", &n);
        ans = solve(n);
        printf("%ld\n", ans);
    }
    return 0;
}
