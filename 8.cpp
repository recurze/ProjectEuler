/**
 * File              : 8.cpp
 * Author            : recurze
 * Date              : 14:12 26.12.2018
 * Last Modified Date: 14:28 26.12.2018
 */

#include <cstdio>

char s[1001];

long long prod(int start, int end) {
    long long res = 1;
    for (int i = start; i < end; ++i) {
        res *= (s[i] - '0');
    }
    return res;
}

long long solve(int n, int k) {
    long long res = prod(0, k);
    long long max = res;
    for (int i = 1; i < n - k; ++i) {
        if (s[i - 1] == '0') {
            res = prod(i, i + k);
        } else {
            res /= (s[i - 1] - '0');
            res *= (s[i - 1 + k] - '0');
        }
        if (res > max) max = res;
    }
    return max;
}

int main() {
    int t;
    scanf("%d", &t);
    int n, k;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d%d", &n, &k);
        scanf("%s", s);
        printf("%ld\n", solve(n, k));
    }
    return 0;
}
