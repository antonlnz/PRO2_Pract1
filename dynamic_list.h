/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ruben Seoane Iglesias LOGIN 1: r.seoane.iglesias
 * AUTHOR 2: Anton Lopez Nunez LOGIN 2: anton.lopez.nunez
 * GROUP: *2.4*
 * DATE: 04 / 03 / 2022
 */


#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H
#include <stdlib.h>
#include <stdbool.h>
#define LNULL NULL

#include "types.h"

typedef struct tNode* tPosL;

struct tNode{
    tItemL data;
    tPosL next;
};

typedef tPosL tList; //Se añade para mantener la transparencia de la implementación (Para que funcione con cualquier implementación)

//Cabeceras de Funciones
void createEmptyList (tList *L);
/*
 Objetivo: Crea una lista vacia y la inicializa
 Salidas: Una lista vacia
 Postcondiciones: Lista queda inicializada y no contiene elementos
 */

bool isEmptyList (tList L);
/*
 Objetivo: Determina si la lista está vacia
 Entradas:
    List: Lista a comprobar
 Salidas:
    Verdadero si la lista esta vacia y falso en caso contrario
 Precondiciones: La lista debe estar inicializada
 */

tPosL first(tList L);
/*
 Objetivo: Devuelve la posición del primer elemento de la lista
 Entradas:
    List: Lista a manipular
 Salidas:
    Position: Posición del primer elemento
 Precondiciones: La lista está inicializada y no esta vacia
 */

tPosL last(tList L);
/*
 Objetivo: Devuelve la posición del ultimo elemento de la lista
 Entradas:
    List: Lista a manipular
 Salidas:
    Position: Posición del ultimo elemento
 Precondiciones: La lista está inicializada y no esta vacia
 */

tPosL next(tPosL p, tList L);
/*
 Objetivo: Devuelve la posición en la lista del elemento siguiente al de la posicion indicada (O LNULL si la posicion n
 tiene siguiente)
 Entradas:
    Position: Posicion del elemento actual
    List: Lista a manipular
 Salidas:
    Position: Posición del elemento siguiente o nulo si es el ultimo
 Precondiciones: La lista está inicializada y postion es una posicion valida de la lista
 */

tPosL previous(tPosL p, tList L);
/*
 Objetivo: Devuelve la posicion en la lista del elemento anterior al de la posicion indicada (o LNULL si no tiene anterior)
 Entradas:
    Position: Posicion del elemento actual
    List: Lista a manipular
 Salidas:
    Position: Posición del elemento anterior o nulo si es el primero
 Precondiciones: La lista está inicializada y position es una posicion valida de la lista
 */

bool insertItem (tItemL d, tPosL p , tList *L);
/*
 Objetivo: Inserta un elemento en la lista antes de la posicion indicada.
    Si la posicion es nula, añade un elemento al final de la lista.
    En caso contrario, el elemento quedará insertado justo antes del que actualmente ocupa la posicion indicada.
 Entradas:
    Item: Contenido del elemento a insetar
    Position: Posicion de referencia para la insercion.
    List: Lista donde vamos a insertar
 Salidas:
    List: Lista con el elemento Item insertado y verdadero si se ha podido insertar, falso en caso contrario.
 Precondiciones: La lista está inicializada y Position es una posicion valida de la lista o es una posicion nula
 Postcondicion: Las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado.
 */

void deleteAtPosition (tPosL p, tList *L);
/*
 Objetivo: Elimina de la lista un elemento con cierta posicion
 Entradas:
    Position: Posicion del elemento a eliminar
    List: Lista a modificar
 Salidas:
    List: Lista sin el elemento correspondiente a Position
 Precondiciones: La lista está inicializada y position es una posicion valida de la lista
 Postcondiciones: Las posiciones de los elementos de la lista posteriores a la de la posicion eliminada pueden haber
 variado.
 */

tItemL getItem (tPosL p, tList L);
/*
 Objetivo: Recupera el contenido de un elemento de la lista
 Entradas:
    Position: Posicion del elemento buscado
    List: Lista donde realizar la busqueda
 Salidas:
    Item: Contenido del elemento que esta en Position
 Precondiciones: La lista está inicializada y position es una posicion valida de la lista
 */

void updateItem (tItemL d, tPosL p, tList *L);
/*
 Objetivo: Modifica el contenido de un elemento de la lista.
 Entradas:
    Item: Nuevo contenido a asignar al elemento en position
    Position: Posicion del elemento que queremos modificar
    List: Lista a modificar
 Salidas:
    List: Lista con el contenido del elemento modificado
 Precondiciones: La lista está inicializada y position es una posicion valida de la lista
 */

tPosL findItem (tProductId d, tList L);
/*
 Objetivo: Busca el primer elemento con cierto contenido en la lista
 Entradas:
    Item: Contenido del elemento buscado
    List: Lista donde realizar la búsqueda
 Salidas:
    Position: Posición del elemento encontrado o nulo si no se encuentra
 Precondiciones: La lista está inicializada
 */

bool createNode (tPosL *p);
/*
 Objetivo: Devuelve la posicion en la lista del elemento anterior al de la posicion indicada (o LNULL si no tiene anterior)
 Entradas:
    Position: Posicion del elemento actual
    List: Lista a manipular
 Salidas:
    Position: Posición del elemento anterior o nulo si es el primero
 Precondiciones: La lista está inicializada y position es una posicion valida de la lista
 */

#endif