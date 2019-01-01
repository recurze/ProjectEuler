#!/usr/bin/env python
# -*- coding: utf-8 -*-
# File              : 29.py
# Author            : recurze
# Date              : 16:33 01.01.2019
# Last Modified Date: 20:52 01.01.2019

x = set()
n = int(raw_input())
ans = []
for a in xrange(2, n + 1):
    s = ''
    for b in xrange(2, n + 1):
        s += '01'[pow(a, b) in x]
        x.add(pow(a, b))
    ans.append(s)

for i, j in enumerate(ans):
    if j.count('1') > 0:
        print j
        print i+2, j.count('1')
