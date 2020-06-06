# -*- coding: utf-8 -*-
"""
Created on Fri Jun  5 17:34:11 2020

@author: Valenzuela
"""

import numpy as np
import sys

from threading import Thread

def hilo(A,B,C,r1,c2,r2):
    for r in range(0,r1):
        for c in range (0,c2):
            for k in range(0,r2): #acumulacion de suma
                matrizr[r,c]+=matriz1[r,k]*matriz2[k,c]
    print (matrizr)


print("Este progrma hace l amultiplicacion  entre matrices con prog paralela")
r1=int(input('numro de renglones de la matriz 1: '))
c1=int(input('numro de columnas de la matriz 1: '))
r2=int(input('numro de renglones de la matriz 2: '))
c2=int(input('numro de columnas de la matriz 2: '))

#se verifica si se puede hacer la multiplicacion
if(c1 != r2):
    print("no se puede hacer la multiplicacion de matrices")
    sys.exit()
matriz1=np.zeros((r1,c1))
matriz2=np.zeros((r2,c2))
matrizr=np.zeros((r1,c2))
#matriz 1
print("introduce los elementos de la matriz 1")
for i in range(0,r1):#ciclo para meter datos en todos los renglones
    for c in range (0,c1):#meter datos en todas las columnas
        matriz1[i,c]=input("Elemento a["+str(i+1)+" "+str(c+1)+"]: ")
#matriz 2
print("introduce los elementos de la matriz 2")
for i in range(0,r2):#ciclo para meter datos en todos los renglones
    for c in range (0,c2):#meter datos en todas las columnas
        matriz2[i,c]=input("Elemento a["+str(i+1)+" "+str(c+1)+"]: ")

#for r in range(0,r1):
   # for c in range (0,c2):
    #    for k in range(0,r2): #acumulacion de suma
 #           matrizr[r,c]+=matriz1[r,k]*matriz2[k,c]
t = Thread(target=hilo, args=(matriz1,matriz2,matrizr,r1,c2,r2))
t.start()
t.join()         
#print(matrizr)