#include <stdio.h>    // Instrukcja Preprocesora
#include <stdlib.h>

struct fraction {
    int counter;
    unsigned denominator;
    float value;
};


void printArray(int *, int);

int minFractions(struct fraction f1, struct fraction f2) {
    return f1.counter * f2.denominator < f2.counter * f1.denominator;
}

int printFractions(struct fraction f) {
    printf("%d/%u, %f \n", f.counter, f.denominator, f.value);
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

void bubbleSort(struct fraction *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareByMultiply(&a[j], &a[j + 1])) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }

}


void printArray(int array[], int n) {
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

void printTwoDimArr(int *arr[][], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", *arr[i][j]);
            if (i == n) {
                printf("\n");
            }
        }
    }
}
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


void bubbleSortNum(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j] > arr[j + 1]) {
                swapNum(&arr[j], &arr[j + 1]);
            }
        }
    }
    printArray(arr, n);
}

int main() {
    int array[5][5] = {{2,  3,  1,  7,  5},
                       {5,  87, 17, 33, 11},
                       {44, 65, 25, 12, 78},
                       {3,  22, 7,  13, 7},
                       {43, 54, 33, 1,  0}};

    printTwoDimArr(array, 5, 5);
    /* const int n = 5;
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

}

