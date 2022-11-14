#include <stdio.h>
#include <string.h>
#define MAX 81
/* ricerca di parole in un file di testo */
int main()
{
    FILE *f1;
    char S[MAX];
    int contatore = 0;
    f1 = fopen("F1.txt", "r");
    if (f1 == NULL)
    {
        printf("Errore apertura del file!\n");
        return 0;
    }
    fscanf(f1, "%s", S);
    while (!feof(f1))
    {
        contatore++;
        fscanf(f1, "%s", S);
    }
    printf("Il file contiene %d parole\n", contatore);
    fclose(f1);
}
