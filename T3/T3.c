#include <stdio.h>
#include <stdlib.h>


/*----------------  Parte 1--------------*/
float x[10] = {0.97, 0.4, 0.3, 0.84, 1.2, 0.7, 0.6, 0.9, 0.1, 0.25};
float *p;

void main(){

/* Parte a) */
p = &x[6];
/* Parte b) */
*p += 3;

/* Parte c) */
p = (p +1) ;

*p = 1;

/* Parte c) */
p = &x[6];
p = (p -5) ;
*p = 3.61;

/* Parte c) */

p = (p +3) ;
*p = 3.56;

int length = sizeof(x)/sizeof(x[0]);
printf("Array de voltjes: \n");    
for (int i = 0; i < length; i++) {     
        printf("%f ", x[i]);     
    }      

/* Source: https://www.javatpoint.com/c-program-to-print-the-elements-of-an-array*/



}