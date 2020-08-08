#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<omp.h>

using namespace std;

// primero asignaremos el tamaño de nuestro sistema de ecuaciones
int n = 3;

// Inicializaremos la Matriz de 2 dimenciones
float **Matriz = new float*[n],aux,TimeParalell;

// Crearemos una funcion para iniclizar con valoeres aleatorios nuestra matriz
void InitMatriz()
{
    for(int i=0;i<n+1;i++)
    {   
        Matriz[i] = new float[n + 1];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            Matriz[i][j] = (int)(rand() / (float)RAND_MAX * 20) + 1;      
        }      
    }    
}

// Crearemos una funcion que nos permita ver el contenido de nuestra matriz
void mostrarMatriz()
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            cout<< "\t" << Matriz[i][j];            
            if ( j == n - 1)
            {
                cout<<"\t|";
            }
        }
        cout<< "\n";
    }
}

// Pasemos a crear la funcion que le dara vida al metodo de Gauss-Jordan
void Gauss()
{   
    float T1 = omp_get_wtime();                                        // guardamos el tiempo de ejecucion openMP en un float
    #pragma omp parallel for                                           // Con esta linea indicamos donde comienza el buble que se ejecutara en paralelo
    for(int i=0;i<n;i++)
    {
        if(Matriz[i][i]!=0)                                            // En caso que algun elemento del sistema sea 0 no se ejecutra e imprimira un error.
        {
            aux = 1 / Matriz[i][i];                                    // A la variable aux le asinamos el reciproco del pivote.
            for(int j=0;j<n+1;j++)
            {
                Matriz[i][j]=aux*Matriz[i][j];                         // Multiplicamos todos los valores de las columnas i junto con la columna independiente  
            }                                                          // con auxiliar y los guardamos en la misma matriz, dejando en 1 la diagonal principal 
            
            for(int j=0;j<n;j++)                                       // comenzamos a obtener la matriz identidad columna por columna.
            {
                if(j!=i)                                               // Evitamos que la diagonal principal contenga algun 0
                {
                    aux=-Matriz[j][i];                                 // el auxiliar toma el valor negativo de los demas elementos de la columna
                    for(int k=0;k<n+1;k++)
                    {
                        Matriz[j][k]=Matriz[j][k]+aux*Matriz[i][k];    // Al sumarlos con su negativo, todos los elementos se hacen cero.
                    }                                                  // asi obtenemos la matriz identidad del sistema de ecuaciones o bien su solucion.
                }
            }
        } else{
            cout<<"\nHay un 0 en la matriz"<<endl;                     //mensaje de error
        }
        cout<<"El thread "<<omp_get_thread_num() << " esta trabajando"<<endl;   //indentificamos los Threads que estan trabajando. 
    }
    TimeParalell = omp_get_wtime() - T1;                                        // obtenemos el tiempo de ejecucion en paralelo. 
}

// ahora creamos una funcion para poder ver los resultados de una mejor forma.
void viewResultados()
{
    for(int i=0;i<n;i++)
    {
        cout<<"\nx"<< i + 1 <<" = "<< Matriz[i][n]<<endl;
    }
    cout<<"\nTiempo de ejecucion en paralelo: "<<TimeParalell<<" seg."<<endl;; 
}

// todas estas ultimas funciones las colocamos en orden en el metodo principal
int main()
{
    InitMatriz();
    omp_set_num_threads(4);     // <- Aqui asignamos el numero de Threads que trabajaran sobre el bucle en este caso solo usaremos 4.
    mostrarMatriz();
    Gauss();
    mostrarMatriz();
    viewResultados();
}