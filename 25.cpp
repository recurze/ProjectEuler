/**
 * File              : 25.cpp
 * Author            : recurze
 * Date              : 14:02 28.12.2018
 * Last Modified Date: 14:15 28.12.2018
 */
#include <cstdio>
#include <cmath>

//F(n) = [phi^n/5^0.5]
//nD(n) = log(n)/log(10) + 1
//nD(F(n)) = nlog(phi) - 0.5log5 + 1

double phi = (1 + sqrt(5))/2.0;

double lp = log(phi)/log(10);
double l5 = 0.5*log(5)/log(10);

int solve(int n) {
    //fprintf(stderr, "%d %lf %lf\n", n, l5, lp);
    double res = (n - 1 + l5)/lp;
    //fprintf(stderr, "%lf\n", res);
    return floor(res) + 1;
}

int main() {
    int t; scanf("%d", &t);
    int n;
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        printf("%d\n", solve(n));
    }
}
