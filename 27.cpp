/**
 * File              : 27.cpp
 * Author            : recurze
 * Date              : 15:01 28.12.2018
 * Last Modified Date: 15:21 28.12.2018
 */
#include <cstdio>
#include <vector>
#include <cmath>

const int N = 1010101;
bool prime[N];
std::vector<int> primes;
void sieve(int n = N) {
    std::fill(prime, prime + n, 1);
    prime[0] = 0;
    prime[1] = 0;

    primes.push_back(2);
    for (int k = 4; k <= n; k += 2) {
        prime[k] = 0;
    }

    float m = sqrt(n);
    for (int i = 3; i <= m; i += 2) {
        if (prime[i]) {
            for (int k = i*i; k<= n; k += i) {
                prime[k] = 0;
            }
        }
    }
    for (int i = 3; i <= N; i += 2) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
}

inline bool isSquare(int n) {
    int s = sqrt(n);
    return s*s == n;
}

inline bool sameParity(int a, int b) {
    return (a&1) == (b&1);
}

int run(int a, int b) {
    int f = b;
    for (int i = 1; i < b; ++i) {
        f += a + 2*i - 1;
        if (!prime[f]) {
            return i;
        }
    }
    return b;
}

void solve(int n) {
    int d = 0, c = 0, max = -1;
    std::pair<int, int> ans;
    for (int b: primes) {
        if (b > n) {
            break;
        }
        for (int a = -n; a <= n; ++a) {
            d = a*a-4*b;
            if (isSquare(d) && sameParity(a, d)) {
                continue;
            }
            c = run(a, b);
            if (c > max) {
                max = c;
                ans = {a, b};
            }
        }
    }
    printf("%d %d\n", ans.first, ans.second);
}

int main() {
    int t = 1; //scanf("%d", &t);
    int n;
    sieve();
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        solve(n);
    }
}
