#ifndef HEADER_H
#define HEADER_H


typedef struct podatci {

	char ime[20];
	char prezime[30];
	char OIB[13];
	char datumRodenja[13];

}PODATCI;

typedef struct parametri {

	short brojRoditelja;
	short brojBraceISestara;
	short zaposleniRoditelj;
	short posebnePotrebe;
	short dijeteIznad4Godine;
	int zbrojBodova;


};

PODATCI* zauzimanjeMemPodataka(char ime[20], char prezime[30], char OIB[12]);
void otvoriDatoteku(FILE** datoteka, const char* naziv, const char* nacin);
void unesiDijete(FILE* datoteka);
void pretraziDatoteku(FILE* datoteka, const char* prezime);
void sortirajDatoteku(FILE* datoteka);

#endif // !HEADER_H

