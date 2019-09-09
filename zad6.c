#include<stdio.h>
#include<stdlib.h>
#define N 21
typedef struct towar{
    unsigned int id;
    char nazwa[N];
    float cena;
} TOWAR;
// argc => argument count
//argv => arguments vector
int main(int argc, char *argv[]){
    char * filename;
    if(argc == 2){
        filename = argv[1];
    } else{
        printf("Nie podano naazwy pliku");
        return 1;
    }

    FILE *fp = fopen(filename, "w+b");
    if(fp == NULL){
        perror("Wysy?pi? b??d przy otwieraniu pliku");
        return 0;
    }
TOWAR produkt = {.nazwa = "pralka", .cena = 899.99, .id = 1};
    fwrite(&produkt, sizeof(produkt), 1, fp);

    fclose(fp);
TOWAR kopia_produkt;

printf("id: %u nazwa: %s cena %.2f zl",
kopia_produkt.id, kopia_produkt.nazwa, kopia_produkt.cena);

return 0;
}

