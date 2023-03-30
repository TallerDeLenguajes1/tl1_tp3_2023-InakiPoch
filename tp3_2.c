#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void averageRevenue(int production[5][12]) {
    for(int i = 0 ; i < 5 ; i++) {
        int average = 0;
        for(int j = 0 ; j < 12 ; j++) {
            average += production[i][j];
        }
        printf("Promedio del anio %d: %d\n",i+1,average/12);
    }
}

void maxAndMin(int production[5][12]) {
    int maxValue = production[0][0];
    int minValue = production[0][0];
    int maxYear = 0, maxMonth = 0;
    int minYear = 0, minMonth = 0;
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 12 ; j++) {
            if(production[i][j] > maxValue) {
                maxValue = production[i][j];
                maxYear = i + 1;
                maxMonth = j + 1;
            }
            else {
                if(production[i][j] < minValue) {
                    minValue = production[i][j];
                    minYear = i + 1;
                    minMonth = j + 1;
                }
            }
        }
    }
    printf("Maximo valor: %d\nAnio: %d\nMes: %d\n",maxValue,maxYear,maxMonth);
    printf("\nMinimo valor: %d\nAnio: %d\nMes: %d\n",minValue,minYear,minMonth);
}

int main(int arc,char** argv) {
    int production[5][12];
    srand(time(NULL));
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 12 ; j++) {
            production[i][j] = rand()%40001 + 10000;
        }
    }
    printf("Valores cargados\n");
    for(int i = 0 ; i < 5 ; i++) {
        for(int j = 0 ; j < 12 ; j++) {
            printf("%d  ",production[i][j]);
        }
        printf("\r\n");
    }
    averageRevenue(production);
    maxAndMin(production);
    return 0;
}