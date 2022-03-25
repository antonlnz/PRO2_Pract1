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
#include <stdlib.h>

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

void new (char *param1, char *param2, char *param3, char *param4, tList *L) { //Cabecera de la función. Recibe el identificador del nuevo producto (param1), el vendedor del producto (param2), la categoría (param3) y el precio (param4)
    tItemL d;

    if (findItem(param1,*L)!=LNULL) { //Si existe un producto en la lista con ese identificador (param1), no podemos insertar otro
        printf("+ Error: New not possible\n"); //Imprimimos un error para indicar que no se completo la operacion
    } else {
        printf("* New: product %s seller %s category %s price %s\n", param1, param2, param3, param4);
        strcpy(d.seller, param2); //Copiamos el valor de param2 en el campo "seller" del struct tItemL d
        strcpy(d.productId, param1); //Copiamos el valor de param1 en el campo "productId" del struct tItemL d
        if (strcmp(param3, "book")==0) d.productCategory = book; else d.productCategory = painting; //Si param3 es de tipo book,
        //el campo "productCategory" pasa a ser book. Sino, pasa a ser "painting" que es el otro tipo posible
        sscanf(param4, "%f", &d.productPrice); //Pasamos el param4 (char) a float y lo cambiamos en el tItemL d, en el campo del precio

        insertItem (d, LNULL, L);//Insertamos el tItemL d con los valores correspondientes en la lista
    }
}

