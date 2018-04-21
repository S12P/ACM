# -*- coding: utf-8 -*-
"""
Created on Sat Feb  4 19:00:26 2017

@author: Stéphane
"""
import sys
def egalite(t,m,volume):
    i=0
    c=0
    for k in range(len(t)):
        c+=t[k]
        if t[k]>volume:
            return(False)
        elif c>volume:
            i+=1
            c=t[k]
    i+=1
    return(i<=m)
    
def dichotomie(deb,fin,t,m):
    while deb<fin+1:
        if egalite(t,m,deb+((fin-deb)/2)):
            maxi=deb+((fin-deb)/2)
            fin=maxi-1
        else:
            deb=deb+((fin-deb)/2)+1
    return(int(maxi))
    
while True:
    L=[]
    total_volume=0
    t=sys.stdin.readline().split()
    if t==[]:
        break
    n, m=map(int, t)
    t=sys.stdin.readline().split()
    if m>=n:
        print(max(t))
    else:
        for k in range(len(t)):
            t[k]=int(t[k])
            total_volume+=int(t[k])
        print(dichotomie(0,total_volume,t,m))
    
