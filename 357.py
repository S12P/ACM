# -*- coding: utf-8 -*-
"""
Created on Tue Feb  7 15:00:47 2017

@author: Stéphane
"""
import sys
piece=[1,5,10,25,50]
n=30001
m=[[0 for i in range(n)] for j in range(5)]
for i in range(5):
	m[i][0]=1
for j in range(n):
	m[0][j]=1
for coins in range(1,5):
	for somme in range(1,n):
        	if somme-piece[coins]>=0:
                	m[coins][somme]+=m[coins][somme-piece[coins]]
        	m[coins][somme]+=m[coins-1][somme]


while True:
    t=sys.stdin.readline().split()
    if t==[]:
        break
    t=int(t[0])
    x=m[4][t]
    if x==1:
        print("There is only 1 way to produce",t, "cents change."+"")
    else:
        print("There are",x, "ways to produce",t ,"cents change."+"")


