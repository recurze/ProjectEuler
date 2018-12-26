/**
 * File              : 2.cpp
 * Author            : recurze
 * Date              : 12:33 26.12.2018
 * Last Modified Date: 12:39 26.12.2018
 */

#include <cstdio>

inline long long solve(long long n) {
    long long res = 0;
    long long a = 2, b = 3, temp;
    while (a < n) {
        //fprintf(stderr, "%ld\n", a);
        res += a;
        temp = a;
        a = a + 2*b;
        b = temp + a + b;
    }
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
