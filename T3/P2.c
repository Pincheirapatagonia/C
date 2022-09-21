

#include <stdio.h>
#include <stdlib.h>

/* Declar puntero */

int i;
int j = 7;
float *p;

void definir (int i, int j, float *p, float y[i][j]){
  
  int a, b;
  float aux;
    
  for (a = 0; a < i; a += 1)
    {
      for (b = 0; b < j; b += 1)
	{
	  p = &y[a][b];
	  printf ("Ingrese la energía del dia %d para el auto %d: \n",
		  (b + 1), (a + 1));
	  scanf ("%f", &aux);
	  *p = aux;
	}
    }
};

void sumar(int i, int j, float y[i][j]){
    
    int a, b;
    float sum;
    float *p;
    p = &y[0][0];
    for (a = 0; a < i; a += 1)
    {
      for (b = 0; b < j; b += 1)
	{
	  sum += *((p+a)+b);
	  
	}
    }
    printf("El total de energía consumida para %d vehículos es: %f (kWh), el promedio de consumo en %d dias es: %f (kWh).\n", i, sum, j, (sum/(i*j)));
}



void definir();
void sumar();
void main ()
{
/*--------------Problema 2-----------*/

/* - - - Ingresar cantidad de vehículos - - - */

  printf ("Ingrese la cantidad de vehículos: \n");

  scanf ("%d", &i);
  
float y[i][j];


/*----Definir la matriz de energías-----*/

  float y2[5][7] = {
    {20.88, 44.02, 25.23, 22.62, 23.14, 22.27, 15.66},
    {13.82, 23.47, 21.31, 9.36, 26.78, 30.24, 15.26},
    {9.29, 13.93, 17.42, 23.74, 15.74, 7.48, 8.77},
    {16.47, 25.91, 26.28, 49.05, 44.42, 13.70, 19.25},
    {39.20, 36.46, 31.95, 28.42, 45.47, 14.70, 37.04}
  };
 
 

/* ------ Modo manual o automatico ------ */

int modo;
printf("Ingrese el modo (por salud mental) : 0: manual, 1: automatico\n");
scanf("%d", &modo);

if(modo == 0){
    /*------ Matriz de usuario------*/
    definir(i,j,p,y);
    sumar(i,j,y);
}
  
else if(modo == 1){
    sumar(i,j,y2);
}
  
else{
    printf("no entró");
}


}