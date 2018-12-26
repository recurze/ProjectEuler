/**
 * File              : 1.cpp
 * Author            : recurze
 * Date              : 11:44 26.12.2018
 * Last Modified Date: 11:49 26.12.2018
 */

#include <cstdio>

inline long long sumOfNaturalNumbers(int n) {
    return 1L*n*(n+1)>>1;
}

inline long long solve(int n) {
    return 3*sumOfNaturalNumbers(n/3)
        +  5*sumOfNaturalNumbers(n/5)
        - 15*sumOfNaturalNumbers(n/15);
}

int main() {
    int t = 0;
    scanf("%d", &t);
    int n = 0;
    long long ans = 0;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        ans = solve(n - 1);
        printf("%ld\n", ans);
    }
}
