# -*- coding: utf-8 -*-
"""
Created on Tue Jan 24 15:45:12 2017

@author: Stéphane
"""
import sys
for line in sys.stdin:
    a,b=map(int,line.split())
    print(abs(b-a))
