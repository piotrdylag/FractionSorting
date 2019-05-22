#include <stdio.h>    // Instrukcja Preprocesora
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define N 5
#define Max 50
#include <ctype.h>
#include <string.h>
#define pi 3.14


char exampleFunction(const char *s){
    return *s;
}

void linia(int);

void putRandom(float (*)[N], int);

void printArr(float (*)[N], int);

float **allocation(int w, int k);


struct fraction {
    int counter;
    unsigned denominator;
    float value;
};

struct stack {
    int value;
    struct stack *next;
};

struct stack *pointer;
struct stack *old;

struct kolejka{
    int przod, tyl, size;
    unsigned capacity;
    int* array;
};

struct node{            // węzeł
    char *w;
    int count;
    struct node *left, *right;
};
//Zadanie 7a - plik zadania_t4.pdf
struct EList{
    int klucz;
    struct EList *nast;
};


struct EList* dodaj_elem(struct EList*q, int x);
void drukuj_liste(struct EList* q);
struct EList* usun_elem(struct EList*q, int x);
void drukuj_rek(struct EList *q);
void drukuj_ostatni(struct EList *q);

//--------------------------------------------------

int minFractions(struct fraction f1, struct fraction f2) {
    return f1.counter * f2.denominator < f2.counter * f1.denominator;
}

int printFractions(struct fraction f) {
    printf("%d/%u, %f \n", f.counter, f.denominator, f.value);
    return 0;
}


void sortFract(struct fraction *t, int n) {
    for (int i = 0; i < n; i++) {
        int y = i;
        struct fraction min = t[y];
        for (int j = i + 1; j < n; j++) {
            minFractions(t[j], min);
            if (minFractions(t[j], min) == 1) {
                t[y] = t[i];
                t[i] = min;
                min = t[j];
            }
        }
    }

}

void swap(struct fraction *a, struct fraction *b) {
    struct fraction tmp = *a;
    *a = *b;
    *b = tmp;
}

int compareByValue(struct fraction *left, struct fraction *right) {
    return left->value < right->value;
}

int compareByMultiply(struct fraction *left, struct fraction *right) {
    return left->counter * right->denominator < right->counter * left->denominator;
}

void bubbleSortfract(struct fraction *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareByMultiply(&a[j], &a[j + 1])) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }

}


void printArray(int *array[], int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
    printf("}");
}

void printTwoDimArr(int n, int m, int arr[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
            if (j == n - 1) {
                printf("\n");
            }
        }
    }
}

void printNumbers(int n) {
    printf("{");
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", i);
        } else {
            printf("%d, ", i);
        }
    }
    printf("}");
}


int *fibonacci(int n) {
    int *fib = (int *) malloc(n * sizeof(int));  // Dynamiczna alokacja zmiennej
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;
}

void swapNum(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int diagonalna(int **a, int w) {  // w - liczba wierszy
    int i, j;
    for (i = 0; i < w; i++)
        for (j = 0; j < w; j++)
            if (j != i && a[i][j] != 0)
                return 0;
    return 1;
}


void bubbleSort(int arr[], int n) {             // Sortowanie bąbelkowe
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[j + 1]) {
                swapNum(&arr[j], &arr[j + 1]);
            }
        }
    }
    printArray(arr, n);
}

void insertSort(int arr[], int size) {           // sortowanie przez wstawianie!
    int i, j;
    for (i = 1; i < size; i++) {
        int tmp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = tmp;
    }
    printArray(arr, size);
}

void insertSortofChars(char arr[], int size) {           // sortowanie przez wstawianie!
    int i, j;
    for (i = 1; i < size; i++) {
        int tmp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = tmp;
    }

}

void selectionSort(int *t, int n) {                  //Sortowanie przez wybieranie
    for (int i = 0; i < n; i++) {
        int y = i;
        int min = t[y];
        for (int j = i + 1; j < n; j++) {
            if (t[j] < min) {
                min = t[j];
                y = j;
            }
            t[y] = t[i];
            t[i] = min;
        }
    }
    printArray(t, n);
}

void quickSort(int arr[], int left, int right) {             //Szybkie sortowanie
    int l = left, r = right;
    int pivot = arr[(l = r) / 2];
    while (left <= right) {
        while (arr[l] < pivot)
            l++;
        while (arr[r] > pivot)
            r++;
        if (l < r) {
            swapNum(&arr[l], &arr[r]);
            l++;
            r++;
        }
    }
    if (left < r) quickSort(arr, left, r);
    if (l < right) quickSort(arr, l, right);
}

