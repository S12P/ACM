# -*- coding: utf-8 -*-
"""
Created on Tue Jan 31 22:26:41 2017

@author: Stéphane 
"""

import sys
nb_premier=[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]


def calcul(nb,nb_int,liste,dejavu,ens):
    if nb_int<nb:
        for i in ens:
            if not dejavu[i] and i + liste[nb_int-1] in nb_premier:
                dejavu[i] = True
                liste.append(i)
                calcul(nb,nb_int+1,liste,dejavu,ens)
                liste.pop()
                dejavu[i] = False 
    elif nb_int==nb and liste[-1]+liste[0] in nb_premier:
        x=""
        for k in range(len(liste)):
            if x=="":
                x=str(liste[k])
            else:
                x=x+" "+str(liste[k])
        print(x)



c=1
while True:
    t=sys.stdin.readline().split()
    if t==[]:
        break
    nb=int(t[0])
    ens=[i for i in range(1,nb+1)]
    dejavu = [ False for i in range(nb+1) ]
    dejavu[1]=True
    if c!=1:
        print("")
    print("Case %s:"%c)
    calcul(nb,1,[1],dejavu,ens)
    c+=1

