#include <stdio.h>

int main(){

    int vector[10],i, j, k;
    int swap_var,quantita;

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