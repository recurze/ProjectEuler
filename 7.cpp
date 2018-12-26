/**
 * File              : 7.cpp
 * Author            : recurze
 * Date              : 14:05 26.12.2018
 * Last Modified Date: 14:10 26.12.2018
 */

#include <cstdio>
#include <vector>
#include <cmath>

std::vector<int> primes;

const int N = 1010101;
bool prime[N];
void sieve(int n) {
    std::fill(prime, prime + n, 1);
    prime[0] = 0;
    prime[1] = 0;
    float m = sqrt(n);
    for (int i = 2; i <= m; ++i) {
        if (prime[i]) {
            for (int k = i*i; k<= n; k += i) {
                prime[k] = 0;
            }
        }
    }
    for (int i = 2; i < n; ++i) {
        if (prime[i])
            primes.push_back(i);
    }
    fprintf(stderr, "Primes below 1010101: %d\n", primes.size());
}

inline int solve(int n) {
    return primes[n - 1];
}

int main() {
    int t;
    scanf("%d", &t);
    int n;
    sieve(N);
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}
