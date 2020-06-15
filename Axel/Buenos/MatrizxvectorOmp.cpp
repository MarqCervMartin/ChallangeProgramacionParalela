#include<pthread.h>
#include<omp.h>
#include<cstdio>
#include<iostream>
//g++ MatrizxvectorOmp.cpp -fopenmp
using namespace std;

int main(int argc,char * argv[])
{   
    omp_set_num_threads(2);
    int Matriz[100][100];
    int Matriz2[100];
    int prod;
    //struct p = (struct Str);
	int sumas = 0;

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            Matriz2[i]=1;
            Matriz[i][j]=1;
        }
    }
    int b=0;
    int c[100][100];
    #pragma omp parallel for reduction(+:b)
    for(int i = 0 ; i <100; i++)
	    {   
            for(int j=0;j<100;j++){
                c[i][j]=Matriz[i][j]*Matriz2[i];
                b+=c[i][j];
            }        
           
        }
    
    cout<<"resultado: "<<b;  
    return 0;
}