/**
 * File              : 21.cpp
 * Author            : recurze
 * Date              : 17:02 27.12.2018
 * Last Modified Date: 17:42 27.12.2018
 */

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

inline int f(int k, int i) {
    int res = 1;
    int sum = 1;
    while (!(k%i)) {
        k /= i;
        res *= i;
        sum += res;
    }
    return sum;
}

const int N = 1010101;
int sumOfDivisors[N] = {0};
void sieve(int n) {
    float m = sqrt(n);
    for (int i = 0; i <= n; ++i) {
        sumOfDivisors[i] = 1;
    }
    for (int i = 2; i <= n/2 + 1; ++i) {
        if (sumOfDivisors[i] == 1) {
            sumOfDivisors[i] = i + 1;
            for (int k = i << 1; k<= n; k += i) {
                sumOfDivisors[k] *= f(k, i);
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        if(sumOfDivisors[i] == 1)
            sumOfDivisors[i] += i;
        else
            sumOfDivisors[i] -= i;
    }
}

int main() {
    int t; scanf("%d", &t);
    int q[t], m = -1;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", q + tc);
        if (q[tc] > m) {
            m = q[tc];
        }
    }

    sieve(N);
    std::vector<int> amicable;
    for (int i = 3; i <= m; ++i) {
        if (i == sumOfDivisors[sumOfDivisors[i]] &&
            i != sumOfDivisors[i]) {
            amicable.push_back(i);
        }
    }

    std::vector<int> presum;
    presum.push_back(0);
    for (int i: amicable) {
        fprintf(stderr, "%d\n", i);
        presum.push_back(*(presum.end() - 1) + i);
    }
    int index = 0;
    for (int tc = 0; tc < t; ++tc) {
        index = std::lower_bound(amicable.begin(), amicable.end(), q[tc])
              - amicable.begin() - 1;
        printf("%d\n", presum[index + 1]);
    }
}
