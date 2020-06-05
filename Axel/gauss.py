# -*- coding: utf-8 -*-
"""
Created on Thu Jun  4 19:13:01 2020

@author: Valenzuela
"""

import numpy as np

A=np.array([[10,-1,2,0],
            [-1,11,-1,3],
            [2,-1,10,-1],
            [0,3,-1,8]])

b=np.array([6,25,-11,15])

x=np.linalg.solve(A,b)

print(x)

