#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void Instrucciones(void){

    printf("Instrucciones:\n -Juega\n");
}

void Actualizar_Jugador(int Vida_Actual, int Escudo, int Dano){
    int a =   Vida_Actual;
    int b =  Escudo;
    int c =  Dano;


    printf("Estadisticas del jugador:\n -Vida actual: %i\n -Escudo: %i\n -Daño: %i\n", a, b, c);

}

int Nueva_Vida_Maxima(int Vida_Actual, int Escudo, int Dano, int p){
    
    int a = (int) Vida_Actual;
    int b = (int) Escudo;
    int c =  (int) Dano;

    return (a + b - (1 + p)*c);
}


int Generar_Consumible(int Vida_Actual, int p, int v0){
    int a = (int) Vida_Actual;
    int nv = (1 + p/2)*a;
    if (nv>v0){ nv = v0;}

    return nv;
}

int *Adversario(int r1, int r2){
    
    int Vida_Actual =   r1;
    int Escudo =  r2;
    int Dano =  (1000-r1-r2); 
    int *Jugador[3] = { (void*) Vida_Actual,  (void*) Escudo,  (void*) Dano};
    return *Jugador;

}


int *Batalla(int v1,int e1,int d1, int v2,int e2,int d2, int flag, int p){
    int a = Nueva_Vida_Maxima(v1, e1, d2, p); /*Se usa el daño del adversario para calcular*/
    int b = Nueva_Vida_Maxima(v2, e2, d1, p);

    if(a<0 && flag==1){
        a =1;
        flag =0;
    }
    int vidas[2] = {(void*)a, (void*)b};
    return vidas[2];

}