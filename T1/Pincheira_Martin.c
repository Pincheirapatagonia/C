#include <stdio.h>
#include <math.h>
int main()
{
    char op;
    int a, b;
    while (1 == 1)
    {
        printf("Ingresa primer digito: ");
        scanf("%d", &a);

        printf("Ingresa operador(+,-,*,/,%%,P, E,<,>,=,!,R,L): \nF para salir \n");
        scanf("%c", &op);
        scanf("%c", &op);

        if (op == 'F')
        {
            printf("Adios!");
            break;
        }
        
        else if (op == 'P'){
            printf("%d*Pi =\t%f\n", a, a*M_PI);
        }
        
        else if (op == 'E'){
            printf("%d*e =\t%f\n", a, a*M_E);
        }
        
        else if (op == '!'){
            printf("Neg(%d) =\t%i\n", a, ~a);
        }
        else {
            

        printf("Ingresa segundo digito: ");
        scanf("%d", &b);

        switch (op)
        {
        case '+':
            printf("%d + %d =\t%d\n", a, b, a + b);
            break;
        case '-':
            printf("%d - %d =\t%d\n", a, b, a - b);
            break;
        case '/':
            if (a % b == 0)
            {
                printf("%d / %d =\t%d\n", a, b, a / b);
            }
            else
            {
                float x = (float)a;
                float y = (float)b;
                printf("%d / %d =\t%f\n", a, b, x / y);
            }
            break;
        case '%':
            printf("%d %% %d =\t%d\n", a, b, a % b);
            break;
        case '*':
            printf("%d * %d =\t%d\n", a, b, a * b);
            break;

        case '<':
            printf("%d < %d?=\t%d (1 = TRUE/ 0 = FALSE) \n", a, b, a < b);
            break;

        case '>':
            printf("%d > %d?=\t%d (1 = TRUE/ 0 = FALSE) \n", a, b, a > b);
            break;

        case '=':
            printf("%d = %d?=\t%d (1 = TRUE/ 0 = FALSE) \n", a, b, a == b);
            break;

        case '&':
            printf("%d & %d=\t%d\n", a, b, a & b);
            break;

        case '|':
            printf("%d | %d=\t%d\n", a, b, a | b);
            break;
            
        case 'R':
            printf("%d >> %d=\t%d\n", a, b, a >> b);
            break;
        
        case 'L':
            printf("%d << %d=\t%d\n", a, b, a << b);
            break;

        default:
            printf("Error, ingrese validos");
        }
        }
    }
    return 0;
}