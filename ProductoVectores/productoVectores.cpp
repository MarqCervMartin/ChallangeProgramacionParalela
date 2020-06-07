#include<pthread.h>
#include<cstdio>
#include<iostream>

using namespace std;
struct estru1
{
	/* data */
	int up;
    int down;
};

int sumas = 0;
float m1[10000];
float m2[10000];

void* sumar(void* str)
{
	struct estru1* p=(struct estru1*)str;
	int aux = 0;
	int suma=0;
	for (int i = p->down; i < p->up; i++)
	{
		aux = m1[i] * m2[i];
		suma = suma + aux; 
	}
	sumas = sumas + suma;
	return (void*) suma;
}
int main(int argc, char const *argv[])
{
    int sum0,sum1,sum2,sum3;
    sum0=sum1=sum2=sum3=1;
	pthread_t t[4];
	estru1 st[4];
	st[0].up=2500;
	st[0].down=0;
	for (int i = 1; i <= 4; i++)
	{
		st[i].up = st[i-1].up + 2500;
		st[i].down = st[i-1].down + 2500;
	}

    for (int i = 0; i < 10000; i++)
    {
        m1[i] = 1;
        m2[i] = 1; 
    }

	pthread_create(&t[0],NULL,&sumar,&st[0]);
	pthread_create(&t[1],NULL,&sumar,&st[1]);
    pthread_create(&t[2],NULL,&sumar,&st[2]);
	pthread_create(&t[3],NULL,&sumar,&st[3]);
	pthread_join(t[0],(void**) &sum0);
	pthread_join(t[1],(void**) &sum1);
    pthread_join(t[2],(void**) &sum2);
    pthread_join(t[3],(void**) &sum3);

	int sumatotal=sum0+sum1+sum2+sum3;
    cout<<"\n(Producto) la respuesta es: "<<sumatotal<<endl;
	pthread_exit(NULL);
}