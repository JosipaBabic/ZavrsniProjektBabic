#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"



void otvoriDatoteku(FILE** datoteka, const char* naziv, const char* nacin) {
    *datoteka = fopen(naziv, nacin);
    if (*datoteka == NULL) {
        printf("Pogreska pri otvaranju datoteke.\n");
        exit(1);
    }
}

void unesiDijete(const char* const imeDatoteke) {
    
    DIJETE podatciDjeteta = { 0 };
    int i;

    while (1) {
        getchar();
        printf("Unesite OIB djeteta (11 znamenki): ");
        scanf("%s", podatciDjeteta.oib);
        
        int areAllDigits = 1;
        for (i = 0; i < strlen(podatciDjeteta.oib); i++) {
            if (podatciDjeteta.oib[i] < '0' || podatciDjeteta.oib[i] > '9') {
                areAllDigits = 0;
                //break;
            }
        }

        if (strlen(podatciDjeteta.oib) == 11 && areAllDigits == 1) {
            break;
        } else {
            printf("Krivi unos! ");
        }
    }

    printf("oso sam pappa -> '%s'", &podatciDjeteta.oib);



    //do {
    //    getchar();
    //    printf("Unesite OIB djeteta (11 znamenki): ");
    //    scanf("%11[^\n]", podatciDjeteta.oib);


    //    if (podatciDjeteta.oib >= 1000000000000 && podatciDjeteta.oib <= 9999999999999) {
    //        unosOk = 1;
    //    }
    //    else {
    //        printf("Krivi unos! ");
    //        unosOk = 0;
    //    }
    //} while (unosOk == 0);

    getchar();
    printf("Unesite ime djeteta: ");
    scanf("%19[^\n]", podatciDjeteta.ime);


    printf("oso sam pappa -> '%s'", &podatciDjeteta.ime);

   // printf("Unesite prezime djeteta: ");
   // fgets(podatciDjeteta->prezime, sizeof(podatciDjeteta->prezime), stdin);
   // podatciDjeteta->prezime[strcspn(podatciDjeteta->prezime, "\n")] = '\0';

   // printf("Unesite oib djeteta: ");
   // fgets(podatciDjeteta->oib, sizeof(podatciDjeteta->oib), stdin);
   // podatciDjeteta->oib[strcspn(podatciDjeteta->oib, "\n")] = '\0';

   ///* printf("Unesite datum rodenja djeteta (dd.mm.gggg): ");
   // fgets(dijete.datumRodenja, sizeof(dijete.datumRodenja), stdin);
   // dijete.datumRodenja[strcspn(dijete.datumRodenja, "\n")] = '\0';*/

   // printf("Unesite broj roditelja (0, 1 ili 2): ");
   // do {
   //     scanf("%d", &podatciDjeteta->brojRoditelja);
   //     if (podatciDjeteta->brojRoditelja < 0 || podatciDjeteta->brojRoditelja>2) {
   //         printf("krivi unos, unesite broj roditelja (0, 1 ili 2): ");
   //     }
   // } while (podatciDjeteta->brojRoditelja < 0 || podatciDjeteta->brojRoditelja>2);
   // 
   // printf("Unesite broj zaposlenih roditelja (0, 1 ili 2): ");
   // do {
   //     scanf("%d", &podatciDjeteta->brojZaposlenihRoditelja);
   //     if (podatciDjeteta->brojZaposlenihRoditelja < 0 || podatciDjeteta->brojZaposlenihRoditelja>2) {
   //         printf("krivi unos, unesite broj zaposlenih roditelja (0, 1 ili 2): ");
   //     }
   // } while (podatciDjeteta->brojZaposlenihRoditelja < 0 || podatciDjeteta->brojZaposlenihRoditelja>2);
   // 
   // printf("Unesite broj braæe i sestara: ");
   // scanf("%d", &podatciDjeteta->brojBraceSestara);
   // 
   // printf("Unesite dijete s posebnim potrebama (1 - da, 0 - ne): ");
   // do {
   //     scanf("%d", &podatciDjeteta->dijeteSPosebnimPotrebama);
   //     if (podatciDjeteta->dijeteSPosebnimPotrebama < 0 || podatciDjeteta->dijeteSPosebnimPotrebama>1) {
   //         printf("krivi unos, unesite vrijednost 1 ili 0 (1 - da, 0 - ne): ");
   //     }
   // } while (podatciDjeteta->dijeteSPosebnimPotrebama < 0 || podatciDjeteta->dijeteSPosebnimPotrebama>1);
   // 
   // printf("Unesite broj godina djeteta (1-6): ");
   // do {
   //     scanf("%d", &podatciDjeteta->brojGodina);
   //     if (podatciDjeteta->brojGodina < 1 || podatciDjeteta->brojGodina>6) {
   //         printf("krivi unos, unesite broj godina djeteta (1-6): ");
   //     }
   // } while (podatciDjeteta->brojGodina < 1 || podatciDjeteta->brojGodina>6);
   // 
   // 
   // podatciDjeteta->zbrojBodova = 0;
   // podatciDjeteta->zbrojBodova += (2 - podatciDjeteta->brojRoditelja);
   // podatciDjeteta->zbrojBodova += podatciDjeteta->brojZaposlenihRoditelja;
   // podatciDjeteta->zbrojBodova += podatciDjeteta->brojBraceSestara;
   // podatciDjeteta->zbrojBodova += podatciDjeteta->dijeteSPosebnimPotrebama;
   // podatciDjeteta->zbrojBodova += podatciDjeteta->brojGodina;
   // 
   // fprintf(datoteka, "%s %s %s \n", podatciDjeteta->ime, podatciDjeteta->prezime, podatciDjeteta->oib);
   // printf("Dijete je uspjesno uneseno u datoteku.\n");
   // printf("Podatci unesenog djeteta su: %s %s %s \n", podatciDjeteta->ime, podatciDjeteta->prezime, podatciDjeteta->oib);
   // 
   // 

   // fprintf(datoteka, "%s %s %s \n", podatciDjeteta->ime, podatciDjeteta->prezime, podatciDjeteta->oib);
   // printf("Dijete je uspjesno uneseno u datoteku.\n");
   // printf("Podatci unesenog djeteta su: %s %s %s \n", podatciDjeteta->ime, podatciDjeteta->prezime, podatciDjeteta->oib);
}





