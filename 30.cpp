/**
 * File              : 30.cpp
 * Author            : recurze
 * Date              : 22:35 01.01.2019
 * Last Modified Date: 22:43 01.01.2019
 */

#include <cstdio>

int pow(int i, int n) {
    int res = 1;
    while (n--) {
        res *= i;
    }
    return res;
}

bool f(int i, int n) {
    int a = 0, temp = i;
    while (i) {
        a += pow(i%10, n);
        i /= 10;
    }
    return a == temp;
}

int upperLim(int n) {
    return n * pow(9, n);
}

int solve(int n) {
    int l = upperLim(n), ans = 0;

    for (int i = 10; i <= l; ++i) {
        ans += f(i, n)*i;
    }

    return ans;
}

int main() {
    int t = 1; //scanf("%d", &t);
    int n;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
}
