"""
Algortimo para la resolucion de operaciones entre 2 polinomios
Ejercicio: Resolver la siguiente multiplicación de polinomios
P(x) = 7*x**3 + 2*x**2 + x - 7
Q(x) = x**2 + 3
"""

#Importamos la libreria SympY para usar variables simbolicas (x, y)
import sympy
import threading

#Definimos los simbolos

#Declaramos una funcion para cada operacion que querramos utilizar
class Threaded_worker(threading.Thread):
    P1 = input("Primer Polinomio: ")
    P2 = input("Segundo Polinomio: ")
    print("\n")
    sympy.init_printing()
    x,y = sympy.symbols('x,y')

    #Luego almacenamos en varibles los dos polinomios procesados por la funcion Poly de sympy
    Poly1 = sympy.Poly(P1)
    Poly2 = sympy.Poly(P2)
    def mult(p1, p2):
        #print('Hilo:', threading.current_thread().getName(), 'con identificador:', threading.current_thread().ident)
        print("resultado: ",p1*p2)
        return p1 * p2
    mult(Poly1,Poly2)
#Guardamos los valores retornados por las funciones y les pasamos los 2 polinomios como parametros,  Poly1 y Poly2

#Obtenes los dos polinomios introducidos por el usuario

NUM_HILOS =4

for i in range(NUM_HILOS):
    td = Threaded_worker()
    td.start()

