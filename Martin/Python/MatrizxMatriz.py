"""
Martín Márqux Cervantes
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

print("---------------Producto de Matrices--------------")
print("(M*n) * (N*p)")
print("\nMatriz (M x n)")
M = int(input("Ingrese Tamaño M: "))
n = int(input("Ingrese Tamaño n: "))
print("\nMatriz (N x p)")
N = int(input("Ingrese Tamaño N: "))
if n==N:
    P = int(input("Ingrese Tamaño p: "))
else:
    print("No se puede realizar el producto")
    exit(0)
