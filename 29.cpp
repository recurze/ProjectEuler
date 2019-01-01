/**
 * File              : 29.cpp
 * Author            : recurze
 * Date              : 21:25 01.01.2019
 * Last Modified Date: 21:38 01.01.2019
 */

#include <cstdio>
#include <cmath>
#include <vector>

int countRepeats(int n, int k) {
    int count = 0, t = k;

    for (int j = 2; j <= n; ++j) {
        t += k;
        for (int i = 1; i < k; ++i) {
            if (t%i == 0 && t/i <= n) {
                ++count;
                break;
            }
        }
    }

    return count;
}

long long solve(int n) {
    std::vector<int> repeat;

    for (int i = 4, j = 2; i <= n; ++j, i <<= 1) {
        repeat.push_back(countRepeats(n, j));
    }

    bool visited[n + 1] = {0};
    float m = sqrt(n);
    long long ans = 1L * (n - 1) * (n - 1);

    for (int i = 2; i <= m; ++i) {
        if (visited[i]) continue;
        for (int j = i*i, k = 2; j <= n; ++k, j *= i) {
            if (visited[j]) continue;
            ans -= repeat[k - 2];
            visited[j] = 1;
        }
    }

    return ans;
}

int main() {
    int t = 1; //scanf("%d", &t);
    int n;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        printf("%ld\n", solve(n));
    }
}
