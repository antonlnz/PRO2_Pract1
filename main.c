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

void new (char *param1, char *param2, char *param3, char *param4, tList *L);
/*
 Objetivo: incorporar un nuevo producto al final de la lista con el identificador de usuario, categoria y precio
 Entradas:
    param1: variable para comprobar si ya existe un producto con ese identificador
    param2: vendedor asignado al producto
    param3: categoria del producto
    param4: precio del producto
    L: lista en la que se introduce el nuevo producto
 Salidas:
    List: Lista con el nuevo producto insertado, o el mensaje de error en caso de que no se pueda ejecutar la funcion
 Precondiciones: La lista está inicializada y position es una posicion valida de la lista
 Postcondicion: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado.
 */
void stats (tList L);
/*
 Objetivo: mostrar la lista completa de productos. Para cada categoria muestra el numero de productos, la suma de precios de todos los productos de dicha categoria, y el precio medio.
 Entradas:
    L: Lista a consultar
 Salidas:
    L: Se muestran los datos de la lista consultada
 Precondiciones: La lista está inicializada
 */
void delete (char *position, tList *L);
/*
 Objetivo: Localiza el producto en la lista y lo borra
 Entradas:
    position: Posicion del elemento a eliminar
    L: Lista de la cual vamos a eliminar el elemento correspondiente a la posicion position
 Salidas:
    L: Lista sin el elemento que se ha eliminado
 Precondiciones: La lista está inicializada y Position es una posicion valida de la lista
 Postcondicion: Las posiciones de los elementos de la lista pueden haber variado
 */
void bid (char *position, char *param2, char *preciopuja, tList *L);
/*
 Objetivo: buscar un producto y modificar su precio y el contador de pujas
 Entradas:
    position: Posicion del producto que se quiere modificar
    param2: vendedor asignado al producto
    preciopuja: precio del producto por el que se esta pujando
    L: lista de la cual modificamos el producto
 Salidas:
    L: Lista con los parametros precio y contador de pujas del elemento modificados
 Precondiciones: La lista está inicializada y Position es una posicion valida de la lista
 */

void new (char *param1, char *param2, char *param3, char *param4, tList *L) { //Cabecera de la función. Recibe el identificador del nuevo producto (param1), el vendedor del producto (param2), la categoría (param3) y el precio (param4)
    tItemL newItem;

    if (findItem(param1,*L)!=LNULL) { //Si existe un producto en la lista con ese identificador (param1), no podemos insertar otro
        printf("+ Error: New not possible\n"); //Imprimimos un error para indicar que no se completo la operacion
    } else {
        newItem.bidCounter = 0;
        strcpy(newItem.seller, param2); //Copiamos el valor de param2 en el campo "seller" del struct tItemL d
        strcpy(newItem.productId, param1); //Copiamos el valor de param1 en el campo "productId" del struct tItemL d
        if (strcmp(param3, "book")==0){ //el campo "productCategory" pasa a ser book. Si no, pasa a ser "painting" que es el otro tipo posible
            newItem.productCategory = book;
            printf("* New: product %s seller %s category book price %s\n", param1, param2, param4);
        } else {
            newItem.productCategory = painting; //Si param3 es de tipo book,
            printf("* New: product %s seller %s category painting price %s\n", param1, param2, param4);
        }
        newItem.productPrice = atof(param4); //Pasamos el param4 (char) a float y lo cambiamos en el tItemL d, en el campo del precio

        insertItem (newItem, LNULL, L);//Insertamos el tItemL d con los valores correspondientes en la lista
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
void delete (char *position, tList *L) { //Cabecera de la función. Recibe la posicion del item a borrar y la lista donde se encuentra
    tProductId deletePosicion; // creamos una variable local tipo tPosL
    sscanf(position, "%s", deletePosicion); // convertimos el string position a un tipo tPosL posicion
    tPosL p = findItem(deletePosicion, *L);

    if (findItem(position, *L)==LNULL) { //Si no encuentra el item:
        printf("+ Error: Delete not possible\n"); //Imprime un error conforme la operación no pudo completarse
    } else { //En el caso de que si lo encuentre:
        tItemL deleteItem = getItem(p, *L); //Lo localizamos para luego poder imprimir sus valores
        if (deleteItem.productCategory == book) { //Si la categoria del producto es "book":
            printf("* Delete: product %s seller %s category book price %.2f bids %d\n", deleteItem.productId, deleteItem.seller, deleteItem.productPrice, deleteItem.bidCounter); //Escribimos sus atributos teniendo en cuenta su categoria
        } else { //Si su categoria es "painting":
            printf("* Delete: product %s seller %s category painting price %.2f bids %d\n", deleteItem.productId, deleteItem.seller, deleteItem.productPrice, deleteItem.bidCounter); //Escribimos sus atributos teniendo en cuenta su categoria
        }
        deleteAtPosition(p, L); //Lo eliminamos (la funcion deleteAtPosition tambien se encarga de liberar la memoria)
    }
}
void bid (char *position, char *param2, char *preciopuja, tList *L) { //Cabecera de la funcion bid que recibe: posicion del elemento, pujador, precio de la puja, la lista a la que accede
    tPosL r = findItem(position, *L);
    float price = atof (preciopuja); //Ccreamos una variable tipo float para el precio convertimos param4 (char) en un float y lo asignamos a la variable precio

    printf("B: product %s bidder %s price %.2f\n", position, param2, price); //Imprimimos la cabecera de la funcion

    tItemL bidItem = getItem(r, *L); // Buscamos el item a modificar en la posicion dada (devuelve una copia del item)

    if ( (r == LNULL) || (strcmp(bidItem.seller, param2) == 0) || (bidItem.productPrice >= price))  { //Si el vendedor del producto es el
        //Mismo que el pujador, o el precio de la puja no es superior al precio actual, entonces:
        printf("+ Error: Bid not possible\n"); //Imprime el mensaje de error
    } else { //Si no:
        bidItem.productPrice = price; //Actualizamos el precio del producto
        bidItem.bidCounter = bidItem.bidCounter + 1; // actualizamos el contador de pujas
        updateItem(bidItem, r, L); // aplicamos los cambios a la lista
        if (bidItem.productCategory == book) { //Si la categoria es book
           printf("* Bid: product %s seller %s category book price %.2f bids %d\n", bidItem.productId, bidItem.seller, bidItem.productPrice, bidItem.bidCounter); // imprime el mensaje con categoria "book"
        } else { // realiza esta otra accion si la categoria es painting
            printf("* Bid: product %s seller %s category painting price %.2f bids %d\n", bidItem.productId, bidItem.seller, bidItem.productPrice, bidItem.bidCounter); // imprime el mensaje con categoria "painting"
        }
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
            //printf("B: product %s bidder %s price %s\n", param1, param2, param4); //Imprimimos la cabecera de la funcion
            bid(param1, param2, param4, L); //Llamamos a la funcion bid, enviandole los parametros que necesita
            break;
        case 'D':
            printf("D: product %s\n", param1); //Imprimimos la cabecera de la funcion
            delete (param1, L); //Llamamos a la funcion delete, enviandole los parametros que necesita
            break;
        default:
            printf("%c is not a valid command\n", command);
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