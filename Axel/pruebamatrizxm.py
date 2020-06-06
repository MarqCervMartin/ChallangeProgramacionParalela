# -*- coding: utf-8 -*-
"""
Created on Fri Jun  5 18:19:52 2020

@author: Valenzuela
"""

import math
from threading import Thread

def hilo(A,B,C):
    for k in range(0,2):
        for j in range(0,2):
            for i in range(0,2):
                C[k][j] += A[k][i] * B[i][j]
    print (C)


print ("Por default son 2 filas  y 2 columnas para ambas matrices")
print ("Matriz Numero 1: ")
matriz = []
matriz3 = []
matriz2 = []
for i in range(0,2):
    tmp = []
    tmp2 = []
    for j in range(0,2):
        elemento = int(input("Elemento %d,%d : " % (i,j)))
        tmp.append(elemento)
        elemento = 0
        tmp2.append(elemento)
        matriz.append(tmp)
        matriz3.append(tmp2)

print ("Matriz Numero 2: ")
for i in range(0,2):
    tmp3 = []
    for j in range(0,2):
        elemento = int(input("Elemento %d,%d : " % (i,j)))
        tmp3.append(elemento)
        matriz2.append(tmp3)

t = Thread(target=hilo, args=(matriz,matriz2,matriz3))
t.start()
t.join()