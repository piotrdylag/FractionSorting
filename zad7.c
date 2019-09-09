#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define W 8
#define K 12

char randChar();
void uzupelnij_wyswietl(char[W][K]);

int main (void){
    time_t t;
    time(&t);
    srand(t);
    char tablica[W][K];
    uzupelnij_wyswietl(tablica);
    return 0;
}

char randChar(){
    int x[] = {65 + (rand()%26), 97 + (rand()%26)};
    char c = (char)x[rand()%2];
    return c;
}

void uzupelnij_wyswietl(char tab[W][K]){
    for(int i = 0; i < W; i++){
        for(int j = 0; j < K; j++){
            tab[i][j] = randChar();
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
}
