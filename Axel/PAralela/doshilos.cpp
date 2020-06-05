#include <pthread.h>
#include<cstdio>
#include<iostream>

using namespace std;
//copilar con g++ -o creath.x thread.cpp -lpthread
//La funcion  es print_x's el parametro por default
//es unused
int i;
struct doshilos{
    int idx;
};



void*print_xs(void*str){
    struct doshilos* p=(struct doshilos* ) str;
    int id=p->idx;
    i=0;
    while(i<=id){
        cout<<"x";
        i++;
    }
    return NULL;
}
void*print_os(void*str){
    struct doshilos* p=(struct doshilos* ) str;
    int id=p->idx;
    i=0;
    while(i<=id){
        cout<<"o";
        i++;
    }
    return NULL;
}
//main del programa


int main(){
    int i=0;
    //declaramos th1 tipo thread_t
    pthread_t th1,th2;
    doshilos st1;
    doshilos st2;
    st1.idx=50000;
    st2.idx=60000;
    
    //Crea un nuevo thread si es el numero 1, El nuevo thread llama a la funcion print_xs
    pthread_create (&th1,NULL,&print_xs,&st1);
    pthread_create (&th2,NULL,&print_os,&st2);
    //si no print o's continuously to stderr
    pthread_join(th1,NULL);
    pthread_exit(NULL);
    pthread_exit(NULL);
    cout<<"\n";
}