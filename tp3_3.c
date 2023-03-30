#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char** argv) {
    int numberOfNames;
    printf("Ingresar la cantidad de nombres: ");
    scanf("%d",&numberOfNames);
    fflush(stdin);
    char** names = (char**)malloc(sizeof(char*)*numberOfNames);
    char* buffer = (char*)malloc(100);
    for(int i = 0; i < numberOfNames; i++) {
        printf("\nIngresar la frase %d: ",i+1);
        gets(buffer);
        names[i] = (char*)malloc(strlen(buffer)+1);
        strcpy(names[i],buffer);
    }
    for(int i = 0; i < 5; i ++) {
        printf("Frase %d: %s\n",i+1,names[i]);
    }
    free(names);
    free(buffer);
    return 0;
}