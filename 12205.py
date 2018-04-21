# -*- coding: utf-8 -*-
"""
Created on Wed Jan 25 22:01:04 2017

@author: Stéphane
"""

import sys
l=[]
c=0
while True:
    t=sys.stdin.readline()
    N, M=map(int, t.split())
    if N==0 and M==0:
        break
    for i in range(N):
        u=sys.stdin.readline()
        x, y, z, t=map(int, u.split())
        l+=[[z,z+t]]
    for i in range(M):
        v=sys.stdin.readline()
        start, duration=map(int, v.split())
        fin=duration+start
        for j in range(N):
            if not l[j][0]>=fin and not l[j][1]<=start:
                c+=1
        print(c)
        c=0
    l=[]
        
