#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

PODATCI* zauzimanjeMemPodataka(char ime[20], char prezime[30], char OIB[12], char datumRodenja[12]) {

    PODATCI* tempZauzimanje = NULL;
    tempZauzimanje = (PODATCI*)calloc(4, sizeof(PODATCI));

    if (tempZauzimanje == NULL) {
        return NULL;
    }
    return tempZauzimanje;

}

void otvoriDatoteku(FILE** datoteka, const char* naziv, const char* nacin) {
    *datoteka = fopen(naziv, nacin);
    if (*datoteka == NULL) {
        printf("Pogreska pri otvaranju datoteke.\n");
        exit(1);
    }
}

void unesiDijete(FILE* datoteka) {
    PODATCI dijete;

    printf("Unesite ime djeteta: ");
    fgets(dijete.ime, sizeof(dijete.ime), stdin);
    dijete.ime[strcspn(dijete.ime, "\n")] = '\0';

    printf("Unesite prezime djeteta: ");
    fgets(dijete.prezime, sizeof(dijete.prezime), stdin);
    dijete.prezime[strcspn(dijete.prezime, "\n")] = '\0';

    printf("Unesite OIB djeteta: ");
    fgets(dijete.OIB, sizeof(dijete.OIB), stdin);
    dijete.OIB[strcspn(dijete.OIB, "\n")] = '\0';

    printf("Unesite datum rodenja djeteta (dd.mm.gggg): ");
    fgets(dijete.datumRodenja, sizeof(dijete.datumRodenja), stdin);
    dijete.datumRodenja[strcspn(dijete.datumRodenja, "\n")] = '\0';

    fprintf(datoteka, "%s,%s,%s,%s\n", dijete.ime, dijete.prezime, dijete.OIB, dijete.datumRodenja);
    printf("Dijete je uspjesno uneseno u datoteku.\n");
    printf("Podatci unesenog djeteta su: %s, %s, %s, %s\n", dijete.ime, dijete.prezime, dijete.OIB, dijete.datumRodenja);
}

void pretraziDatoteku(FILE* datoteka, const char* prezime) {
    PODATCI dijete;
    char temp;
    int pronadjeno = 0;

    rewind(datoteka);  // Vraca na pocetak datoteke


    while (fscanf(datoteka, "%s, %s, %s, %s\n", dijete.ime, dijete.prezime, dijete.OIB, dijete.datumRodenja) != EOF) {
        temp = strcmp(dijete.prezime, prezime);
        if (temp==0) {
            printf("Pronadeno dijete:\n");
            printf("Ime: %s\n", dijete.ime);
            printf("Prezime: %s\n", dijete.prezime);
            printf("OIB: %s\n", dijete.OIB);
            printf("Datum rodenja: %s\n", dijete.datumRodenja);
            pronadjeno = 1;
        }
        
    }
    if (!pronadjeno) {
    printf("Dijete s prezimenom '%s' nije pronadeno.\n", prezime);
     }
    
}

void sortirajDatoteku(FILE* datoteka) {
    int brojDjece = 0;
    PODATCI* djeca = NULL;
    PODATCI temp;

    rewind(datoteka);  // Vraca na pocetak datoteke

    while (fscanf(datoteka, "%s, %s, %s, %s\n", temp.prezime, temp.OIB, temp.datumRodenja) != EOF) {
        brojDjece++;

        for (int i = 0; i < brojDjece - 1; i++) {
            for (int j = i + 1; j < brojDjece; j++) {
                if (strcmp(djeca[i].prezime, djeca[j].prezime) > 0) {
                    temp = djeca[i];
                    djeca[i] = djeca[j];
                    djeca[j] = temp;
                }
            }
        }
    }

    printf("Sortirana datoteka:\n");
    for (int i = 0; i < brojDjece; i++) {
        printf("%s, %s, %s\n", djeca[i].prezime, djeca[i].OIB, djeca[i].datumRodenja);
    }

    free(djeca);
}