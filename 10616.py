# -*- coding: utf-8 -*-
"""
Created on Sun Feb 12 12:51:09 2017

@author: Stéphane
"""
import sys
N_liste=[0 for k in range(201)]
matrice=[[[0 for k in range(21)] for k in range(21)]for k in range(201)]
compteur=1
while True:
    t=sys.stdin.readline().split()
    if t==['0','0']:
        break
    print("SET %s:" % compteur)
    compteur+=1
    N, Q=map(int, t)
    for k in range(1,N+1):
        N_liste[k]=int(sys.stdin.readline().split()[0])
    for k in range(Q):
        t=sys.stdin.readline().split()
        D, M=map(int, t)
        for i in range(N+1):
            matrice[i][0][0]=1
        for i in range(1,N+1):
            for j in range(1,M+1):
                for l in range(D):
                    x=(l-N_liste[i]%D)%D
                    if x>=0:
                        matrice[i][j][l]=matrice[i-1][j][l]+matrice[i-1][j-1][x]
                    else:
                        matrice[i][j][l]=matrice[i-1][j][l]+matrice[i-1][j-1][x+D]
        print("QUERY %s:" % (k+1), matrice[N][M][0])