int *evenNum(int n) {
    int *arrEven = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i += 2) {
        printNumbers(i);
    }
    return arrEven;
}


void switchMax(float arr[], int size, int j) {
    int i, max = 0;

    for (i = 1; i < size; i++) {
        if (arr[max] < arr[i]) {
            max = i;
        }
    }
    int temp = arr[j];
    arr[j] = arr[j + 1];
    arr[j + 1] = temp;
}

int howManyDifnum(float *arr, int n){
    int sum = n;                            //zmniejszać o 1 gdy będzie jakaś liczba taka sama od drugiej
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            if(arr[i] == arr[j] && i != j){
                sum--;
                break;
            }
        }
    return sum;
}

int strlen1(const char *s){
    int n;
    for(n=0; *s != '\0'; ++s)++n;
    return n;
}

void strcpy1(char *t, const char *s) {
    while ((*t = *s) != '\0') {
        s++;
        t++;
    }
}
void reversPrint(char *arr, int size){
    for(int i = size - 1; i >= 0; i--){
        printf("%c ", arr[i]);
    }
}

void printChars(char *array, int size){
    for(int i = 0; i < size; i++){
        printf("%c ", array[i]);
    }
}

struct kolejka* createQueue(unsigned capacity){
    struct kolejka* kolejka = (struct kolejka*) malloc(sizeof(struct kolejka));
    kolejka->capacity = capacity;
    kolejka->przod = kolejka->size = 0;
    kolejka->tyl = capacity - 1;
    kolejka->array = (int*) malloc(kolejka->capacity * sizeof(int));
    return kolejka;
}

int czyPelna(struct kolejka* kolejka){
    return (kolejka->size == kolejka->capacity);
}

int czyPusta(struct kolejka* kolejka){
    return (kolejka->size == 0);
}

void kolejkuj(struct kolejka* kolejka, int item){
    if (czyPelna(kolejka))
        return;
    kolejka->tyl = (kolejka->tyl + 1)%kolejka->capacity;
    kolejka->array[kolejka->tyl] = item;
    kolejka->size = kolejka->size + 1;
    printf("%d dodane do kolejki\n", item);
}

int usunEle(struct kolejka* kolejka){
    if (czyPusta(kolejka))
        return 0;
    int item = kolejka->array[kolejka->przod];
    kolejka->przod = (kolejka->przod + 1)%kolejka->capacity;
    kolejka->size = kolejka->size - 1;
    return item;
}

int przod(struct kolejka* kolejka){
    if (czyPusta(kolejka))
        return 0;
    return kolejka->array[kolejka->przod];
}

int tyl(struct kolejka* kolejka){
    if (czyPusta(kolejka))
        return 0;
    return kolejka->array[kolejka->tyl];
}

int read(FILE *fp, char *s){
    return fscanf(fp, "%s", s);
}

//TODO implemet this function body
//zadanie 1 (zadania_t2_2019.pdf)
int licz(double *p1, double *p2, double x) {
    int n = 0;
    while (p1 < p2) {
        if (*p1 == x) {
            n++;
        }
        p1++;
    }
    return n;
}

void replace (float arr[3][3], int size){
    float m = arr[0][0];
    for(int r = 0; r < size; r++){
        for(int c = 0; c < size; c++) {
            if (arr[r][c] > m) {
                m = arr[r][c];
            }
        }
    }
    int w = size;
    while(w--){
        arr[w][w] = m;
    }
}
void swapRows(int **arr, int x, int y){
    int *tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}


void maxTwoDim(int arr[][3], int size){
    int i, j;
    for(i = 0; i < size; i++){
        for( j = 0; j < size; j++){
            int max = arr[i][j];
            if(arr[i][j] > max){
                int tmp = arr[i][j];
                arr[i][j] = max;
                max = tmp;
            }
        }
    }
}

int toBinar(int x){
    printf("%d\n", x);
    if(x > 0){
        if(x%2) {
            printf("1");
        }else printf("0");
        return toBinar(x/2);
    }
}

int printArrayback(int *arr, int n){       // Z zadania_t4_s.pdf 6 zadanie (rekurencyjnie wypisanie tablicy od tyłu)

}

