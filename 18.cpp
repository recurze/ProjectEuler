/**
 * File              : 18.cpp
 * Author            : recurze
 * Date              : 16:35 27.12.2018
 * Last Modified Date: 16:44 27.12.2018
 */
#include <cstdio>
#include <vector>

int n;
const int N = 20;
std::vector<int> v[N];
int solve() {
    for (int i = n - 2; i > -1; --i) {
        for (int j = 0; j <= i; ++j) {
            v[i][j] += std::max(v[i + 1][j], v[i + 1][j + 1]);
        }
    }
    return v[0][0];
}

int main() {
    int t; scanf("%d", &t);
    int x;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            v[i].clear();
            for (int j = 0; j <= i; ++j) {
                scanf("%d", &x);
                v[i].push_back(x);
            }
        }
        printf("%d\n", solve());
    }
}
