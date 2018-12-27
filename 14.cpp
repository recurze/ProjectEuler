/**
 * File              : 14.cpp
 * Author            : recurze
 * Date              : 12:35 27.12.2018
 * Last Modified Date: 14:45 27.12.2018
 */

#include <cstdio>
#include <algorithm>

const int N = 5050505;
int ans[N] = {0};
int run(long long n) {
    if (n == 1 || (n < N && ans[n])) return ans[n];
    int x;
    if (n&1) {
        x = run((3*n + 1)>>1) + 2;
    } else {
        x = run(n >> 1) + 1;
    }
    if (n < N) ans[n] = x;
    return x;
}

int main() {
    int t; scanf("%d", &t);
    int a[t];
    for (int tc = 0; tc < t; ++tc) { scanf("%d", &a[tc]); }
    int m = *std::max_element(a, a + t);
    for (int i = 0; i < m; ++i) { run(i + 1); }
    int max[m + 1] = {0, 1};
    for (int i = 2; i <= m; ++i) { 
        if (ans[max[i - 1]] <= ans[i]) {
            max[i] = i;
        } else {
            max[i] = max[i - 1];
        }
    }
    for (int i = 0; i < t; ++i) {
        printf("%d\n", max[a[i]]);
    }
}
