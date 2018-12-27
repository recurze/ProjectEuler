/**
 * File              : 16.cpp
 * Author            : recurze
 * Date              : 16:19 27.12.2018
 * Last Modified Date: 16:24 27.12.2018
 */
#include <cstdio>

const int N = 10101;
char s[N] = "1";
int sumOfDigits() {
    int sum = 0;
    for (int i = 0; s[i]; ++i) {
        sum += (s[i] - '0');
    }
    return sum;
}

void multiply() {
    int carry = 0, n, i;
    for (i = 0; s[i]; ++i) {
        n = 2*(s[i] - '0') + carry;
        s[i] = '0' + n%10;
        carry = n/10;
    }
    while (carry) {
        s[i++] = '0' + carry%10;
        carry /= 10;
    }
}
int main() {
    int t; scanf("%d", &t);
    int n, a[t], m = -1;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", a + tc);
        if (a[tc] > m) {
            m = a[tc];
        }
    }
    int ans[m + 1];
    for (int i = 0; i <= m; ++i) {
        ans[i] = sumOfDigits();
        multiply();
    }
    for (int tc = 0; tc < t; ++tc) {
        printf("%d\n", ans[a[tc]]);
    }
}
