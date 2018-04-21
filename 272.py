# -*- coding: utf-8 -*-
"""
Created on Tue Jan 24 16:39:48 2017

@author: Stéphane
"""
import sys
t=sys.stdin.read()
c=0
i=0
while i<len(t):
    if t[i]=='"' and c==0:
        t=t[:i]+"``"+t[(i+1):]
        c=1
    elif t[i]=='"' and c==1:
        t=t[:i]+"''"+t[(i+1):]
        c=0
    i+=1
print(t,end="")
            
