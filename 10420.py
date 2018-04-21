# -*- coding: utf-8 -*-
"""
Created on Wed Jan 25 20:40:42 2017

@author: Stéphane
"""

import sys

Pays=[]
P=[]
N=sys.stdin.readline()
for line in sys.stdin:
    l=line.split()[0]
    Pays+=[l]
    if l not in P:
        P+=[l]
    P.sort()
for k in range(len(P)):
    print(P[k],Pays.count(P[k]))
