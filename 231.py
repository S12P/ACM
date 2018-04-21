# -*- coding: utf-8 -*-
"""
Created on Tue Jan 31 16:19:41 2017

@author: Stéphane
"""

import sys

def programmation_dyn(l, nb_interception, maxi):
    if len(l)==0:
        return(nb_interception)
    else:
        if l[0]<=maxi:
            return(max(programmation_dyn(l[1:], nb_interception+1,l[0]),programmation_dyn(l[1:], nb_interception,maxi)))
        else:
            return(max(programmation_dyn(l[1:],1,l[0]),programmation_dyn(l[1:],nb_interception,maxi)))
            
        

k=1
l=[]
while True:
    if k!=1:
        print("")
    while True:
        t=sys.stdin.readline().split()
        if int(t[0])==(-1):
            break
        l+=[int(t[0])]
    x=programmation_dyn(l, 0, 32768)
    print("Test #%s:" % k)
    print("  maximum possible interceptions:",x)
    k+=1
    t=sys.stdin.readline().split()
    if int(t[0])==(-1):
        break
    else:
        l=[int(t[0])]

    
