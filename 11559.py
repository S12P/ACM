# -*- coding: utf-8 -*-
"""
Created on Wed Jan 25 11:08:02 2017

@author: Stéphane
"""

import sys
while True:
    resultat="stay home"
    t=sys.stdin.readline()
    if t=="":
        break
    nb_personne, budget, nb_hotel, nb_wd=map(int, t.split())
    for k in range(nb_hotel):
        prix=int(sys.stdin.readline().split()[0])
        l=sys.stdin.readline().split()
        if nb_personne*prix<=budget:
            for x in l:
                if int(x)>=nb_personne and (resultat=="stay home" or resultat>(nb_personne*prix)):
                    resultat=nb_personne*prix
                    budget_min=prix
    print(resultat)
