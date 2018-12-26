/**
 * File              : 4.cpp
 * Author            : recurze
 * Date              : 13:03 26.12.2018
 * Last Modified Date: 13:48 26.12.2018
 */

#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

inline bool isPalindrome(int n) {
    std::string s = std::to_string(n);
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return 0;
        }
    }
    return 1;
}

std::vector<int> palindromes;
int np;
inline void pre() {
    int n;
    for (int i = 100; i < 1000; ++i) {
        for (int j = 100; j < 1000; ++j) {
            n = i * j;
            if (isPalindrome(n)) {
                palindromes.push_back(n);
            }
        }
    }
    std::sort(palindromes.begin(), palindromes.end());
    np = palindromes.size();
}

inline int solve(int n) {
    for (int i = 0; i < np; ++i) {
        if (palindromes[i] >= n) {
            return palindromes[i - 1];
        }
    }
    return palindromes[np - 1];
}

int main() {
    pre();
    fprintf(stderr, "# palindromes %d", palindromes.size());
    int t = 0;
    scanf("%d", &t);
    int n = 0, ans;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        ans = solve(n);
        printf("%d\n", ans);
    }
    return 0;
}
