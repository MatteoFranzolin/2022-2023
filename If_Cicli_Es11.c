#include <stdio.h>
#include <stdlib.h>

void disegna(int numero)
{
    for (int i = 0; i < numero; i++)
    {
        printf("*");
    }
    for (int k = 1; k < numero - 1; k++)
    {
        printf("\n*");
        for (int i = 1; i < numero - 1; i++)
        {
            printf(" ");
        }
        printf("*");
    }
    printf("\n");
    for (int i = 0; i < numero; i++)
    {
        printf("*");
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    int numero;
    if (argc == 1)
        printf("\nNon è stato inserito un numero\n");
    else
    {
        numero = atoi(argv[1]);
        if (numero > 0)
        {
            disegna(numero);
        }
        else
            printf("\nIl numero inserito non è un intero positivo\n");
    }
    return 0;
}