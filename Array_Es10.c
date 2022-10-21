#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int controllo_giorno(int giorno)
{
    if (giorno > 31 || giorno < 1)
        return -1;
    return 0;
}
int controllo_mese(int mese)
{
    if (mese > 12 || mese < 1)
        return -1;
    return 0;
}
int controllo_anno(int anno, int anno_corrente)
{
    if (anno > anno_corrente)
        return -1;
    return 0;
}
int main(int argc, char *argv[])
{
    const int DIM = 9;
    char input[DIM];
    const int anno_corrente = 2022;
    printf("Inserisci una data di nascita (8 caratteri)\n");
    fgets(input, DIM, stdin);
    int giorno, mese, anno;
    char stringa_giorno[2];
    stringa_giorno[0] = input[0];
    stringa_giorno[1] = input[1];
    giorno = atoi(stringa_giorno);
    printf("%d\n", giorno);
    char stringa_mese[2];
    stringa_mese[0] = input[2];
    stringa_mese[1] = input[3];
    mese = atoi(stringa_mese);
    printf("%d\n", mese);
    char stringa_anno[4];
    stringa_anno[0] = input[4];
    stringa_anno[1] = input[5];
    stringa_anno[2] = input[6];
    stringa_anno[3] = input[7];
    anno = atoi(stringa_anno);
    printf("%d\n", anno);
    if (controllo_giorno(giorno) == -1)
        printf("\nIl giorno inserito è errato\n");
    else if (controllo_mese(mese) == -1)
        printf("\nIl mese inserito è errato\n");
    if (controllo_anno(anno, anno_corrente) == -1)
        printf("\nL'anno inserito è errato\n");
    else
        printf("\nData di nascita: %d/%d/%d\n", giorno, mese, anno);
}