void pretraziPoPrezimenu(DIJETE* podatciDjeteta, int brojDjece, char* prezime) {
    
    int pronadeno = 0;

    for (int i = 0; i < brojDjece; i++) {
        if (strcmp(podatciDjeteta[i].prezime, prezime) == 0) {
            printf("Podaci za dijete s prezimenom %s:\n", prezime);
            printf("Ime: %s\n", podatciDjeteta[i].ime);
            printf("Prezime: %s\n", podatciDjeteta[i].prezime);
            printf("oib: %s\n", podatciDjeteta[i].oib);
            printf("Broj roditelja: %d\n", podatciDjeteta[i].brojRoditelja);
            printf("Broj zaposlenih roditelja: %d\n", podatciDjeteta[i].brojZaposlenihRoditelja);
            printf("Broj braæe i sestara: %d\n", podatciDjeteta[i].brojBraceSestara);
            printf("Dijete s posebnim potrebama: %d\n", podatciDjeteta[i].dijeteSPosebnimPotrebama);
            printf("Broj godina: %d\n", podatciDjeteta[i].brojGodina);
            printf("Zbroj bodova: %d\n", podatciDjeteta[i].zbrojBodova);
            printf("\n");

            pronadeno = 1;
        }
    }

    if (!pronadeno) {
        printf("Nema podataka za dijete s prezimenom %s.\n", prezime);
    }
}

