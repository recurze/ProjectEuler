/**
 * File              : 24.cpp
 * Author            : recurze
 * Date              : 13:15 28.12.2018
 * Last Modified Date: 13:27 28.12.2018
 */

#include <iostream>
#include <string>
#include <algorithm>

std::string toFactorialNS(int n) {
    std::string res = "";
    int d = 1;
    while (n) {
        res += n%d + '0';
        n /= d++;
    }
    std::reverse(res.begin(), res.end());
    return res;
}


std::string s = "abcdefghijklm";
std::string solve(int n) {
    std::string res = "", fs = toFactorialNS(n);
    for (int i = 0; i < 13 - fs.size(); ++i) {
        res += s[0];
        s.erase(std::remove(s.begin(), s.end(), s[0]), s.end());
    }
    for (char c: fs) {
        res += s[c - '0'];
        s.erase(std::remove(s.begin(), s.end(), s[c-'0']), s.end());
    }
    return res;
}

int main() {
    int t; std::cin>>t;
    int n;
    for (int tc = 0; tc < t; ++tc) {
        std::cin>>n;
        s = "abcdefghijklmn";
        std::cout<<solve(n-1)<<'\n';
    }
}
