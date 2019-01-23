#include <stdio.h>

struct fractions{
    int counter;
    unsigned denominator;
};

void printArray (int *, int);

int minFractions (struct fractions f1, struct fractions f2) {
     return f1.counter * f2.denominator < f2.counter * f1.denominator;
}

int printFractions(struct fractions f) {
    printf("%d/%u \n", f.counter, f.denominator);
}

     void selectionSort(int *t, int n){                  //Sortowanie prze wybieranie
    for(int i =0; i < n; i++){
        int y = i;
        int min = t[y];
        for(int j = i + 1; j < n; j++){
            if(t[j] < min){
                min = t[j];
                y = j;
            }
            t[y] = t[i];
            t[i] = min;
        }
    }
    printArray(t, n);
}

void sortFract (struct fractions *t, int n){

    for(int i =0; i < n; i++){
        int y = i;
        struct fractions min = t[y];
        for(int j = i + 1; j < n; j++){
            minFractions(t[j], min);
            if(minFractions (t[j], min) == 1) {
                t[y] = t[i];
                t[i] = min;
                min = t[j];
            }
        }
    }

}


void printArray(int array[], int n){
    printf("{");
    for(int i =0; i < n; i++){
        if(i == n - 1){
            printf("%d", array[i]);
        } else {
            printf("%d, ", array[i]);
        }
    }
    printf("}");
}


int main() {

    struct fractions array[4] = {{3, 4}, {5, 8}, {1, 2}, {3, 8}};
    sortFract(array, 4);
    for(int i = 0; i < 4; i++){
        printFractions(array[i]);
    }


    return 0;
}

