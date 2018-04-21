# -*- coding: utf-8 -*-
"""
Created on Fri Jan 27 11:07:48 2017

@author: Stéphane
"""

def compter(n,p,lp,c):
    l=[]
    for k in range(n):
        for m in range(1,len(lp[0])):
            l+=[lp[k][m]]
    for k in range(n):
        if l.count(k+1)!=p:
            c[k]+=1
    return(c)
        
def somme(l):
    e=0
    for k in range(len(l)):
        if l[k]>0:
            e+=1
    return(e)
    
    
   
    
l=[]
lt=[]
import sys
message="NO PROBLEMS FOUND"
message_bis="PROBLEMS FOUND"
nb=[]
while True:
    K, N=map(int,sys.stdin.readline().split())
    error=[0 for i in range(N)]
    if K==0 and N==0:
        break
    for i in range(N):
        t=sys.stdin.readline().split()
        l+=[t]
        for j in range(1,len(l[0])):
            l[i][j]=int(l[i][j])
            if l[i][j]==i+1:
                error[i]+=1
            if l[i][j]=
    error=compter(N,K,l,error)
    error=somme(error)
    if error==0:
        print(message)
    elif error==1:
        print("1 PROBLEM FOUND")
    else:
        print(error, message_bis)
    l=[]
    lt=[]
    error=0


            
            
        
