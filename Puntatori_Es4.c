#include <stdio.h>
#include <string.h>
#include <limits.h>

void inserimento(int array_numeri[], int *i)
{
    int numero_inserito;
    do
    {
        scanf("%d", &numero_inserito);
        if (numero_inserito != -1)
        {
            array_numeri[*i] = numero_inserito;
            (*i)++;
        }
    } while (numero_inserito != -1);
}
void visualizza(int array[], int lunghezza)
{
    for (int i = 0; i < lunghezza; i++)
    {
        printf("Numero in posizione %d: %d\n", i, array[i]);
    }
}
void visualizza_inverso(int array[], int lunghezza)
{
    for (int i = lunghezza - 1; i >= 0; i++)
    {
        printf("Numero in posizione %d: %d\n", i, array[i]);
    }
}
void inserimento_coda(int array_numeri[], int *lunghezza)
{
    int numero;
    printf("\nInserisci il numero da inserire: ");
    scanf("%d", &numero);
    array_numeri[(*lunghezza)++] = numero;
    printf("\nValore inserito correttamente\n");
}
int ricerca(int array[], int lunghezza, int ricercato)
{
    for (int i = 0; i < lunghezza; i++)
    {
        if (array[i] == ricercato)
            return i;
    }
    return -1;
}
void modifica(int array[], int posizione)
{
    int numero;
    printf("Inserisci la modifica: ");
    scanf("%d", &numero);
    array[posizione] = numero;
}
void elimina(int array[], int posizione, int *dimensione)
{
    for (int i = posizione + 1; i < *dimensione; i++)
    {
        array[i - 1] = array[i];
    }
    array[*dimensione - 1] = 0;
    (*dimensione)--;
}
void inserisci_posizione(int array[], int *lunghezza, int posizione)
{
    int numero;
    printf("\nInserisci il numero da inserire: ");
    scanf("%d", &numero);
    (*lunghezza)++;
    for (int i = (*lunghezza); i > posizione; i--)
    {
        array[i] = array[i - 1];
    }
    array[posizione] = numero;
}
int massimo(int array[], int lunghezza)
{
    int numero = array[0];
    int max = numero;
    int posizione_max = 0;
    for (int i = 1; i < lunghezza; i++)
    {
        numero = array[i];
        if (numero > max)
        {
            posizione_max = i;
            max = numero;
        }
    }
    return posizione_max;
}
int menu()
{
    int scelta;
    printf("\n| Menù |\n");
    printf("1) Visualizza contenuto dell'array\n");
    printf("2) Inserisci un elemto in coda all'array\n");
    printf("3) Modifica un elemento se presente\n");
    printf("4) Elimina un elemento se presente\n");
    printf("5) Ricerca un elemento\n");
    printf("6) Inserisci un elemento in una certa posizione\n");
    printf("7) Visualizza contenuto dell'array in modo inverso\n");
    printf("8) Visualizza il valore massimo presente nell'array\n");
    printf("0) Termina il programma\n");
    printf("Seleziona: ");
    scanf("%d", &scelta);
    printf("\n");
    return scelta;
}
int main(int argc, char *argv[])
{
    int numeri[SHRT_MAX];

    int num;
    printf("Inserisci numeri, per terminare inserire il valore -1:\n");
    inserimento(numeri, &num);

    int selezione, numero_ricerca, posizione;
    do
    {
        selezione = menu();
        switch (selezione)
        {
        case 0:
            printf("Termina il programma\n");
            break;
        case 1:
            printf("| Visualizza |\n");
            visualizza(numeri, num);
            break;
        case 2:
            printf("| Inserisci un elemento in coda |\n");
            inserimento_coda(numeri, &num);
            break;
        case 3:
            printf("| Modifica un elemento |\n");
            printf("Inserisci numero da modificare: ");
            scanf("%d", &numero_ricerca);
            posizione = ricerca(numeri, num, numero_ricerca);
            if (posizione != -1)
            {
                modifica(numeri, posizione);
                printf("Il numero è stato modificato correttamente\n");
            }
            else
                printf("Il numero non è presente nell'array\n");
            break;
        case 4:
            printf("| Elimina un elemento |\n");
            printf("Inserisci numero da eliminare: ");
            scanf("%d", &numero_ricerca);
            posizione = ricerca(numeri, num, numero_ricerca);
            if (posizione != -1)
            {
                elimina(numeri, posizione, &num);
                printf("Il numero è stato eliminato correttamente\n");
            }
            else
                printf("Il numero non è presente nell'array\n");
            break;
        case 5:
            printf("| Ricerca un elemento |\n");
            printf("Inserisci numero da ricercare: ");
            scanf("%d", &numero_ricerca);
            posizione = ricerca(numeri, num, numero_ricerca);
            if (posizione != -1)
                printf("Il numero %d si trova in posizione %d\n", numero_ricerca, posizione);
            else
                printf("Il numero non è presente nell'array\n");
            break;
        case 6:
            printf("| Inserisci un elemento in una certa posizione |\n");
            printf("\nInserisci la posizione in cui inserire il numero: ");
            scanf("%d", &posizione);
            if (posizione < 0)
                printf("\nPosizione non valida\n");
            else
            {
                inserisci_posizione(numeri, &num, posizione);
                printf("\nNumero inserito correttamente in posizione %d\n", posizione);
            }
            break;
        case 7:
            printf("| Visualizza in modo inverso |\n");
            visualizza_inverso(numeri, num);
            break;
        case 8:
            printf("| Valore massimo dell'array |\n");
            posizione = massimo(numeri, num);
            printf("\nIl valore massimo è %d in posizione %d\n", numeri[posizione], posizione);
            break;
        default:
            printf("Voce selezionata non disponibile\n");
            break;
        }
    } while (selezione != 0);
    visualizza(numeri, num);
}