struct node * new_node (char * word) {
    struct node * tmp;
    tmp = (struct node *) malloc(sizeof(struct node));
    tmp->w = (char *) malloc(strlen(word) + 1);
    strcpy(tmp->w, word);
    tmp->count = 1;
    tmp->left = tmp->right = NULL;
    return tmp;
}

struct Elist* addNext(struct EList *q, int x){
    if(q == NULL) {
        q = (struct EList*) malloc(sizeof(struct EList));
        q -> klucz = x;
        q -> nast = NULL;
    }else{
        q -> nast = addNext(q -> nast, x);
    }
    return q;
}

void write(struct node *p){
    if(p == NULL) return;
    write(p->left);
    printf("%s %d\n", p->w, p->count);
    write(p->right);
    while(p->right){
        printf("%s %d\n", p->right->w, p->right->count);
    }

}

int main() {


    /* linia(1);
(1) Sprawdziæ dzialanie programu

    FILE *plik;

    if ((plik=fopen("DANE.TXT","w"))==NULL) {
        puts("Blad otwarcia pliku!");
        exit(EXIT_FAILURE);
    }

    int i;
    srand((unsigned int)time(0));
    for (i=0;i<20;i++)
        fprintf(plik,"%d ", rand()%100);

    fclose(plik);

    printf("Wylosowane liczby zapisano w pliku DANE.TXT\n");

    linia(2);
(2) Napisac instrukcje programu, ktore spowoduja odczytanie
  liczb z pliku DANE.TXT i wyswietlenie ich na ekranie


    int  i,x;
    struct EList* glowa=NULL;


    for(i=0;i<5; i++)
        glowa=dodaj_elem(glowa,i);

    printf("\n");
    drukuj_liste(glowa);


    if(glowa!=NULL){
        printf("\nPodaj element do usuniecia: ");
        scanf("%d", &x);
        glowa=usun_elem(glowa,x);
    }
    else
        printf("Lista pusta");

    printf("\n");
    drukuj_rek(glowa);

    printf("\n");
    drukuj_ostatni(glowa);

    printf("%d", toBinar(11));
    int a[3][3] = {{3, 56, 21}, {51, 87, 1}, {30, 99, 5}};
    printf("__________Array before__________\n");
    printTwoDimArr(3, 3, a);
    maxTwoDim(a, 3);
    printf("__________Array after__________\n");
    printTwoDimArr(3, 3, a);



    int size = 4;
    int **p = (int **)malloc(sizeof(int *) * size);
    for(int i = 0; i < size; i++){
        p[i] = (int *)malloc(sizeof(int) * size);
        for(int j = 0; j < size; j++){
            p[i][j] = i + 1;
        }
    }
    swapRows(p, 1, 2);
    printArray(p[0], size);
    printArray(p[1], size);
    printArray(p[2], size);
    printArray(p[3], size);

     struct kolejka* kolejka = createQueue(1000);

    kolejkuj(kolejka, 10);
    kolejkuj(kolejka, 20);
    kolejkuj(kolejka, 30);
    kolejkuj(kolejka, 40);

    printf("%d Usuniete z kolejki\n\n", usunEle(kolejka));

    printf("przod wynosi %d\n", przod(kolejka));
    printf("tyl wynosi %d\n", tyl(kolejka));


     char arr[5] = {'a', 'b', 'c', 'd', 'e'};
    printf("__________Chars in normal position__________\n");
    printChars(arr, 5);
    printf("\n");
    printf("__________Chars in revers position__________\n");
    reversPrint(arr, 5);

    //char tekst[Max]="Sztuka dobrego wyboru";
    //linia(1);
1) Sprawdzic dzialanie programu

    puts(tekst);
    printf("%c\n", exampleFunction(tekst));*/

//    linia(2);
//(2) Pobra� z wej�cia dowolny ci�g znakowy i sprawdzic jego d�ugo��
//wykorzystuj�c funkcje strlen1 i strlen2

    //gets(tekst);
    //puts(tekst);
    //printf("Ciąg sklada sie z %d znakow", strlen1(tekst));




    //inia(3);
//(3) Przydzieli� dynamicznie pami�� dla tablicy o d�ugo�ci odpowiadaj�cej
//pobranemu ci�gowi znak�w i skopiowa� do niej ten ci�g
//wykorzystuj�c funkcje  strcpy1 i strcpy2







    /*float (*m)[N];
    m = (float(*)[N]) malloc(N*N* sizeof(float));

    linia(1);
    (1) Dokona� dynamicznego przydzia�u pami�ci dla wska�nika m,tak aby m�g�
    sta� si� parametrem aktualnym definiowanych poni�ej funkcji, zastosowa� funkcje -
    wczyta� i wypisa� macierz*/

    //putRandom(*m, N);
    //printArr(*m, N);

    //linia(2);
//(2) Wywo�a� funkcj� z zadania nr 3 dla tablicy m.

    /*switchMax(m[i], N, i);
    printArr(m, N);*/

    // linia(3);

    /*for(int i = 0; i < N; i++){
        switchMax(m[i], N, i);
    }
    printArr(m, N);*/

    // linia(4);





    //Zwolni� pami�� dla wska�nika m
    //linia(0);

    /*for(i = 0; i < N; i++){
        free(m[i]);
        free(m);
    }*/



    /*int m[N][N] = {{1, 0, 7, 0},
                    {0, 5, 0, 4},
                    {0, 0, 9, 0},
                    {0, 0, 0, 3}};

   printf("\nCzy diagonalna?\n");
   if (diagonal(&m[N][N], 4))
       printf("\n-TAK");
   else printf("\n-NIE");


   int array[5][5] = {{2,  3,  1,  7,  5},
                      {5,  87, 17, 33, 11},
                      {44, 65, 25, 12, 78},
                      {3,  22, 7,  13, 7},
                      {43, 54, 33, 1,  0}};

   printTwoDimArr(5, 5, array);
    const int n = 5;
    struct fraction array[5] = {{5, 4},
                                {3, 4},
                                {5, 8},
                                {1, 2},
                                {3, 8},
                                {8, 9}};
    for (int i = 0; i < n; i++) {
        array[i].value = (float) array[i].counter / array[i].denominator;
        printf("%d/%d %f \n", array[i].counter, array[i].denominator, array[i].value);
    }
    printf("\n Sortowanie \n");
    bubbleSort(array, n);
    for (int i = 0; i < n; i++) {
        printFractions(array[i]);
    } */
    return 0;
}