void pretraziPoOibu(DIJETE* podatciDjeteta, int brojDjece, char* oib) {
    
    int pronadeno = 0;

    for (int i = 0; i < brojDjece; i++) {
        if (strcmp(podatciDjeteta[i].oib, oib) == 0) {
            printf("Podaci za dijete s oib-om %s:\n", oib);
            printf("Ime: %s\n", podatciDjeteta[i].ime);
            printf("Prezime: %s\n", podatciDjeteta[i].prezime);
            printf("oib: %s\n", podatciDjeteta[i].oib);
            printf("Broj roditelja: %d\n", podatciDjeteta[i].brojRoditelja);
            printf("Broj zaposlenih roditelja: %d\n", podatciDjeteta[i].brojZaposlenihRoditelja);
            printf("Broj braæe i sestara: %d\n", podatciDjeteta[i].brojBraceSestara);
            printf("Dijete s posebnim potrebama: %d\n", podatciDjeteta[i].dijeteSPosebnimPotrebama);
            printf("Broj godina: %d\n", podatciDjeteta[i].brojGodina);
            printf("Zbroj bodova: %d\n", podatciDjeteta[i].zbrojBodova);
            printf("\n");

            pronadeno = 1;
        }
    }

    if (!pronadeno) {
        printf("Nema podataka za dijete s oib-om %s.\n", oib);
    }
}

void sortirajPoPrezimenu(DIJETE* podatciDjeteta, int brojDjece) {
    int i, j;
    DIJETE tempPodatci;

    for (i = 0; i < brojDjece - 1; i++) {
        for (j = i + 1; j < brojDjece; j++) {
            if (strcmp(podatciDjeteta[i].prezime, podatciDjeteta[j].prezime) > 0) {
                tempPodatci = podatciDjeteta[i];
                podatciDjeteta[i] = podatciDjeteta[j];
                podatciDjeteta[j] = tempPodatci;
            }
        }
    }
}

void rangLista(DIJETE* podatciDjeteta, int brojDjece) {
    int i, j;
    DIJETE tempPodatci;

    for (i = 0; i < brojDjece - 1; i++) {
        for (j = i + 1; j < brojDjece; j++) {
            if (podatciDjeteta[i].zbrojBodova < podatciDjeteta[j].zbrojBodova) {
                tempPodatci = podatciDjeteta[i];
                podatciDjeteta[i] = podatciDjeteta[j];
                podatciDjeteta[j] = tempPodatci;
            }
        }
    }

    printf("Rang lista:\n");

    for (i = 0; i < brojDjece; i++) {
        printf("%d. mjesto: %s %s (%d bodova)\n", i + 1, podatciDjeteta[i].ime, podatciDjeteta[i].prezime, podatciDjeteta[i].zbrojBodova);
    }

    printf("\n");
}

