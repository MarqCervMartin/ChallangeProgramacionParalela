/*
Funciones Run time                          Descripción
void omp_set_num_threads( int )             Establece el número de hilos.
int omp_get_num_threads( void )             Regresa el número de hilos.
int omp_get_thread_num( void )              Regresa el identificador del hilo.
int omp_get_num_procs( void )               Regresa el número de procs.

Variables de Ambiente                       Ejemplo
OMP_NUM_THREADS                             8

*/
#include<cstdio>
#include<iostream>
#include<pthread.h>
#include<omp.h>
using namespace std;

int main(int argc,char * argv[])
{   
    //Declaramos el número de threads
    omp_set_num_threads(6);
    int Mat1[100][100];
    int Mat2[100][100];

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            Mat2[i][j]=1;
            Mat1[i][j]=1;
        }
    }
    int aux=0;
    int c[100][100];
    #pragma omp parallel for reduction(+:aux)
    for(int i = 0 ; i <100; i++){   
            for(int j=0;j<100;j++){
                c[i][j]=Mat1[i][j]*Mat2[j][i];
                aux+=c[i][j];
            }
        }
    
    cout<<"Producto: "<<aux;  
    return 0;
}
