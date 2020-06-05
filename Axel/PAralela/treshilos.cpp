#include <pthread.h>
#include<cstdio>
#include<iostream>
#include <fstream>


using namespace std;
//copilar con g++ -o creath.x thread.cpp -lpthread
//La funcion  es print_x's el parametro por default
//es unused
int i;
struct doshilos{
    int idx;
};

void* escribirArchivo(void* str){
    
    ofstream archivo;  // objeto de la clase ofstream

    archivo.open("datos.txt");
    for(int i=0;i<10001;i++){
    archivo << i<<" ";
    }
    archivo.close();
}
  string arr[10010];//poner tamaño


void*print_xs(void*str){
    struct doshilos* p=(struct doshilos* ) str;
    int id=p->idx;
    int i =0;
  
    char cadena[128];
    ifstream fe("/home/axel/Documentos/PAralela/datos.txt");
    while (!fe.eof()) {
        
        fe >> cadena;
        //cout << cadena << endl;
        arr[i]=cadena;
        i++;
    }
    fe.close();
}
void*print_os(void*str){
    struct doshilos* p=(struct doshilos* ) str;
    int id=p->idx;
    for(int i=0;i<10000;i++){
        cout<<arr[i];
    }
    
}
//main del programa



int main(){
    
    int i=0;
    //declaramos th1 tipo thread_t
    pthread_t th1,th2,th3;
    doshilos st1;
    doshilos st2;
    doshilos st3;
    st1.idx=50000;
    st2.idx=60000;
    
    //Crea un nuevo thread si es el numero 1, El nuevo thread llama a la funcion print_xs
    pthread_create (&th1,NULL,&print_xs,&st1);
    pthread_create (&th2,NULL,&print_os,&st2);
    pthread_create (&th3,NULL,&escribirArchivo,&st3);
    //si no print o's continuously to stderr
    pthread_join(th1,NULL);
    pthread_exit(NULL);
    pthread_exit(NULL);



    
    cout<<"\n";
}