
/*
 *
 *  Fecha Entrega: 01-04-2022
 *      Author: Felipe Valenzuela Ilabaca
 *      Código: TicTacToe
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <string.h>

const char Jugador1 = 'X';
const char Jugador2 = 'O';
const char Computadora = 'O';
char Nombres[3];
char Tablero[19] = {'0','1','2','3','4','5','6','7','8','9','1','2','3','4','5','6','7','8','9'};

int Comprobar_Fin_Juego()
{
    int Final = 9;
    for(int i = 0; i<10; i++)
    {
        if(Tablero[i] == 'X'||Tablero[i] == 'O')
        {
            Final--;
        }
    }
    return Final; //si es que final vale 0 significa que el juego puede terminar

}

void Imprimir_Tablero()
{
    printf("\n %c | %c | %c ", Tablero[1],Tablero[2],Tablero[3]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", Tablero[4],Tablero[5],Tablero[6]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", Tablero[7],Tablero[8],Tablero[9]);
    printf("\n\n");
}

void Reiniciar_Tablero()
{
    for(int i = 0 ; i<10 ; i++)
    {
        if (Tablero[i] =='X' || Tablero[i] == 'O')
        {
            Tablero[i] = Tablero[i+9];
        }
    }
}//Reinicia el tablero haciendo que los los primeros valores pasen a ser iguales que los que no se estan cambiando durante el juego

char Chequear_Ganador()
{
    if(Tablero[1]==Tablero[2] && Tablero[1]==Tablero[3])
    {
        return Tablero[1];
    }
    else if(Tablero[4]==Tablero[5] && Tablero[4]==Tablero[6])
    {
        return Tablero[4];
    }
    else if(Tablero[7]==Tablero[8] && Tablero[7]==Tablero[9])
    {
        return Tablero[7];
    }
    else if(Tablero[1]==Tablero[5] && Tablero[1]==Tablero[9])
    {
        return Tablero[1];
    }
    else if(Tablero[3]==Tablero[5] && Tablero[3]==Tablero[7])
    {
        return Tablero[3];
    }
    else if(Tablero[1]==Tablero[4] && Tablero[1]==Tablero[7])
    {
        return Tablero[1];
    }
    else if(Tablero[2]==Tablero[5] && Tablero[2]==Tablero[8])
    {
        return Tablero[2];
    }
    else if(Tablero[3]==Tablero[6] && Tablero[3]==Tablero[9])
    {
        return Tablero[3];
    }
    else
    {
        return ' ';
    }
}// Son todas las condiciones de victoria dentro del juego.
 

int Turno_Jugador1(char* Nombre)
{
    int x;
    int Rendirse = 0;

    do
    {
        printf("\nTurno de %s\n",Nombre);
        printf("\n Escoja posicion de X (presionar 0 para rendirse):\n");
        scanf("%d", &x );
        if(x == 0)
        {
            printf("\nHas perdido la ronda\n");
            Rendirse = 1;
            break;
            
        }
        
        else if (Tablero[x]=='X'||Tablero[x]=='O'|| x>9)
        {
            printf("\n Movimiento invalido, escoja otra posicion\n");
            Imprimir_Tablero();
        }
        else
        {
            Tablero[x]= Jugador1;
            break;
        }

    } while ( x>9 || Tablero[x]=='X' || Tablero[x]=='O');

    return Rendirse;


    
}// Se hace un do while para que se mantenga preguntando posiciones hasta que se cumplan las condiciones.
//(No funciona si se introduce una letra)

int Turno_Jugador2(char* Nombre)
{
    int y;
    int Rendirse = 0;
    do
    {
        printf("\nTurno de %s\n",Nombre);
        printf("\n Escoja posicion de O (presionar 0 para rendirse):\n");
        scanf("%d", &y );
        if(y == 0)
        {
            printf("\nHas perdido la ronda\n");
            Rendirse = 1;
            break;   
        }
        else if (Tablero[y]=='X'||Tablero[y]=='O'|| y>9)
        {
            printf("\n Movimiento invalido, escoja otra posicion\n");
            Imprimir_Tablero();
        }
        else
        {
            Tablero[y]= Jugador2;
            break;
        }

    }while (Tablero[y]=='X'||Tablero[y]=='O'|| y>9);

    return Rendirse;
    
}
//Igual que Turno_Jugador1

int Posibilidad_de_Victoria(char* Computer, char* Player)//Aqui pongo todas las posibilidades de victoria para la computadora, 
                                                            //retorna la posicion que necesita para ganar.
{
    int Posicion = 0;
    if(Tablero[1] == Tablero[2] && Tablero[1] == *Computer && Tablero[3] != *Player)
    {
        Posicion = 3;
    }
    else if (Tablero[1] == Tablero[3] && Tablero[1] == *Computer && Tablero[2] != *Player)
    {
        Posicion = 2;
    }
    else if (Tablero[2] == Tablero[3] && Tablero[2] == *Computer && Tablero[1] != *Player)
    {
        Posicion = 1;
    }
    else if(Tablero[4] == Tablero[5] && Tablero[4] == *Computer && Tablero[6] != *Player)
    {
        Posicion = 6;
    }
    else if (Tablero[4] == Tablero[6] && Tablero[4] == *Computer && Tablero[5] != *Player)
    {
        Posicion = 5;
    }
    else if (Tablero[5] == Tablero[6] && Tablero[5] == *Computer && Tablero[4] != *Player)
    {
        Posicion = 4;
    }
    else if(Tablero[7] == Tablero[8] && Tablero[7] == *Computer && Tablero[9] != *Player)
    {
        Posicion = 9;
    }
    else if (Tablero[7] == Tablero[9] && Tablero[7] == *Computer && Tablero[8] != *Player)
    {
        Posicion = 8;
    }
    else if (Tablero[8] == Tablero[9] && Tablero[8] == *Computer && Tablero[7] != *Player)
    {
        Posicion = 7;
    }
    else if(Tablero[1] == Tablero[4] && Tablero[1] == *Computer && Tablero[7] != *Player)
    {
        Posicion = 7;
    }
    else if (Tablero[1] == Tablero[7] && Tablero[1] == *Computer && Tablero[4] != *Player)
    {
        Posicion = 4;
    }
    else if (Tablero[4] == Tablero[7] && Tablero[4] == *Computer && Tablero[1] != *Player)
    {
        Posicion = 1;
    }
    else if(Tablero[2] == Tablero[5] && Tablero[2] == *Computer && Tablero[8] != *Player)
    {
        Posicion = 8;
    }
    else if (Tablero[2] == Tablero[8] && Tablero[2] == *Computer && Tablero[5] != *Player)
    {
        Posicion = 5;
    }
    else if (Tablero[5] == Tablero[8] && Tablero[5] == *Computer && Tablero[2] != *Player)
    {
        Posicion = 2;
    }
    else if(Tablero[3] == Tablero[6] && Tablero[3] == *Computer && Tablero[9] != *Player)
    {
        Posicion = 9;
    }
    else if (Tablero[3] == Tablero[9] && Tablero[3] == *Computer && Tablero[6] != *Player)
    {
        Posicion = 6;
    }
    else if (Tablero[6] == Tablero[9] && Tablero[6] == *Computer && Tablero[3] != *Player)
    {
        Posicion = 3;
    }
    else if(Tablero[1] == Tablero[5] && Tablero[1] == *Computer && Tablero[9] != *Player)
    {
        Posicion = 9;
    }
    else if (Tablero[1] == Tablero[9] && Tablero[1] == *Computer && Tablero[5] != *Player)
    {
        Posicion = 5;
    }
    else if (Tablero[5] == Tablero[9] && Tablero[5] == *Computer && Tablero[1] != *Player)
    {
        Posicion = 1;
    }
    else if(Tablero[3] == Tablero[5] && Tablero[3] == *Computer && Tablero[7] != *Player)
    {
        Posicion = 7;
    }
    else if (Tablero[3] == Tablero[7] && Tablero[3] == *Computer && Tablero[5] != *Player)
    {
        Posicion = 5;
    }
    else if (Tablero[5] == Tablero[7] && Tablero[5] == *Computer && Tablero[3] != *Player)
    {
        Posicion = 3;
    }
    else
    {
        Posicion = 0;
    }

    return Posicion;
    
}

int Posibilidad_Derrota(char* Computer, char* Player)//es lo mismo que la anterior pero con la derrota.
{
    int Posicion = 0;
    if(Tablero[1] == Tablero[2] && Tablero[1] == *Player && Tablero[3] != *Computer)
    {
        Posicion = 3;
    }
    else if (Tablero[1] == Tablero[3] && Tablero[1] == *Player && Tablero[2] != *Computer)
    {
        Posicion = 2;
    }
    else if (Tablero[2] == Tablero[3] && Tablero[2] == *Player && Tablero[1] != *Computer)
    {
        Posicion = 1;
    }
    else if(Tablero[4] == Tablero[5] && Tablero[4] == *Player && Tablero[6] != *Computer)
    {
        Posicion = 6;
    }
    else if (Tablero[4] == Tablero[6] && Tablero[4] == *Player && Tablero[5] != *Computer)
    {
        Posicion = 5;
    }
    else if (Tablero[5] == Tablero[6] && Tablero[5] == *Player && Tablero[4] != *Computer)
    {
        Posicion = 4;
    }
    else if(Tablero[7] == Tablero[8] && Tablero[7] == *Player && Tablero[9] != *Computer)
    {
        Posicion = 9;
    }
    else if (Tablero[7] == Tablero[9] && Tablero[7] == *Player && Tablero[8] != *Computer)
    {
        Posicion = 8;
    }
    else if (Tablero[8] == Tablero[9] && Tablero[8] == *Player && Tablero[7] != *Computer)
    {
        Posicion = 7;
    }
    else if(Tablero[1] == Tablero[4] && Tablero[1] == *Player && Tablero[7] != *Computer)
    {
        Posicion = 7;
    }
    else if (Tablero[1] == Tablero[7] && Tablero[1] == *Player && Tablero[4] != *Computer)
    {
        Posicion = 4;
    }
    else if (Tablero[4] == Tablero[7] && Tablero[4] == *Player && Tablero[1] != *Computer)
    {
        Posicion = 1;
    }
    else if(Tablero[2] == Tablero[5] && Tablero[2] == *Player && Tablero[8] != *Computer)
    {
        Posicion = 8;
    }
    else if (Tablero[2] == Tablero[8] && Tablero[2] == *Player && Tablero[5] != *Computer)
    {
        Posicion = 5;
    }
    else if (Tablero[5] == Tablero[8] && Tablero[5] == *Player && Tablero[2] != *Computer)
    {
        Posicion = 2;
    }
    else if(Tablero[3] == Tablero[6] && Tablero[3] == *Player && Tablero[9] != *Computer)
    {
        Posicion = 9;
    }
    else if (Tablero[3] == Tablero[9] && Tablero[3] == *Player && Tablero[6] != *Computer)
    {
        Posicion = 6;
    }
    else if (Tablero[6] == Tablero[9] && Tablero[6] == *Player && Tablero[3] != *Computer)
    {
        Posicion = 3;
    }
    else if(Tablero[1] == Tablero[5] && Tablero[1] == *Player && Tablero[9] != *Computer)
    {
        Posicion = 9;
    }
    else if (Tablero[1] == Tablero[9] && Tablero[1] == *Player && Tablero[5] != *Computer)
    {
        Posicion = 5;
    }
    else if (Tablero[5] == Tablero[9] && Tablero[5] == *Player && Tablero[1] != *Computer)
    {
        Posicion = 1;
    }
    else if(Tablero[3] == Tablero[5] && Tablero[3] == *Player && Tablero[7] != *Computer)
    {
        Posicion = 7;
    }
    else if (Tablero[3] == Tablero[7] && Tablero[3] == *Player && Tablero[5] != *Computer)
    {
        Posicion = 5;
    }
    else if (Tablero[5] == Tablero[7] && Tablero[5] == *Player && Tablero[3] != *Computer)
    {
        Posicion = 3;
    }
    else
    {
        Posicion = 0;
    }

    return Posicion;

}

int Turno_Jugador_o_Computadora(char* Nombre, int Final, char* Computer, char* Player, int Dificultad)
{
    int Rendirse = 0;
    //Turno de la computadora
    if (strcmp(Nombre, "Computadora") == 0)
    { 
        printf("Turno de %s\n", Nombre);
        srand(time(0));//Con esto se crea una seed random dependiendo del tiempo transcurrido.
        int y;
        int Victoria = Posibilidad_de_Victoria(Computer, Player);
        int Derrota = Posibilidad_Derrota(Computer, Player);
        if(Dificultad == 1)
        {
            if (Final > 0)
            {
                do
                {
                    y = rand() % 9;//Con esto se genera un número aleatorio entre el 0 y el 9

                } while (Tablero[y]=='X'||Tablero[y]=='O'|| y<1);//esta es la condición para que siempre elija un número válido.

                Tablero[y] = *Computer;
                
            }
        }

        else if (Dificultad == 2)
        {
            if (Final > 0 && Victoria == 0 && Derrota == 0)
            {
                do
                {
                    y = rand() % 9;//Con esto se genera un número aleatorio entre el 0 y el 9

                } while (Tablero[y]=='X'||Tablero[y]=='O'|| y<1);//esta es la condición para que siempre elija un número válido.

                Tablero[y] = *Computer;
                
            }
            else if (Final > 0 && Victoria != 0)
            {
                Tablero[Victoria] = *Computer;
            }
            else if(Final > 0 && Derrota != 0)
            {
                Tablero[Derrota] = *Computer;
            }
        }
        

        
        
    }
    else
    {
        int x;
        
        do
        {
            printf("\nTurno de %s\n",Nombre);
            printf("\n Escoja posicion de %s (presionar 0 para rendirse):\n",Player);
            scanf("%d", &x );
            if(x == 0)
            {
                printf("\nHas perdido la ronda\n");
                Rendirse = 1;
                break;
            
            }
            
            else if (Tablero[x]=='X'||Tablero[x]=='O'|| x>9)
            {
                printf("\n Movimiento invalido, escoja otra posicion\n");
                Imprimir_Tablero();
            }
            
            else
            {
                Tablero[x]= *Player;
                break;
            }

        } while (Tablero[x]=='X'||Tablero[x]=='O'|| x>9);

        
    }

    return Rendirse;
}//Esto es igual al turno de jugador1. Combiné ambos turnos en una sola función para que fuera más facil el cambio de turnos después.

void Quien_Gano(int* Cuenta1,int* Cuenta2,char* Nombre1, char* Nombre2)
{
    if(*Cuenta1>*Cuenta2)
    {
        printf("\nGana %s %d - %d\n", Nombre1, *Cuenta1, *Cuenta2);
    }
    else if(*Cuenta2>*Cuenta1)
    {
        printf("\nGana %s %d - %d\n", Nombre2, *Cuenta2, *Cuenta1);
    }
    else
    {
        printf("\nEmpate %d - %d\n", *Cuenta1, *Cuenta2);
    }
}
//Literalmente dice quien ganó. Se utilizan como inputs los marcadores y los nombres de los jugadores.

int main ()
{
    printf("\nBienvenido al TicTacToe\n \nSe juegan 3 rondas y gana quien obtenga mayor puntaje\n");
    int Modo_de_Juego = 0;//En esta variable se va a guardar el modo de juego elegido
    int Aprobar = 0;// esta variable cambiará si es que se elige un número válido, y permitirá que comience el juego.
    while(Aprobar == 0)
    {
        
        printf("\nEscoja el modo de juego\n1 para jugar contra otra persona\n2 para jugar contra la computadora\n");
        scanf("%d", &Modo_de_Juego);
        if (Modo_de_Juego == 1 || Modo_de_Juego == 2)
        {
            Aprobar = 1;
        }

        else
        {
            printf("\nEscoja una opcion valida\n");
        }
    }//loop para que se escoja una opción válida de juego.

    if (Modo_de_Juego == 1)//Aquí comienza el modo de juego pvp
    {
        char Nombre1[100];//Variables en las que se guardarán los nombres ingresados por los jugadores.
        char Nombre2[100];
        char Auxiliar[100];

        printf("\nIngrese nombre de jugador 1: \n");
        scanf("%s",Nombre1);

        int comparacion = 0;//Variable auxiliar usada para el siguiente loop

        while(comparacion == 0)
        {
            printf("\nIngrese nombre de jugador 2: \n");
            scanf("%s",Nombre2);
            
            char Nombre1mayusculas[100];//Variables para guardar los nombres en mayúsculas
            char Nombre2mayusculas[100];
            for(int i = 0; i<100; ++i)
            {
                Nombre1mayusculas[i] = '\0';
                Nombre2mayusculas[i] = '\0';
            }
            for (int i = 0; Nombre1[i] != '\0'; ++i)
            {
                Nombre1mayusculas[i] = toupper(Nombre1[i]); //toupper hace que todas las letras del nombre sean mayúsculas
            }
            for (int i = 0; Nombre2[i] != '\0'; ++i)
            {
                Nombre2mayusculas[i] = toupper(Nombre2[i]);
            }
            comparacion = strcmp(Nombre1mayusculas,Nombre2mayusculas);//strcmp compara strings y si devuelve 0 significa que son iguales
            if (comparacion == 0)
            {
                printf("\nNombre ocupado, porfavor ingrese otro \n");
            }

        }// loop para que se escoja un nombre distinto al primero
        
        char Ganador = ' ';//Esta variable guarda al ganador de cada ronda.
        int Respuesta = 1;//Esta variable guardará la respuesta del jugador despues de terminar el juego.
        int Marcador1 = 0;//Esta variable guarda cuantos puntos lleva el jugador 1.
        int Marcador2 = 0;//Esta variable guarda cuantos puntos lleva el jugador 2.
        int Rondas = 0;//Esta variable guarda cuantas rondas se han jugado.
        int Temp = 0;//Variable auxiliar.
        int Seguir = 0;//Variable utilizada para terminar el juego.
        int Acabar;//Esta variable va a guardar el valor retornado por las funciones Turno_Jugador.

        while((Respuesta == 1||Respuesta == 3) && (Seguir == 0))
        {   
            Rondas = 0;
            Marcador1 = 0;
            Marcador2 = 0;
            Respuesta = 1;

            while(Marcador1 < 3 && Marcador2 < 3 && Rondas < 3 && Respuesta == 1)
            {
                Reiniciar_Tablero();
                Imprimir_Tablero();
                Ganador = Chequear_Ganador();
                int Fin = Comprobar_Fin_Juego();

                while(Ganador == ' ' && Fin != 0)
                {
                    Acabar = Turno_Jugador1(Nombre1);
                    Imprimir_Tablero();
                    Chequear_Ganador();
                    Fin = Comprobar_Fin_Juego();
                    Ganador = Chequear_Ganador();

                    if(Ganador == Jugador1)
                    {
                        Marcador1++;
                        Rondas++;
                        printf("\n%s ha ganado la ronda %d\n", &Nombre1 ,Rondas);
                        break;
                    }

                    else if (Fin == 0 && Ganador == ' ')
                    {
                        Rondas++;
                        printf("\nse ha empatado la ronda %d\n", Rondas);
                        break;
                    }
                    else if(Acabar == 1)
                    {
                        Rondas++;
                        Marcador2++;
                        break;   
                    }

                    Acabar = Turno_Jugador2(Nombre2);
                    Imprimir_Tablero();
                    Chequear_Ganador();
                    Fin = Comprobar_Fin_Juego();
                    Ganador = Chequear_Ganador();

                    if(Ganador == Jugador2)
                    {
                        
                        Marcador2++;
                        Rondas++;
                        printf("\n%s ha ganado la ronda %d\n", &Nombre2 ,Rondas);
                        break;
                    }

                    else if (Fin == 0 && Ganador == ' ')
                    {
                        Rondas++;
                        printf("\n se ha empatado la ronda %d", Rondas);
                        break;
                    }

                    else if(Acabar == 1)
                    {
                        Rondas++;
                        Marcador1++;
                        break;

                    }
                    
                    
                }
                printf("\nNumero de rondas jugadas: %d\n", Rondas);
                printf("\nRondas ganadas por %s: %d\n", Nombre1, Marcador1);
                printf("\nRondas ganadas por %s: %d\n", Nombre2, Marcador2);

                if (Rondas<3)
                {
                    int Validar = 0;//Variable auxiliar utilizada para terminar con el loop

                    while(Validar == 0)
                    {
                        printf("\nJugar siguiente ronda?\n 1 para continuar\n 2 para rendirse\n 3 para reiniciar\n");
                        scanf("%d", &Respuesta);

                        if (Respuesta == 1)
                        {
                            strcpy(Auxiliar,Nombre1);//Esta funcion intercambia los strings que se le dan.
                            strcpy(Nombre1,Nombre2);
                            strcpy(Nombre2,Auxiliar);
                            Temp = Marcador1;
                            Marcador1 = Marcador2;
                            Marcador2 = Temp;
                            Validar = 1;
                        }//Aqui intercambio los nombres y los marcadores, para que en el siguiente turno se cambie el orden de partida.

                        else if (Respuesta == 2)
                        {
                            printf("Te has rendido\n");
                            Validar = 1;
                            //rendirse
                        }

                        else if (Respuesta == 3)
                        {
                            Validar = 1;
                            //reiniciar
                        }

                        else 
                        {
                            printf("\nEscoja una respuesta valida\n");
                        }

                    }
                    
                }

            }

            Quien_Gano(&Marcador1, &Marcador2, Nombre1, Nombre2);//Esta función devuelve al ganador del juego.
            
            if(Respuesta != 3)
            {
                printf("\nQuieres jugar otra vez? (1 para seguir jugando, otro numero para terminar para terminar): \n");
                scanf("%d", &Respuesta);

                if (Respuesta != 1)
                {
                    Seguir++;
                }
            }//Esta parte es para cuando se juegan las 3 rondas o alguien se rinde, da la opcion de jugar otra partida.
            
            else
            {
                printf("\nSe reiniciara el juego por lo que los marcadores volveran a 0\n");
            }//Esta parte es por si se eligió reiniciar el juego.
        }

        return 0;    
    }
    
    else if (Modo_de_Juego == 2)//Aqui comienza el juego contra la computadora. (Funciona de manera bastante parecida que lo anterior)
    {
        int Bueno = 0;//Variable auxiliar
        int Dificultad;//Variable que guarda la dificultad elegida por el jugador.
        while(Bueno == 0)
        {
            printf("Escoja la dificultad (1 modo facil, 2 modo medio):\n");
            scanf("%d",&Dificultad);
            if(Dificultad == 1 || Dificultad == 2)
            {
                Bueno++;
            }
            else
            {
                printf("Escoja una opcion valida\n");
            }

        }

        if (Dificultad == 1)//Aqui empieza el modo facil
        {
            char Nombre1[100];
            char Auxiliar[100];
            char Nombre2[12] = {'C','o','m','p','u','t','a','d','o','r','a','\0'}; //Esto es para poder intercambiar los turnos después.
            char Ganador = ' ';
            int Respuesta = 1;
            int Marcador1 = 0;
            int Marcador2 = 0;
            int Rondas = 0;
            int Temp = 0;
            int Seguir = 0;
            char Player; //Player y Computer son variables utilizadas para determinar cual es la marca que deben utilizar el jugador y la computadora
            char Computer;
            char Change;//Variable auxiliar
            int Acabar;

            while((Respuesta == 1||Respuesta == 3) && (Seguir == 0))
            {   
                printf("\nIngrese nombre de jugador 1: \n");
                scanf("%s",Nombre1);
                char Nombre2[12] = {'C','o','m','p','u','t','a','d','o','r','a','\0'}; 
                char Ganador = ' ';
                Rondas = 0;
                Marcador1 = 0;
                Marcador2 = 0;
                Respuesta = 1;
                Computer = Computadora;
                Player = Jugador1;

                while(Marcador1 < 3 && Marcador2 < 3 && Rondas < 3 && Respuesta == 1)
                {
                    Reiniciar_Tablero();
                    Imprimir_Tablero();
                    Ganador = Chequear_Ganador();
                    int Fin = Comprobar_Fin_Juego();

                    while(Ganador == ' ' && Fin != 0)
                    {
                        Acabar = Turno_Jugador_o_Computadora(Nombre1,Fin,&Computer,&Player,Dificultad);
                        Imprimir_Tablero();
                        Chequear_Ganador();
                        Fin = Comprobar_Fin_Juego();
                        Ganador = Chequear_Ganador();

                        if(Ganador == Jugador1)
                        {
                            Marcador1++;
                            Rondas++;
                            printf("\n%s ha ganado la ronda %d\n", Nombre1 ,Rondas);
                            break;
                        }

                        else if (Fin == 0 && Ganador == ' ')
                        {
                            Rondas++;
                            printf("\nse ha empatado la ronda %d\n", Rondas);
                            break;
                        }
                        else if (Acabar == 1)
                        {
                            Rondas++;
                            Marcador2++;
                            break;
                        }
                        
                        Acabar = Turno_Jugador_o_Computadora(Nombre2,Fin,&Computer,&Player,Dificultad);
                        Imprimir_Tablero();
                        Chequear_Ganador();
                        Fin = Comprobar_Fin_Juego();
                        Ganador = Chequear_Ganador();

                        if(Ganador == Computadora)
                        {
                            
                            Marcador2++;
                            Rondas++;
                            printf("\n%s ha ganado la ronda %d\n", Nombre2 ,Rondas);
                            break;
                        }

                        else if (Fin == 0 && Ganador == ' ')
                        {
                            Rondas++;
                            printf("\n se ha empatado la ronda %d", Rondas);
                            break;
                        }
                        else if (Acabar == 1)
                        {
                            Rondas++;
                            Marcador1++;
                            break;
                        }
                        
                        
                    }
                    printf("\nNumero de rondas jugadas: %d\n", Rondas);
                    printf("\nRondas ganadas por %s: %d\n", Nombre1, Marcador1);
                    printf("\nRondas ganadas por %s: %d\n", Nombre2, Marcador2);

                    if (Rondas<3)
                    {
                        int Validar = 0;

                        while(Validar == 0)
                        {
                            printf("\nJugar siguiente ronda?\n 1 para continuar\n 2 para rendirse\n 3 para reiniciar\n");
                            scanf("%d", &Respuesta);

                            if (Respuesta == 1)//Aqui se intercambian los nombres, los marcadores y las marcas que se usan en el tablero.
                            {
                                strcpy(Auxiliar,Nombre1);
                                strcpy(Nombre1,Nombre2);
                                strcpy(Nombre2,Auxiliar);
                                Temp = Marcador1;
                                Marcador1 = Marcador2;
                                Marcador2 = Temp;
                                Change = Player;
                                Player = Computer;
                                Computer = Change;
                                Validar = 1;
                            }

                            else if (Respuesta == 2)
                            {
                                printf("Te has rendido\n");
                                Validar = 1;
                                //rendirse
                            }

                            else if (Respuesta == 3)
                            {
                                Validar = 1;
                                //reiniciar
                            }

                            else 
                            {
                                printf("\nEscoja una respuesta valida\n");
                            }

                        }
                        
                    }

                }

                if(Respuesta != 3)
                {
                    Quien_Gano(&Marcador1, &Marcador2, Nombre1, Nombre2);
                    printf("\nQuieres jugar otra vez? (1 para seguir jugando, otro numero para terminar para terminar): \n");
                    scanf("%d", &Respuesta);

                    if (Respuesta != 1)
                    {
                        Seguir++;
                    }
                }
                
                else
                {
                    printf("\nSe reiniciara el juego por lo que los marcadores volveran a 0\n");
                }
            }
            

            return 0;

        }
        else if (Dificultad == 2)//Aqui comienza el nivel medio.(Funciona igual que el nivel facil, pero la funcion de turno cambia su
        // funcionamiento)
        {
            char Nombre1[100];
            char Auxiliar[100];
            char Nombre2[12] = {'C','o','m','p','u','t','a','d','o','r','a','\0'};
            char Ganador = ' ';
            int Respuesta = 1;
            int Marcador1 = 0;
            int Marcador2 = 0;
            int Rondas = 0;
            int Temp = 0;
            int Seguir = 0;
            char Player; 
            char Computer;
            char Change;
            int Acabar;

            while((Respuesta == 1||Respuesta == 3) && (Seguir == 0))
            {   
                printf("\nIngrese nombre de jugador 1: \n");
                scanf("%s",Nombre1);
                char Nombre2[12] = {'C','o','m','p','u','t','a','d','o','r','a','\0'}; 
                char Ganador = ' ';
                Rondas = 0;
                Marcador1 = 0;
                Marcador2 = 0;
                Respuesta = 1;
                Computer = Computadora;
                Player = Jugador1;

                while(Marcador1 < 3 && Marcador2 < 3 && Rondas < 3 && Respuesta == 1)
                {
                    Reiniciar_Tablero();
                    Imprimir_Tablero();
                    Ganador = Chequear_Ganador();
                    int Fin = Comprobar_Fin_Juego();

                    while(Ganador == ' ' && Fin != 0)
                    {
                        Acabar = Turno_Jugador_o_Computadora(Nombre1,Fin,&Computer,&Player,Dificultad);
                        Imprimir_Tablero();
                        Chequear_Ganador();
                        Fin = Comprobar_Fin_Juego();
                        Ganador = Chequear_Ganador();

                        if(Ganador == Jugador1)
                        {
                            Marcador1++;
                            Rondas++;
                            printf("\n%s ha ganado la ronda %d\n", Nombre1 ,Rondas);
                            break;
                        }

                        else if (Fin == 0 && Ganador == ' ')
                        {
                            Rondas++;
                            printf("\nse ha empatado la ronda %d\n", Rondas);
                            break;
                        }
                        else if (Acabar == 1)
                        {
                            Rondas++;
                            Marcador2++;
                            break;
                        }
                        


                        Acabar = Turno_Jugador_o_Computadora(Nombre2,Fin,&Computer,&Player,Dificultad);
                        Imprimir_Tablero();
                        Chequear_Ganador();
                        Fin = Comprobar_Fin_Juego();
                        Ganador = Chequear_Ganador();

                        if(Ganador == Computadora)
                        {
                            
                            Marcador2++;
                            Rondas++;
                            printf("\n%s ha ganado la ronda %d\n", Nombre2 ,Rondas);
                            break;
                        }

                        else if (Fin == 0 && Ganador == ' ')
                        {
                            Rondas++;
                            printf("\n se ha empatado la ronda %d", Rondas);
                            break;
                        }
                        else if (Acabar == 1)
                        {
                            Rondas++;
                            Marcador1++;
                            break;
                        }
                        
                        
                    }
                    printf("\nNumero de rondas jugadas: %d\n", Rondas);
                    printf("\nRondas ganadas por %s: %d\n", Nombre1, Marcador1);
                    printf("\nRondas ganadas por %s: %d\n", Nombre2, Marcador2);

                    if (Rondas<3)
                    {
                        int Validar = 0;

                        while(Validar == 0)
                        {
                            printf("\nJugar siguiente ronda?\n 1 para continuar\n 2 para rendirse\n 3 para reiniciar\n");
                            scanf("%d", &Respuesta);

                            if (Respuesta == 1)//Aqui se intercambian los nombres, los marcadores y las marcas.
                            {
                                strcpy(Auxiliar,Nombre1);
                                strcpy(Nombre1,Nombre2);
                                strcpy(Nombre2,Auxiliar);
                                Temp = Marcador1;
                                Marcador1 = Marcador2;
                                Marcador2 = Temp;
                                Change = Player;
                                Player = Computer;
                                Computer = Change;
                                Validar = 1;
                            }

                            else if (Respuesta == 2)
                            {
                                printf("Te has rendido\n");
                                Validar = 1;
                                //rendirse
                            }

                            else if (Respuesta == 3)
                            {
                                Validar = 1;
                                //reiniciar
                            }

                            else 
                            {
                                printf("\nEscoja una respuesta valida\n");
                            }

                        }
                        
                    }

                }

                
                
                if(Respuesta != 3)
                {
                    Quien_Gano(&Marcador1, &Marcador2, Nombre1, Nombre2);
                    printf("\nQuieres jugar otra vez? (1 para seguir jugando, otro numero para terminar para terminar): \n");
                    scanf("%d", &Respuesta);

                    if (Respuesta != 1)
                    {
                        Seguir++;
                    }
                }
                
                else
                {
                    printf("\nSe reiniciara el juego por lo que los marcadores volveran a 0\n");
                }
            }
            

            return 0;
            
        }
        

    } 
}
        
        