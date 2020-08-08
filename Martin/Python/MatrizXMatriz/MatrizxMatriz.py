"""
Martín Márquez Cervantes
1.- Producto de (1000)*(1100) x (1100)*(500)
    Dividir el producto entre cuatro
    Considere producto como vector renglón x vector columna
    Mostrar matriz C
    Paso intermedio, transpuesta de B (P*n)
    Ahora el producto sera de (M*P) productos vectoriales

    ------------Incluir------
    +Matriz leida desde archivo
    +Memoria dinamica para las matrices
    +Lenguaje Python
    +Optimización del programa

"""
import numpy as np
from threading import Thread as th

def archivoEscribir(X,Y,Nombre):
  fic = open(Nombre,"w")
  fic = open(Nombre,"a")
  for i in range(X):
    for j in range(Y):
      #print(i,file=fic)
      fic.write("1 ")
    fic.write("\n")
  fic.close()


def generarMatrices():
  print("\nMatriz (M x n)")
  M = int(input("Ingrese Tamaño M: "))
  n = int(input("Ingrese Tamaño n: "))
  print("\nMatriz (N x p)")
  N = int(input("Ingrese Tamaño N: "))
  if n==N:
      p = int(input("Ingrese Tamaño p: "))
      MatrizA = "loadMatrizA.txt"
      MatrizB = "loadMatrizB.txt"
      archivoEscribir(M, n, MatrizA)
      archivoEscribir(N, p, MatrizB)
  else:
      print("No se puede realizar el producto")
      exit(0)

def ejec_hilo(M,N,Q,ini,fin):
  for i in range(ini,fin):
    cij = float(0)
    for j in range(N.shape[0]):
      cij = M[i].dot(N[j])
      Q[i,j] = cij
  return

  
if __name__ == "__main__":
  print("---------------Producto de Matrices--------------")
  print("(M*n) * (N*p)")
  generarMatrices()
  threads = []
  A = np.loadtxt("loadMatrizA.txt",skiprows=0,delimiter=None,dtype=float)
  B = np.loadtxt("loadMatrizB.txt",skiprows=0,delimiter=None,dtype=float)
  C = np.zeros((A.shape[0],B.shape[1]),dtype=float)
  Bt = np.array((B.shape[1],B.shape[0]),dtype=float)
  Bt = B.T
  for i in range(4):
    ini = int(i*25)
    fin = int(ini+25)
    t = th(target = ejec_hilo, args = (A,Bt,C,ini,fin))
    threads.append(t)
    t.start()
    t.join()
  print(C)
    
    
    
    
    
    
    
    
  
  
  
  
  
  