#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int moja_atoi(char *str) {
    int size = strlen(str);
    char *str2 = malloc(sizeof(char) * size);
    int num = 0;
    int n = 0;
    int sign = 0;
    for (int i = 0; i < size; i++) {
        int c = (int) str[i];
        if ((c > 47 && c < 58) || c == 45) {
            if (c == 45) {
                sign = 1;
                continue;
            }
            str2[n] = c - 48;
            n++;
        } else{
            if(n > 0){
                break;
            }
        }

    }
    int acc = 0;
    for (int i = n - 1; 0 <= i; i--) {
        int w = pow(10, n - i - 1);
        int d = str2[i];
        acc += d * w;
    }
    if(sign){
        acc *= -1;
    }
    return acc;
}

int main() {
    printf("%d", moja_atoi(" -115.4ola)"));
    return 0;
}


