#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 30
#define MAX 2
typedef struct osoba {
    char *imie;
    char *nazwisko;
    char *miejscowosc;
    int wiek;
} OSOBA;

//TODO implements 3 functions

void inicjalizacja_OSOBA(OSOBA * dane, char * tab_imie, char *  tab_nazwisko, char * tab_miejscowosc, int age) {
    dane->imie = (char *) malloc(strlen(tab_imie) + 1 * sizeof(char));
    dane->nazwisko = (char *) malloc(strlen(tab_nazwisko)+ 1 * sizeof(char));
    dane->miejscowosc = (char *) malloc(strlen(tab_miejscowosc) + 1 * sizeof(char));
    strcpy(dane->imie, tab_imie);
    strcpy(dane->nazwisko, tab_nazwisko);
    strcpy(dane->miejscowosc, tab_miejscowosc);
}

void wyswietl(OSOBA * dane){
    printf("\n%s\n", dane->imie);
    printf("%s\n", dane->nazwisko);
    printf("%s\n", dane->miejscowosc);
}

void wyswietl_alter(OSOBA dane){
    printf("\n%s\n", dane.imie);
    printf("%s\n", dane.nazwisko);
    printf("%s\n", dane.miejscowosc);
}

void dealokacja_OSOBA(OSOBA * dane){
    free(dane->imie);
    free(dane->nazwisko);
    free(dane->miejscowosc);
}

int main(void) {
    OSOBA dane[MAX];
    char tab_imie[N + 1];
    char tab_nazwisko[N + 1];
    char tab_miejscowosc[N + 1];
    int i = 0, age, k;
    while (i < MAX) {
        printf("Podaj imie: ");
        gets(tab_imie);
        printf("Podaj nazwisko: ");
        gets(tab_nazwisko);
        printf("Podaj miejscowosc: ");
        gets(tab_miejscowosc);
        printf("Podaj wiek: ");
        scanf("%d", &age);
        while (getchar() != '\n');
        inicjalizacja_OSOBA(&dane[i], tab_imie, tab_nazwisko, tab_miejscowosc, age);
        i++;
    }
    printf("Podaj, ktory rekord tablicy dane chcesz wyswietlic.\n");
    printf("Wyjscie poza indeks tablicy lub wpisanie znaku nie bedacego liczba konczy wypisywanie!");
    while (scanf("%d", &k) == 1 && k >= 0 && k < MAX) {
        printf("Rekord %d\n", k);
        printf("--------------------------\n");
       // wyswietl(&dane[k]);
       wyswietl_alter(dane[k]);
        printf("--------------------------\n");
        while (getchar() != '\n');
        printf("Podaj ktory rekord tablicy dane chcesz wyswietlic.\n");
        printf("Wyjscie poza idkeks tablicy lub wpisanie znku nie bedacego liczba konczy wypisywanie!\n");
    }
    for (int i = 0; i < MAX; i++)
        dealokacja_OSOBA(&dane[i]);
    printf("KONIEC!");
    return 0;
}