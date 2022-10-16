#include <stdio.h>
#include <string.h>

int conta_consonanti(int vocali, int lunghezza)
{
    dasda
}
int conta_vocali(char parola[])
{
    int vocali_parola=0;
    for (int i = 0; i < strlen(parola); i++)
    {
        if (parola[i] == 'a' || parola[i] == 'a' || parola[i] == 'e' || parola[i] == 'i' || parola[i] == 'o' || parola[i] == 'u')
            vocali_parola++;
    }
    return vocali_parola;
}
int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        int vocali_totali = 0, consonanti_totali = 0, vocali_parola;
        for (int i = 1; i < argc; i++)
        {
            vocali_parola = conta_vocali(argv[i]);
            consonanti_totali += strlen(argv[i])-vocali_parola;
            vocali_totali+=vocali_parola;
        }
        printf("Vocali: %d\n", vocali_totali);
        printf("Consonanti: %d\n", consonanti_totali);
    }
    else
    {
        printf("Non sono state inserite stringhe");
    }
    return 0;
}