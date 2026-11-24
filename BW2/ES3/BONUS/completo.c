#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Queste variabili sono usate da entrambe le funzioni. */
int vector[10], i, j, k;
int swap_var, quantita;

/* Dichiarazioni delle funzioni gia presenti nel file. */
int controllato(void);
int vulnerabile(void);

int main(void)
{
    char testo[30];

    printf("Quale funzionamento vuoi adottare? Vulnerabile o Controllato?\n");

    /* Leggiamo una parola senza superare la dimensione di testo. */
    if (scanf("%29s", testo) != 1)
    {
        printf("Errore nella lettura dell'input.\n");
        return 1;
    }

    /* Convertiamo la scelta in minuscolo. */
    for (int indice = 0; testo[indice] != '\0'; indice++)
    {
        testo[indice] = (char)tolower((unsigned char)testo[indice]);
    }

    /* Chiamiamo le funzioni mantenendo i loro nomi originali. */
    if (strcmp(testo, "controllato") == 0)
    {
        return controllato();
    }
    else if (strcmp(testo, "vulnerabile") == 0)
    {
        return vulnerabile();
    }

    printf("Modalita non riconosciuta.\n");
    return 1;
}

int controllato(){

    printf("Inserisci numeri interi oppure 'e' per terminare:\n");

    i = 0;

    while (1){
        /* Controlliamo il limite prima di leggere un altro numero. */
        if (i >= 10)
        {
            printf("ATTENZIONE: raggiunta la capacità massima di 10 numeri.\n");
            printf("L'inserimento viene terminato.\n");
            break;
        }

        printf("[%d]: ", i + 1);

        /* Un input non numerico, come 'e', termina l'inserimento. */
        if (scanf("%d", &vector[i]) != 1){
            break;
        }
        i++;
    }

    /* Conserviamo il numero di elementi realmente inseriti. */
    quantita = i;

    if (quantita == 0)
    {
        printf("Non hai inserito nessun numero.\n");
        return 0;
    }

	printf ("Il vettore inserito e':\n");
	for ( i = 0 ; i < 10 ; i++){
        int t= i+1;
        printf("[%d]: %d", t, vector[i]);
		printf("\n");
	}

    /* Ordiniamo soltanto gli elementi inseriti con Bubble Sort. */
	for (j = 0 ; j < 10 - 1; j++){
		for (k = 0 ; k < 10 - j - 1; k++){
			if (vector[k] > vector[k+1]){
				swap_var=vector[k];
				vector[k]=vector[k+1];
				vector[k+1]=swap_var;
				}
			}
		}

	printf("Il vettore ordinato e':\n");
	for (j = 0; j < 10; j++){
		int g = j+1;
		printf("[%d]:", g);
		printf("%d\n", vector[j]);
		}

    return 0;
}

int vulnerabile(){

	printf("Inserisci un numero intero oppure 'e' per terminare:\n");

	i = 0;

	/* Continua finché viene inserito un numero intero, Scrivendo 'e', scanf restituisce 0 e il ciclo termina. */
	while (1){	
		if (scanf("%d", &vector[i]) != 1){
            break;
    	}
    	i++;
	}


	printf ("Il vettore inserito e':\n");
	for ( i = 0 ; i < 10 ; i++){
        int t= i+1;
        printf("[%d]: %d", t, vector[i]);
		printf("\n");
	}


	for (j = 0 ; j < 10 - 1; j++){
		for (k = 0 ; k < 10 - j - 1; k++){
			if (vector[k] > vector[k+1]){
				swap_var=vector[k];
				vector[k]=vector[k+1];
				vector[k+1]=swap_var;
				}
			}
		}
	printf("Il vettore ordinato e':\n");
	for (j = 0; j < 10; j++){
		int g = j+1;
		printf("[%d]:", g);
		printf("%d\n", vector[j]);
		}

	return 0;

}