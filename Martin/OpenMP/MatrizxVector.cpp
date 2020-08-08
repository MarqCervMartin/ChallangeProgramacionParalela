#include <iostream>
#include <omp.h>

using namespace std;
int main(){

    //Declaracion de número de threads
    omp_set_num_threads(6);
    int Mat[100][100];
    int Vect[100];
    //Llenamos con unos
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            Vect[i]=1;
            Mat[i][j]=1;
        }
    }
    int aux=0;
    int c[100][100];
    #pragma omp parallel for reduction(+:aux)
    for(int i = 0 ; i <100; i++){   
            for(int j=0;j<100;j++){
                c[i][j]=Mat[i][j]*Vect[i];
                aux+=c[i][j];
            } 
        }
    
    cout<<"Producto: "<<aux;  
    return 0;
}