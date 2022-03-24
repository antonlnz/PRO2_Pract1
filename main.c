/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ruben Seoane Iglesias LOGIN 1: r.seoane.iglesias
 * AUTHOR 2: Anton Lopez Nunez LOGIN 2: anton.lopez.nunez
 * GROUP: *2.4*
 * DATE: 11 / 03 / 2022
 */

#include <stdio.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

void new (tList *L, char *param1, char *param2, char *param3, char *param4) {
    tItemL d;

    if (findItem(param1,*L)!=LNULL) { //Si existe un producto en la lista con ese identificador (param1), no podemos insertar otro
        printf("+ Error: New not possible\n"); //Imprimimos un error para indicar que no se completo la operacion
    } else {
        printf("* New: product %s seller %s category %s price %s\n", param1, param2, param3, param4);
        strcpy(d.seller, param2); //Copiamos el valor de param2 en el campo "seller" del struct tItemL d
        strcpy(d.productId, param1); //Copiamos el valor de param1 en el campo "productId" del struct tItemL d
        if (strcmp(param3, "book")==0) d.productCategory = book; else d.productCategory = painting; //Si param3 es de tipo book,
        //el campo "productCategory" pasa a ser book. Sino, pasa a ser "painting" que es el otro tipo posible
        sscanf(param4, "%f", &d.productPrice);

        insertItem (d, LNULL, L);//Insertamos el tItemL d con los valores correspondientes en la lista
    }
}

void stats (tList L) {
    tPosL i;
    int countBook = 0, countPainting = 0; //countBook = contador numero de productos tipo book, countPainting = contador numero de productos tipo painting
    float avgBook, avgPainting, sumBook = 0, sumPainting = 0;
    if (isEmptyList(L)) { //Si la LISTA DE USUARIOS está vacia
        printf("+ Error: Stats not possible\n"); //Imprimimos el mensaje de que la funcion no es realizable
    } else {
        for (i = first(L); i!=LNULL; i=next(i,L)) {
            tItemL item = getItem(i,L);
            if (item.productCategory == book) {
                printf("Product %s seller %s category book price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter);
                countBook = countBook + 1;
                sumBook = sumBook + item.productPrice;
            } else {
                printf("Product %s seller %s category painting price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter);
                countPainting = countPainting + 1;
                sumPainting = sumPainting + item.productPrice;
            }
        }
        if (countBook == 0) {
            avgBook = 0;
        } else avgBook = sumBook / countBook;
        if (countPainting == 0) {
            avgPainting = 0;
        } else avgPainting = sumPainting / countPainting;
        printf("\n");
        printf ("Category  Products    Price  Average\n");
        printf("Book      %8d %8.2f %8.2f\n", countBook, sumBook, avgBook); //En orden: nº de productos que se ofertan de la categoria, la suma de precios de todos los productos de dicha categoría y precio medio
        printf("Painting  %8d %8.2f %8.2f\n", countPainting, sumPainting, avgPainting); //Lo mismo que en la de arriba pero para otra categoria
    }
}

void delete (char *param1, tList *L) {
    if (findItem(param1, *L)!=LNULL) {
        printf("+ Error: Delete not possible");
    } else {
        tItemL item = getItem(*param1, *L);
        deleteAtPosition(*param1,L);
        if (item.productCategory == book) {
            printf("Product %s seller %s category book price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter);
        } else {
            printf("Product %s seller %s category painting price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter);
        }
    }
}

void bid (char *param1, *param2, *param3, *param4, tList *L) {
    tItemL item = getItem(*param1, *L);
    tProductPrice puja;
    sscanf(*param3, "%f", puja);
    if ((findItem(param1, *L)==LNULL) || (item.seller == param2) || (strcmp (item.productPrice, param3)>0))  { //REVISAR FUNCION FINDITEM DE LA DINAMICA
        printf("+ Error: Bid not possible");
    } else {
        item.productPrice = param4;
        item.bidCounter = item.bidCounter + 1;
        if (item.productCategory == book) {
            printf("* Bid: product %s seller %s category book price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter);
        } else {
            printf("* Bid: product %s seller %s category painting price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter);
        }
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {
    printf("********************\n");
    printf("%s ", commandNumber);
    switch (command) {
        case 'N':
            printf("N: product %s seller %s category %s price %s\n", param1, param2, param3, param4);
            new(L, param1, param2, param3, param4);
            break;
        case 'S':
            printf("S\n");
            stats(*L);
            break;
        case 'B':
            printf("B: product %s bidder %s price %s\n", param1, param2, param4);
            bid (param1, param2, param3, param4, L);
            break;
        case 'D':
            printf("D: product %s\n", param1);
            delete (param1, L);
            break;
        default:

            break;
    }
}

void readTasks(char *filename, tList *L) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4, L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    tList lista01;
    createEmptyList(&lista01);

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name, &lista01);

    return 0;
}