void stats (tList L) { //Cabecera de la función. Solo recibe la lista y no la va a modificar, solo a leerla
    tPosL i; //Creamos una variable tipo tPosL para recorrer la lista
    int countBook = 0, countPainting = 0; //countBook = contador numero de productos tipo book, countPainting = contador numero de productos tipo painting
    float avgBook, avgPainting, sumBook = 0, sumPainting = 0; //Creamos las variables necesarias para almacenar las operaciones que luego mostraremos
    //avgBook = precio medio de los productos tipo "book"; avgPainting = precio medio de los productos tipo "painting"; sumBook = suma de todos los precios de los productos tipo "book"; sumPainting = suma de todos los precios de los productos tipo "painting"
    if (isEmptyList(L)) { //Si la lista está vacia:
        printf("+ Error: Stats not possible\n"); //Imprimimos el mensaje de que la funcion no es realizable
    } else { //Si no esta vacia:
        for (i = first(L); i!=LNULL; i=next(i,L)) { //Recorremos la lista, desde el principio hasta el final
            tItemL item = getItem(i,L); //Cogemos el item i y lo asignamos a la variable "item"
            if (item.productCategory == book) { //Si la categoria del item es "book":
                printf("Product %s seller %s category book price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter); //Escribimos sus atributos teniendo en cuenta su tipo
                countBook = countBook + 1; //Aumentamos el numero de productos tipo "book" en una unidad
                sumBook = sumBook + item.productPrice; //Sumamos su precio al valor de la variable donde almacenaremos el precio total de todos los productos tipo "book"
            } else { //Si no es tipo "book" (como solo hay dos categorias, al no ser de tipo "book" nos esta diciendo implicitamente que es de tipo "painting"):
                printf("Product %s seller %s category painting price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter); //Escribimos sus atributos teniendo en cuenta su tipo
                countPainting = countPainting + 1; //Aumentamos el numero de productos tipo "painting" en una unidad
                sumPainting = sumPainting + item.productPrice; //Sumamos su precio al valor de la variable donde almacenaremos el precio total de todos los productos tipo "book"
            }
        }
        if (countBook == 0) { //Si el numero de productos tipo "book" es 0:
            avgBook = 0; //El precio medio es automaticamente = 0; para evitar errores al dividir entre 0
        } else avgBook = sumBook / countBook; //Si no es 0, el precio medio es igual a la suma de precios entre el numero de productos
        if (countPainting == 0) { //Si el numero de productos tipo "painting" es 0:
            avgPainting = 0; //El precio medio es automaticamente = 0; para evitar errores al dividir entre 0
        } else avgPainting = sumPainting / countPainting; //Si no es 0, el precio medio es igual a la suma de precios entre el numero de productos
        printf("\n"); //Hacemos un salto de linea para facilitar la legibilidad de la salida por pantalla
        printf ("Category  Products    Price  Average\n"); //Imprimimos las columnas de la tabla
        printf("Book      %8d %8.2f %8.2f\n", countBook, sumBook, avgBook); //Imprimimos, en orden: nº de productos que se ofertan de la categoria, la suma de precios de todos los productos de dicha categoría y precio medio
        printf("Painting  %8d %8.2f %8.2f\n", countPainting, sumPainting, avgPainting); //Lo mismo que en la de arriba pero para la categoria painting
    }
}
// findItem recibe un string y getItem y DeleteAtPosition una variable tipo tPosL
void delete (cahr *position, tList *L) { //Cabecera de la función. Recibe la posicion del item a borrar y la lista donde se encuentra
    if (findItem(position, *L)!=LNULL) { //Si no encuentra el item:
        printf("+ Error: Delete not possible"); //Imprime un error conforme la operación no pudo completarse
    } else { //En el caso de que si lo encuentre:
        tItemL item = getItem(position, *L); //Lo localizamos para luego poder imprimir sus valores
        deleteAtPosition(position, L); //Lo eliminamos (la funcion deleteAtPosition tambien se encarga de liberar la memoria)
        if (item.productCategory == book) { //Si la categoria del producto es "book":
            printf("* Delete: product %s seller %s category book price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter); //Escribimos sus atributos teniendo en cuenta su categoria
        } else { //Si su categoria es "painting":
            printf("* Delete: product %s seller %s category painting price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter); //Escribimos sus atributos teniendo en cuenta su categoria
        }
    }
}

void bid (char *position, char *param2, float preciopuja, tList *L) { //Cabecera de la funcion bid que recibe: posicion del elemento, pujador, precio de la puja, la lista a la que accede
    tItemL item = getItem(position, *L); // Buscamos el item a modificar en la posicion dada (devuelve una copia del item)
    if ((findItem(position, *L)==LNULL) || (strcmp(item.seller, param2) == 0) || (item.productPrice > preciopuja))  { //Si no existiese ningún producto con ese identificador, o el vendedor del producto es el
        //Mismo que el pujador, o el precio de la puja no es superior al precio actual, entoces:
        printf("+ Error: Bid not possible"); // imprime el mensaje de error
    } else { //Si no:
        item.productPrice = preciopuja; //Actualizamos el precio del producto
        item.bidCounter = item.bidCounter + 1; // ?????????????
        if (item.productCategory == book) { //Si la categoria es book
            printf("* Bid: product %s seller %s category book price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter); // imprime el mensaje con categoria "book"
        } else { // realiza esta otra accion si la categoria es painting
            printf("* Bid: product %s seller %s category painting price %.2f bids %d\n", item.productId, item.seller, item.productPrice, item.bidCounter); // imprime el mensaje con categoria "painting"
        }
        updateItem(item, position,L); // aplicamos los cambios a la lista
    }
}

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {
    printf("********************\n");
    printf("%s ", commandNumber);
    switch (command) {
        case 'N':
            printf("N: product %s seller %s category %s price %s\n", param1, param2, param3, param4); //Imprimimos la cabecera de la funcion
            new(param1, param2, param3, param4, L); //Llamamos a la funcion new, enviandole los parametros que necesita
            break;
        case 'S':
            printf("S\n"); //Imprimimos la cabecera de la funcion
            stats(*L); //Llamamos a la funcion stats, enviandole los parametros que necesita
            break;
        case 'B':
            printf("B: product %s bidder %s price %s\n", param1, param2, param4); //Imprimimos la cabecera de la funcion
            float preciopuja; // creamos una variable tipo float para el precio
            preciopuja = atof (param4); // convertimos param4 (char) en un float y lo asignamos a la variable precio
            bid (param1, param2, preciopuja, L); //Llamamos a la funcion bid, enviandole los parametros que necesita
            break;
        case 'D':
            printf("D: product %s\n", param1); //Imprimimos la cabecera de la funcion
            delete (param1, L); //Llamamos a la funcion delete, enviandole los parametros que necesita
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

    tList lista01; //Creamos la variable lista01 de tipo tList
    createEmptyList(&lista01); //Creamos e inicializamos una lista vacia y la almacenamos en la variable lista01

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
