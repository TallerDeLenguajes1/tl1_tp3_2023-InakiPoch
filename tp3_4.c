#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

char* types[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
    int productID;
    int quantity;
    char* productType;
    float unitPrice;
};

struct Cliente {
    int clientId;
    char clientName[MAX];
    int numberOfProducts;
    struct Producto* products;
};

typedef struct Producto Product;
typedef struct Cliente Client;

void generateProducts(Product* product,int number) {
    for(int i = 0 ; i < number ; i++) {
        product->productID = i + 1;
        product->quantity = (int)rand()%10 + 1; //Se interpreta como el stock del producto
        product->productType = types[(int)rand()%5];
        product->unitPrice = (int)rand()%91 + 10;
        product++;
    }
}

float totalPrice(Product* product,int number) {
    float totalPrice = 0;
    for(int i = 0 ; i < number ; i++) {
        totalPrice += product->unitPrice;
        product++;
    }
    return totalPrice;
}

void chargeClient(Client* client,int number) {
    for(int i = 0 ; i < number ; i++) {
        printf("\n-----CLIENTE %d-----\n",i+1);
        client->clientId = i + 1;
        printf("\nNombre: ");
        gets(client->clientName);
        client->numberOfProducts = rand()%5 + 1;
        client->products = (Product*)malloc(sizeof(Product)*client->numberOfProducts);
        generateProducts(client->products,client->numberOfProducts);
        client++;
        fflush(stdin);
    }
}

void printProductData(Product* product,int number) {
    for(int i = 0 ; i < number ; i++) {
        printf("\n-----PRODUCTO %d-----\n",i+1);
        printf("\nID: %d",product->productID);
        printf("\nCantidad en stock: %d",product->quantity);
        printf("\nTipo: %s",product->productType);
        printf("\nPrecio unitario: %.1f",product->unitPrice);
        product++;
    }     
}

void printClientData(Client* client,int number) {
    for(int i = 0 ; i < number ; i++) {
        printf("\n-----CLIENTE %d-----\n",i+1);
        printf("\nID: %d",client->clientId);
        printf("\nNombre: %s",client->clientName);
        printf("\nCantidad de productos: %d",client->numberOfProducts);
        printProductData(client->products,client->numberOfProducts);
        printf("\n\nTotal a pagar: %.1f\n",totalPrice(client->products,client->numberOfProducts));
        client++;
    }                              
}

int main(int argc,char** argv) {
    Client* clients;
    int numberOfClients;
    srand(time(NULL));
    printf("Ingresar la cantidad de clientes: ");
    scanf("%d",&numberOfClients);
    while(numberOfClients > 5) {
        printf("No puede visitar mas de 5 clientes. Ingresar un menor numero de clientes: ");
        scanf("%d",&numberOfClients);
    }
    fflush(stdin);
    clients = (Client*)malloc(sizeof(Client)*numberOfClients);
    chargeClient(clients,numberOfClients);
    printf("\n-----DATOS CARGADOS-----\n");
    printClientData(clients,numberOfClients);
    for(int i = 0 ; i < numberOfClients ; i++) {
        free(clients->products);
    }
    free(clients);
    return 0;
}