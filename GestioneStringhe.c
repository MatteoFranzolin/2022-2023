#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int contiene_lettere(char stringa[])
{
    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (stringa[i] < 97 || stringa[i] > 122)
        {
            return 0;
        }
    }
    return 1;
}
int conta_frequenza(char stringa[], char carattere)
{
    int frequenza=0;
    for (int i = 0; i < strlen(stringa) - 1; i++)
    {
        if (stringa[i] == carattere)
        {
            frequenza++;
        }
    }
    return frequenza;
}
int main(int argc, char *argv[])
{
    char stringa[10];
    char lettera;
    int frequenza;
    int i = 0;
    fgets(stringa, 10, stdin);
    for (int i = 0; i < strlen(stringa); i++)
    {
        stringa[i] = tolower(stringa[i]);
    }
    int selezione;
    do
    {
        printf("\n1) Contiene solo lettere");
        printf("\n2) Conta frequenza di una lettera");
        printf("\n3) Crea due stringhe");
        printf("\n4) Verifica le doppie");
        printf("\nSelezione: ");
        scanf("%d", &selezione);
        switch (selezione)
        {
        case 1:
            printf("Contiene solo lettere: ");
            if (contiene_lettere(stringa) == 1)
            {
                printf("si\n");
            }
            else
                printf("no\n");
            break;
        case 2:
            printf("Conta frequenza di una lettera");
            printf("Inserisci lettera: ");
            scanf("%c", &lettera);
            frequenza=conta_frequenza(stringa, lettera);
            printf("La frequenza della lettera %c è di %d", lettera, frequenza);
            break;
        case 3:
            printf("Crea due stringhe");
            break;
        case 4:
            printf("Verifica le doppie");
            break;
        default:
            return 0;
            break;
        }
    } while (1);
}