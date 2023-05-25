#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"


int main() {

    FILE* datoteka;
    char prezime[30];
    int izbor;

    otvoriDatoteku(&datoteka, "vrtic.txt", "a+");

    do {
        printf("\nOdaberite opciju:\n");
        printf("1. Unesi dijete\n");
        printf("2. Pretrazi dijete\n");
        printf("3. Sortiraj djecu\n");
        printf("4. Izlaz\n");
        printf("Vas odabir: ");
        scanf("%d", &izbor);
        getchar();

        switch (izbor) {
        case 1:
            unesiDijete(datoteka);
            break;
        case 2:
            printf("Unesite prezime djeteta za pretragu: ");
            fgets(prezime, sizeof(prezime), stdin);
            pretraziDatoteku(datoteka, prezime);
            break;
        case 3:
            sortirajDatoteku(datoteka);
            break;
        case 4:
            printf("Hvala na koristenju programa!\n");
            break;
        default:
            printf("Nepoznata opcija, pokušajte ponovno.\n");
        }
    } while (izbor != 4);

    fclose(datoteka);

    return 0;
}
