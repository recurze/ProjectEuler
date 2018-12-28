/**
 * File              : primeFactorizationOfNnumbers.cpp
 * Author            : recurze
 * Date              : 12:09 28.12.2018
 * Last Modified Date: 12:54 28.12.2018
 */

#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>

const int N = 1010101;
std::vector< std::pair<int, int> > primeFactorization[N];

inline int removeDinN(int& n, int d) {
    int count = 0;
    if (d == 2) {
        count = __builtin_ctz(n);
        n >>= count;
        return count;
    }
    while (!(n%d)) {
        n /= d;
        ++count;
    }
    return count;
}

void sieve(int n = N) {
    int residue[N];
    for (int i = 2; i <= n; ++i) {
        residue[i] = i;
    }

    float m = sqrt(n);
    for (int i = 2; i <= m; ++i) {
        if (primeFactorization[i].empty()) {
            for (int j = 2*i; j <= n; j += i) {
                primeFactorization[j].push_back(
                        {i,removeDinN(residue[j],i)});
            }
        }
    }

    primeFactorization[2].push_back({2, 1});
    for (int i = 3; i <= n; i += 2) {
        if (residue[i] - 1) {
            primeFactorization[i].push_back({residue[i], 1});
        }
    }
}

std::vector<int> primes;
bool prime[N];
void generatePrimeList(int n = N) {
    prime[0] = prime[1] = 0;
    std::fill(prime + 2, prime + n, 1);

    for (int k = 4; k <= n; k += 2) {
        prime[k] = 0;
    }

    float m = sqrt(n);
    for (int i = 3; i <= m; i += 2) {
        if (prime[i]) {
            primes.push_back(i);
            for (int k = i*i; k <= n; k += i) {
                prime[k] = 0;
            }
        }
    }
}

void trialDivision(int x) {
    int k = 0, n = x;
    for (const int& i: primes) {
        if (i*i > n) {
            break;
        }
        k = removeDinN(n, i);
        if (k) primeFactorization[x].push_back({i, k});
    }
    if (n - 1) primeFactorization[x].push_back({n, 1});
}

int main() {
    using milli = std::chrono::milliseconds;
    auto start = std::chrono::high_resolution_clock::now();
    //sieve();
    generatePrimeList();
    for (int i = 2; i < N; ++i) {
        trialDivision(i);
    }
    finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<milli>(finish-start).count()
              << '\n';
    return 0;
}
