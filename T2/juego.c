#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "funciones.h"


void Instrucciones();
void Actualizar_Jugador();
int *Adversario();

int Vida_Actual, Escudo, Dano, v0;
int Vida_Actual2, Escudo2, Dano2, v0;

int *Jugador[3];
int *Enemigo[3];

int main(){
    srand(time(NULL)); 
    Instrucciones();

    *Jugador = Adversario(rand() %900, rand() %100);

    printf("%i\n ", Jugador[0]);

    Vida_Actual = (int) Jugador[0];
    Escudo =  (int) Jugador[1];
    Dano =  (int) Jugador[2];
    printf("Datos: %i\n", (int) Jugador[0]);
    
    Actualizar_Jugador(Vida_Actual, Escudo, Dano);

    *Enemigo[3] = Adversario(rand() %900, rand() %100);

    Vida_Actual2 =  (int) Enemigo[0];
    Escudo2 = (int) Enemigo[1];
    Dano2 =  (int) Enemigo[2];
    printf("la vida es: %i\n", (int)  Enemigo[0]);
    Actualizar_Jugador(Vida_Actual2, Escudo2, Dano2);

}