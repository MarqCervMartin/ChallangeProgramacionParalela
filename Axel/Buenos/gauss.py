# -*- coding: utf-8 -*-
"""
Created on Thu Jun  4 19:13:01 2020

@author: Valenzuela
"""
import numpy as np
from threading import Thread

def hilo(itera,m,n,r,matrix):
    k=0
    while k<itera:
        suma=0
        k=k+1
        for r in range(0,m):
            suma=0
            for c in range(0,n):
                if (c != r):
                    suma=suma+matrix[r,c]*x[c]               
            x[r]=(vector[r]-suma)/matrix[r,r]
        del error[:]
    for i in range(0,m):
        print("x["+str(i)+"]: "+str(x[i]))

m=int(input('Valor de m:'))#renglones
n=int(input('Valor de n:'))#columnas
matrix = np.zeros((m,n))#matriz coeficientes
x=np.zeros((m))#solucion

vector= np.zeros((n))
comp=np.zeros((m))
error=[]

print ('Método de Gauss-Seidel')
print ('Introduce la matriz de coeficientes y el vector solución')
for r in range(0,m):
    for c in range(0,n):
        matrix[(r),(c)]=float(input("Elemento a["+str(r+1)+str(c+1)+"] "))
    vector[(r)]=float(input('b['+str(r+1)+']: '))
print ("Método de Gauss-Seidel")

tol=float(input("cual es la tolerancia deseada?: "))
itera=int(input("Cual es el numero maximo de iteraciones?: "))

t = Thread(target=hilo, args=(itera,m,n,r,matrix))
t.start()
t.join()         
#print(matrizr)