#!/usr/bin/env python
# -*- coding: utf-8 -*-
# File              : 28.py
# Author            : recurze
# Date              : 17:37 28.12.2018
# Last Modified Date: 17:41 28.12.2018

# Ans: 1 + 4k + 2k(k + 1)(8k + 7)/3
MD = 10**9+7
for _ in xrange(int(raw_input())):
    k = (int(raw_input()) - 1) >> 1;
    k %= MD
    ans = (1 + 4*k)%MD
    ans += ((2*k)%MD * (k+1) * ((k<<3) + 7)%MD * pow(3, MD - 2, MD)) % MD
    if ans >= MD:
        ans -= MD
    print ans
