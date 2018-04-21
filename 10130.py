# -*- coding: utf-8 -*-
"""
Created on Sat Feb 11 14:44:29 2017

@author: Stéphane
"""

import sys

    
def sac_a_dos(p,w,g):
    m=[[0 for k in range(max(g)+1)] for k in range(len(p))]
    for i in range(len(p)):
        for j in range(max(g)+1):
            if j>=w[i]:
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+p[i])
            else:
                m[i][j]=m[i-1][j]
    return(m)


while True:
    t=sys.stdin.readline().split()
    if t==[]:
        break
    T=int(t[0])
    for k in range(T):
        p=[]
        w=[]
        t=sys.stdin.readline().split()
        N=int(t[0])
        for i in range(N):
            t=sys.stdin.readline().split()
            P,W=map(int, t)
            p.append(int(t[0]))
            w.append(int(t[1]))
        t=sys.stdin.readline().split()
        G=int(t[0])
        g=[]
        for k in range(G):
            t=sys.stdin.readline().split()
            G=int(t[0])
            g.append(G)
        prix=0
        m=(sac_a_dos(p,w,g))
        for k in range(len(g)):
            prix+=m[-1][g[k]]
        print(prix)