void ispravakPogresnihPodataka(DIJETE* podatciDjeteta, int brojDjece) {
    char oib[13];
    int pronadeno = 0;

    printf("Unesite oib djeteta èije podatke želite ispraviti: ");
    scanf("%s", oib);

    for (int i = 0; i < brojDjece; i++) {
        if (strcmp(podatciDjeteta[i].oib, oib) == 0) {
            printf("Podaci za dijete s oib-om %s:\n", oib);
            printf("Ime: %s\n", podatciDjeteta[i].ime);
            printf("Prezime: %s\n", podatciDjeteta[i].prezime);
            printf("oib: %s\n", podatciDjeteta[i].oib);
            printf("Broj roditelja: %d\n", podatciDjeteta[i].brojRoditelja);
            printf("Broj zaposlenih roditelja: %d\n", podatciDjeteta[i].brojZaposlenihRoditelja);
            printf("Broj braæe i sestara: %d\n", podatciDjeteta[i].brojBraceSestara);
            printf("Dijete s posebnim potrebama: %d\n", podatciDjeteta[i].dijeteSPosebnimPotrebama);
            printf("Broj godina: %d\n", podatciDjeteta[i].brojGodina);
            printf("Zbroj bodova: %d\n", podatciDjeteta[i].zbrojBodova);
            printf("\n");

            printf("Unesite novi broj roditelja (0, 1 ili 2): ");
            scanf("%d", &podatciDjeteta[i].brojRoditelja);
            printf("Unesite novi broj zaposlenih roditelja (0, 1 ili 2): ");
            scanf("%d", &podatciDjeteta[i].brojZaposlenihRoditelja);
            printf("Unesite novi broj braæe i sestara: ");
            scanf("%d", &podatciDjeteta[i].brojBraceSestara);
            printf("Unesite dijete s posebnim potrebama (1 - da, 0 - ne): ");
            scanf("%d", &podatciDjeteta[i].dijeteSPosebnimPotrebama);
            printf("Unesite novi broj godina djeteta (1-6): ");
            scanf("%d", &podatciDjeteta[i].brojGodina);

            // Ažuriraj zbroj bodova
            podatciDjeteta[i].zbrojBodova = 0;
            podatciDjeteta[i].zbrojBodova += (2 - podatciDjeteta[i].brojRoditelja);
            podatciDjeteta[i].zbrojBodova += podatciDjeteta[i].brojZaposlenihRoditelja;
            podatciDjeteta[i].zbrojBodova += podatciDjeteta[i].brojBraceSestara;
            podatciDjeteta[i].zbrojBodova += podatciDjeteta[i].dijeteSPosebnimPotrebama;
            podatciDjeteta[i].zbrojBodova += podatciDjeteta[i].brojGodina;

            printf("Podaci su uspješno ispravljeni.\n");

            pronadeno = 1;
        }
    }

    if (!pronadeno) {
        printf("Nema podataka za dijete s oib-om %s.\n", oib);
    }
}

void izbornik(const char* const imeDatoteke) {
    DIJETE* podatciDjeteta = NULL;
    int brojDjece = 0;
    int odabir;

    while (1) {
        printf("Izbornik:\n");
        printf("1. Unos podataka djeteta\n");
        printf("2. Pretraživanje po prezimenu\n");
        printf("3. Pretraživanje po oib-u\n");
        printf("4. Sortiranje po prezimenu\n");
        printf("5. Rang lista\n");
        printf("6. Ispravak pogresnih podataka\n");
        printf("7. Oslobadanje memorije i izlaz iz programa\n");
        printf("Odaberite opciju: ");
        scanf("%d", &odabir);

        switch (odabir) {
        case 1:
            unesiDijete(imeDatoteke);
            break;
        case 2:
            if (podatciDjeteta == NULL) {
                printf("Niste unijeli podatke.\n");
            }
            else {
                char prezime[100];
                printf("Unesite prezime za pretraživanje: ");
                scanf("%s", prezime);
                pretraziPoPrezimenu(podatciDjeteta, brojDjece, prezime);
            }
            break;
        case 3:
            if (podatciDjeteta == NULL) {
                printf("Niste unijeli podatke.\n");
            }
            else {
                char oib[12];
                printf("Unesite oib za pretraživanje: ");
                scanf("%s", oib);
                pretraziPoOibu(podatciDjeteta, brojDjece, oib);
            }
            break;
        case 4:
            if (podatciDjeteta == NULL) {
                printf("Niste unijeli podatke.\n");
            }
            else {
                sortirajPoPrezimenu(podatciDjeteta, brojDjece);
                printf("Podaci su uspješno sortirani po prezimenu.\n");
            }
            break;
        case 5:
            if (podatciDjeteta == NULL) {
                printf("Niste unijeli podatke.\n");
            }
            else {
                rangLista(podatciDjeteta, brojDjece);
            }
            break;
        case 6:
            if (podatciDjeteta == NULL) {
                printf("Niste unijeli podatke.\n");
            }
            else {
                ispravakPogresnihPodataka(podatciDjeteta, brojDjece);
            }
            break;
        case 7:
            if (podatciDjeteta != NULL) {
                oslobodiMemo(podatciDjeteta);
            }
            printf("Memorija je osloboðena.\n");
            return;
        default:
            printf("Pogrešan odabir. Molimo odaberite ponovno.\n");
        }

        printf("\n");
    }
}

 