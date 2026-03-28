#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <string.h>

int main() {
    char sir[] = "zabcdefabxyzwq"; /* Sir de caractere aleatoare */
    int i, n = strlen(sir);
    
    int max_len = 1, current_len = 1;
    int max_start = 0, current_start = 0;
    char *nou_subsir;

    /* Algoritm pentru gasirea celui mai lung subsir strict crescator */
    for (i = 1; i < n; i++) {
        if (sir[i] > sir[i - 1]) {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                max_start = current_start;
            }
            current_len = 1;
            current_start = i;
        }
    }
    /* Verificam si ultima secventa */
    if (current_len > max_len) {
        max_len = current_len;
        max_start = current_start;
    }

    printf("Sirul original: %s\n", sir);

    /* Alocam memorie pentru noul subsir (lungime + 1 pentru terminatorul de sir '\0') */
    nou_subsir = (char *)malloc((max_len + 1) * sizeof(char));
    
    if (nou_subsir != NULL) { /* Verificam daca alocarea a avut succes */
        /* Copiem subsirul de memorie de la sursa la destinatie folosind memcpy */
        memcpy(nou_subsir, &sir[max_start], max_len);
        nou_subsir[max_len] = '\0'; /* Adaugam terminatorul */
        
        printf("Cel mai lung subsir crescator este: %s\n", nou_subsir);
        printf("Lungime: %d caractere\n", max_len);

        /* Eliberam blocul de memorie alocat */
        free(nou_subsir);
    } else {
        printf("Eroare: Nu s-a putut aloca memorie (malloc a returnat NULL)!\n");
    }

    return 0;
}