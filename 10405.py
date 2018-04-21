# -*- coding: utf-8 -*-
"""
Created on Thu Feb  9 23:15:35 2017

@author: Stéphane
"""

import sys

def f(a,b):
    n=len(a)
    m=len(b)
    l=[[0 for j in range(m)] for i in range(n)]
    for i in range(1,n):
        for j in range(1,m):
            if a[i-1]==b[j-1]:
                l[i][j]=1+l[i-1][j-1]
            else:
                l[i][j]=max(l[i-1][j],l[i][j-1])
    return(l)


while True:
    a=str(sys.stdin.readline())
    if a=="":
        break
    b=str(sys.stdin.readline())
    print(f(a,b)[-1][-1])
