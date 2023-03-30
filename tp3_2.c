#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int arc,char** argv) {
    unsigned int production[5][12];
    srand(time(NULL));
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 12 ; j++) {
            production[i][j] = rand()%40001 + 10000;
        }
    }
    printf("Valores cargados\n");
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 12 ; j++) {
            printf("%u  ",production[i][j]);
        }
        printf("\r\n");
    }
    return 0;
}