#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero;
    int k = 0;
    printf("Inserisci un numero: ");
    do
    {
        scanf("%d", &numero);
    } while (numero <= 0);
    printf("\nCoppie di numeri: \n");
    for (int i = numero; i >= k; i--)
    {
        printf("%d e %d\n", i, k);
        k++;
    }
}