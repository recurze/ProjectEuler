/**
 * File              : 10.cpp
 * Author            : recurze
 * Date              : 15:28 26.12.2018
 * Last Modified Date: 15:47 26.12.2018
 */

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

std::vector<int> primes;
std::vector<long long> presum;

const int N = 2020202;
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
    primes.push_back(2);
    presum.push_back(2);
    for (int i = 3; i < n; ++i) {
        if (prime[i]) {
            primes.push_back(i);
            presum.push_back(*(presum.end() - 1) + i);
        }
    }
    fprintf(stderr, "Primes below %d: %d\n", N, primes.size());
}

inline long long solve(int n) {
    int index = std::upper_bound(primes.begin(), primes.end(), n)
                - primes.begin() - 1;
    return presum[index];
}
int main() {
    int t;
    scanf("%d", &t);
    int n;
    sieve(N);
    while (t--) {
        scanf("%d", &n);
        printf("%ld\n", solve(n));
    }
    return 0;
}
