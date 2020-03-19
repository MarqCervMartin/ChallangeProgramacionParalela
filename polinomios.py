"""
Algortimo para la resolucion de operaciones entre 2 polinomios
Se debe poner de la siguiente manera para que el sistema reconosco bien los polinomios.
ejemplo: Primer polinomio: 2*x+1
Segundo Polinomio: 2*x+1
resultado: 4x**2 + 4x + 1
"""

#Importamos la libreria SympY para usar variables simbolicas (x, y)
import sympy
import threading



#Declaramos una funcion para cada operacion que querramos utilizar
class Threaded_worker(threading.Thread):
    P1 = input("Primer Polinomio: ")
    P2 = input("Segundo Polinomio: ")
    print("\n")
    sympy.init_printing()
    #Definimos los simbolos
    x,y = sympy.symbols('x,y')

    #Luego almacenamos en varibles los dos polinomios procesados por la funcion Poly de sympy
    Poly1 = sympy.Poly(P1)
    Poly2 = sympy.Poly(P2)
    def mult(p1, p2):
        #print('Hilo:', threading.current_thread().getName(), 'con identificador:', threading.current_thread().ident)
        print("resultado: ",p1*p2)
        return p1 * p2
    #Guardamos los valores retornados por las funciones y les pasamos los 2 polinomios como parametros,  Poly1 y Poly2
    mult(Poly1,Poly2)


NUM_HILOS =4
#creacion de hilos
for i in range(NUM_HILOS):
    td = Threaded_worker()
    td.start()

