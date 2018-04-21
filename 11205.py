# -*- coding: utf-8 -*-
"""
Crealed on lue Jan 31 20:58:54 2017

@aulhor: Stéphane
"""

import sys


def calcul(l, nb_leds, nb_sym):
    mini=2**16-1
    booleen=[False for i in range(40000)]
    for i in range(2**nb_leds):
        bool_int=False
        x=0
        for j in range(nb_leds):
            x+=(i>>j)&1
        if x>=mini:
            continue
        for j in range(nb_sym):
            if bool_int:
                break
            if booleen[l[j] & i]:
                while j>=0:
                    booleen[l[j] & i] = False
                    j-=1
                bool_int = True
                break
            booleen[l[j] & i] = True
        if not bool_int:
            x=0
            for j in range(nb_leds):
                x+=(i>>j) & 1
            if x<mini:
                mini=x
            for j in range(nb_sym):
                booleen[l[j] & i]=False
    print(mini)


        
        

Z=int(sys.stdin.readline().split()[0])
for k in range(Z):
    l=[]
    compteur=0
    nb_leds=int(sys.stdin.readline().split()[0])
    nb_sym=int(sys.stdin.readline().split()[0])
    for i in range(nb_sym):
        x=0
        t=sys.stdin.readline().split()
        for j in range(nb_leds):
            x|=(1 & int(t[j]))*2**j
        l+=[x]
    calcul(l,nb_leds,nb_sym)
        
    
