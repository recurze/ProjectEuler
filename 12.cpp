/**
 * File              : 12.cpp
 * Author            : recurze
 * Date              : 12:35 27.12.2018
 * Last Modified Date: 13:26 27.12.2018
 */

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>

const int N = 1010101;
std::vector<int> numberOfDivisors(N, 1);

int removeDinN(int n, int d) {
    int count = 0;
    while (!(n%d)) {
        n /= d;
        ++count;
    }
    return count;
}

void sieve(int n) {
    float m = sqrt(n);
    for (int i = 2; i <= m; ++i) {
        if (numberOfDivisors[i] == 1) {
            for (int k = i; k <= n; k += i) {
                numberOfDivisors[k] *= (removeDinN(k, i) + 1);
            }
        }
    }
    for (int i = 2; i < N; ++i) {
        if (numberOfDivisors[i] == 1) {
            ++numberOfDivisors[i];
        }
    }
}

inline int n_divisorsInTriangle(int n) {
    if (n&1) return numberOfDivisors[n]*numberOfDivisors[(n+1)>>1];
    return numberOfDivisors[n>>1]*numberOfDivisors[n+1];
}

int n_triangleDivisors[N];
void pre() {
    sieve(N);
    for (int i = 1; i < N; ++i) {
        n_triangleDivisors[i] = n_divisorsInTriangle(i);
    }
}

inline int triangle(int i) {
    if (i&1) return i*((i+1)>>1);
    return (i>>1)*(i + 1);
}
int solve(int k) {
    for (int i = 0; i < N; ++i) {
        if (n_triangleDivisors[i] > k) {
            return triangle(i);
        }
    }
    return 0;
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
