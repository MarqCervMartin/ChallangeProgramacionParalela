#include<math.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
/********************************Funcion Main********************************/
void main()
{
clrscr();
float aux[10],aux1[10],auxx[10],resultado[10],suma,sumat[10],tole[10],
tole1,tolefin[10],tolerancia,w,x1[10],xy[10][10];
int grado,h=0,i=0,j=0;
/*******************************Captura Datos*******************************/
printf("Grado de la Ecuaci¢n [2 ¢ 3]: ");
scanf("%d",&grado);
for(j=0;j<10;j++)
{
auxx[j]=0;
}
for(i=0;i<grado;i++)
{
printf(" Ingresa la Ecuaci¢n Nø%d ",i+1);
for(j=0;j<grado;j++)
{
printf("X%d%d= ",i+1,j+1);
scanf("%f",&xy[i][j]);
}
printf("Y%d= ",i+1);
scanf("%f",&resultado[i]);
}
/******************************Imprime Matriz*******************************/
printf(" Las Ecuaciones son... ");
for(i=0;i<grado;i++)
{
for(j=0;j<grado;j++)
{
printf("%.0f[X%d]",xy[i][j],j+1);
if(j==0)
printf("+");
}
printf("=",i+1);
printf("%.0f",resultado[i]);
printf(" ");
}
printf(" La Matriz a Resolver es... ");
for(i=0;i<grado;i++)
{
printf("%c ",179);
for(j=0;j<grado;j++)
{
printf(" %.0f ",xy[i][j],j+1);
}
printf(" %c",179);
printf(" %.0f ",resultado[i]);
printf(" %c ",179);
}
printf(" Ingresa la Exactitud o Tolerancia: ");
scanf("%f",&tolerancia);
for(;;)
{
/*****************Calcula Sumatoria de Despeje de Polinomios****************/
h=0;
do
{
suma=0;
for(i=h;i<h+1;i++)
{
for(j=0;j<grado;j++)
{
if(j!=i)
{
suma+=(xy[i][j]*x1[j])/xy[i][i];
}
}
}
sumat[h]=suma;
h++;
}while(h<grado);
for(i=0,j=grado-1;i<grado;i++,j--)
{
aux[i]=auxx[j];
}
for(i=0;i<grado;i++)
{
for(j=0;j<grado;j++)
{
if(i!=j)
{
auxx[i]=((resultado[i])/xy[i][i])-(sumat[i]);
}
}
}
for(i=0,j=grado-1;i<grado;i++,j--) { x1[i]=auxx[i]; }
for(i=0;i<grado;i++) { tole[i]=0; }
for(i=0,j=grado-1;i<grado;i++,j--) { aux1[i]=auxx[j]; }
for(i=0;i<grado;i++) { tole[i]=aux1[i]-aux[i]; }
/*************************Obtencion de la Precision**************************/
int k=0;
while(k<grado)
{
for(i=0;i<grado-1;i++)
{
if(tole[i]<tole[i+1])
{
tole1=tole[i];tole[i]=tole[i+1];tole[i+1]=tole1;
}
}
k++;
}
for( j=0;j<grado;j++)
{
tolefin[j]=tole[j];
}
w=tolefin[0];
printf(" ");
for(j=0;j<grado;j++)
{
printf("x%d= %f ",j+1,auxx[j]);
}
if(fabs(w)<=tolerancia)
{
printf(" Resultados en la Iteracion Nø%d ");
for(j=0;j<grado;j++)
{
printf("X%d=%.15f ",j+1,auxx[j]);
}
getch();
break;
}
}
}