#include <stdio.h>
#include <stdlib.h>

struct EList {
    int klucz;
    struct EList *nast;
};


struct EList *dodaj_elem();

void drukuj_liste(struct EList *q);

struct EList *usun_elem(struct EList *q, int x);

void drukuj_rek(struct EList *q);

void drukuj_ostatni(struct EList *q);

int getListSize(struct EList *head){
    if(!head){
        return 0;
    }
    struct EList * item = head;
    int count = 1;
    while(item->nast){
        count++;
        item = item->nast;
    }
    return count;
}

int main(void) {
    int i, x;
    struct EList *glowa = NULL;

    struct EList *prev = NULL;
    struct EList *current;
    for (i = 0; i < 5; i++) {
        current = dodaj_elem();
        if(prev){
            prev->nast = current;
        }else{
            glowa = current;
        }
        prev = current;
    }
    printf("\n");
    drukuj_liste(glowa);
    printf("\nIlosc elementow to: %d", getListSize(glowa));


//    if (glowa != NULL) {
//        printf("\nPodaj element do usuniecia: ");
//        scanf("%d", &x);
//        glowa = usun_elem(glowa, x);
//    } else
//        printf("Lista pusta");
//
//    printf("\n");
//    drukuj_rek(glowa);
//
//    printf("\n");
//    drukuj_ostatni(glowa);

    return 0;
}

//------------------------------------------------------
struct EList *dodaj_elem() {
    struct EList *pom;
    int x;
    printf("Podaj klucz");
    scanf("%d", &x);
    pom = (struct EList *) malloc(sizeof(struct EList));
    pom->klucz = x;
    pom->nast = NULL;
    return pom;
}

//------------------------------------------------------
void drukuj_liste(struct EList *q) {
    struct EList *pom;
    int i = 0;
    pom = q;
    if (pom == NULL)
        printf("\nLista pusta");
    else {
        printf("\nElementy listy:");
        while (pom != NULL) {
            printf("\nElement nr %d: %d", ++i, pom->klucz);
            pom = pom->nast;
        }
    }
}

//------------------------------------------------------
struct EList *usun_elem(struct EList *q, int x) {
    struct EList *pom, *tmp;
    pom = q;
    while (pom != NULL && pom->klucz != x) {
        tmp = pom;
        pom = pom->nast;
    }
    if (pom != NULL) {
        if (pom == q)
            q = pom->nast;
        else
            tmp->nast = pom->nast;

        free(pom);
    } else
        printf("Elementu %d nie ma w liscie", x);
    return q;
}

//------------------------------------------------------
void drukuj_rek(struct EList *q) {
    if (q != NULL) {
        drukuj_rek(q->nast);
        printf("\n%d", q->klucz);
    }
}

//------------------------------------------------------
void drukuj_ostatni(struct EList *q) {
    if (q->nast == NULL)
        printf("\n%d", q->klucz);
    else
        drukuj_ostatni(q->nast);
}




