/*
UNIVERSIDAD AUTONOMA DEL ESTADO DE MÉXICO
CENTRO UNIVERSITARIO UAEM ZUMPANGO
SISTEMAS OPERATIVOS
PROFESOR: MANUEL ALMEIDA
Axel Valenzuela
*/

#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;

int total=0;
int v1[10000];
int v2[10000];

struct operacion{
     int inicio=0,fin=0;
};

void* multmatriz(void* parameters){
	struct operacion* p = (struct operacion*) parameters;
	for(int i = p->inicio; i <= p->fin; ++i){
		total = total + (v1[i] * v2[i]);
	}
}

int main(){
	int numVals = 10000;
	int hilos = numVals/4;

	for (int i = 0; i < 10000; i++){
		v1[i] = 1;
		v2[i] = 1;
	}
	
     	struct operacion record[hilos];

	int val = 0;
	for (int i = 0; i < 4;i++){
		record[i].inicio = val;
		val = val + hilos;
		if(i == 3){
			record[i].fin = val;
		}else{
			record[i].fin = val-1;
		}
	}
 	pthread_t th[4];
	for(int i = 0; i < 4; i++){
		pthread_create(&th[i], NULL, &multmatriz, &record[i]);
		pthread_join(th[i], NULL);
	}
	cout<<total<<endl;
	return 0;
}
