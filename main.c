#include <stdio.h>
#include <malloc/_malloc.h>
#include <string.h>

#define MAX 100

struct Latitudine {
    int grade;
    int minute;
    int secunde;
};

struct Longitudine {
    int grade;
    int minute;
    int secunde;
};

struct POI {
    struct Latitudine latitudine;
    struct Longitudine longitudine;
    char denumire_POI[MAX];
};

void citire_fisier(struct POI **poi, int *n);

void verificare_date(struct POI *poi, int n);

void afisare_teatru(struct POI *poi, int n);

void scriere_fisier_nou(struct POI *poi, int n);

int main() {
    struct POI *puncte_de_inetres;
    int nr_puncte;

    citire_fisier(&puncte_de_inetres, &nr_puncte);
    verificare_date(puncte_de_inetres, nr_puncte);
    afisare_teatru(puncte_de_inetres, nr_puncte);
    scriere_fisier_nou(puncte_de_inetres, nr_puncte);


}

//functie care citeste datele din fisier
void citire_fisier(struct POI **poi, int *n) {
    FILE *fp;
    char nume_fisier[] = "matrice.txt";
    fp = fopen(nume_fisier, "r");

    if (fp == NULL) {
        printf("Eroare la deschiderea fisierului");
    }

    //citire numar puncte de interes
    fscanf(fp, "%d", n);

    //alocare memorie dinamica pentru structurile POI
    *poi = (struct POI *) malloc(*n * sizeof(struct POI));

    //citire date pentru fiecare punct de interes
    for (int i = 0; i < *n; i++) {
        fscanf(fp, "%d" "%d" "%d" "%d" "%d" "%d" "%s", &(*poi)[i].latitudine.grade, &(*poi)[i].latitudine.minute,
               &(*poi)[i].latitudine.secunde, &(*poi)[i].longitudine.grade, &(*poi)[i].longitudine.minute,
               &(*poi)[i].longitudine.secunde, (*poi)[i].denumire_POI);
    }

    //inchidere fisier dupa citire date
    fclose(fp);

}

//functie care verifica daca datele respecta formatul cerut
void verificare_date(struct POI *poi, int n) {
    for (int i = 0; i < n; i++) {
        if (poi[i].latitudine.grade < -90 || poi[i].latitudine.grade > 90) {
            printf("Latitudinea trebuie sa fie in intervalul [-90, +90].");
        } else if (poi[i].longitudine.grade < -180 || poi[i].longitudine.grade > 190) {
            printf("Longitudinea trebuie sa fie in intervalul [-180, +180].");
        } else if (poi[i].longitudine.minute < 0 || poi[i].longitudine.minute > 60) {
            printf("Minutele trebuie sa fie in intervalul [0. +60].");
        } else if (poi[i].longitudine.secunde < 0 || poi[i].longitudine.secunde > 60) {
            printf("Secundele trebuie sa fie in intervalul [0. +60].");
        } else if (poi[i].latitudine.minute < 0 || poi[i].latitudine.minute > 60) {
            printf("Minutele trebuie sa fie in intervalul [0. +60].");
        } else if (poi[i].latitudine.secunde < 0 || poi[i].latitudine.secunde > 60) {
            printf("Secundele trebuie sa fie in intervalul [0. +60].");
        } else {
            printf("\nDatele respecta structura standard.");
        }

    }
}

//functie care verifica daca exista un element POI cu denumirea teatru
void afisare_teatru(struct POI *poi, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(poi[i].denumire_POI, "teatru") == 0) {
            printf("\nLongitudine: %d %d %d", poi[i].longitudine.grade, poi[i].longitudine.minute,
                   poi[i].longitudine.secunde);
            printf("\nLatitudine: %d %d %d", poi[i].latitudine.grade, poi[i].latitudine.minute,
                   poi[i].latitudine.secunde);
            printf("\nDenumire: %s", poi[i].denumire_POI);
        }
    }
}

//functie care scrie in fisier nou, datele POI din romania
void scriere_fisier_nou(struct POI *poi, int n) {

    FILE *fp;
    char nume[] = "fisier_nou_oras2.txt";
    fp = fopen(nume, "w");

    if (fp != NULL) {
        for (int i = 0; i < n; i++) {
            if (poi[i].latitudine.grade > 43 && poi[i].latitudine.grade < 48 && poi[i].longitudine.grade > 20 &&
                poi[i].longitudine.grade < 29) {
                fprintf(fp, "%d %d %d %d %d %d %s\n", poi[i].latitudine.grade, poi[i].latitudine.minute,
                        poi[i].latitudine.secunde, poi[i].longitudine.grade, poi[i].longitudine.minute,
                        poi[i].longitudine.secunde, poi[i].denumire_POI);
                printf("\nLatitudine: %d %d %d\n", poi[i].latitudine.grade, poi[i].latitudine.minute,
                       poi[i].latitudine.secunde);
                printf("\nLongitudine: %d %d %d\n", poi[i].longitudine.grade, poi[i].longitudine.minute,
                       poi[i].longitudine.secunde);
                printf("\nDenumire: %s\n", poi[i].denumire_POI);
            }
        }
    }


}