//zadania_t4.pdf
//------------------------------------------------------
struct EList* dodaj_elem(struct EList*q, int x){
    struct EList*pom;
    pom=(struct EList*)malloc(sizeof(struct EList));
    pom->klucz=x;
    pom->nast=q;
    q=pom;
    return q;
}

//------------------------------------------------------
void drukuj_liste(struct EList* q){
    struct EList*pom;
    int i=0;
    pom=q;
    if(pom==NULL)
        printf("\nLista pusta");
    else{
        printf("\nElementy listy:");
        while(pom!=NULL){
            printf("\nElement nr %d: %d",++i,pom->klucz);
            pom=pom->nast;
        }
    }
}

//------------------------------------------------------
struct EList* usun_elem(struct EList*q, int x){
    struct EList*pom, *tmp;
    pom=q;
    while (pom !=NULL && pom->klucz!= x){
        tmp=pom;
        pom=pom->nast;
    }
    if(pom!=NULL){
        if (pom == q)
            q=pom->nast;
        else
            tmp->nast=pom->nast;

        free(pom);
    }
    else
        printf("Elementu %d nie ma w liscie", x);
    return q;
}

//------------------------------------------------------
void drukuj_rek(struct EList *q){
    if(q!=NULL){
        drukuj_rek(q->nast);
        printf("\n%d",q->klucz);
    }
}

//------------------------------------------------------
void drukuj_ostatni(struct EList *q){
    if(q->nast==NULL)
        printf("\n%d",q->klucz);
    else
        drukuj_ostatni(q->nast);
}
//------------------------------------------------------

float **allocation(int w, int k){
    int i;
    float **p=(float **)malloc(w*sizeof(float *));
    for(i=0; i< w; i++)
        p[i]=(float *)malloc(k*sizeof(float));

    return p;
}

void putRandom(float (*a)[N], int w) {
    int i, j;
    srand((unsigned) time(NULL));
    for (i = 0; i < w; i++) {
        for (j = 0; j < N; j++) a[i][j] = rand() % 50 * 0.5;
    }

}

void printArr(float(*a)[N], int w) {
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < N; j++) printf("%.2f ", a[i][j]);
        printf("\n");
    }

}


void linia(int k) {
    if (k > 0) printf("\n\n______________ %d ________________\n\n", k);
    else printf("\n\n___________________________________\n\n");
}