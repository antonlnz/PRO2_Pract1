/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ruben Seoane Iglesias LOGIN 1: r.seoane.iglesias
 * AUTHOR 2: Anton Lopez Nunez LOGIN 2: anton.lopez.nunez
 * GROUP: *2.4*
 * DATE: 11 / 03 / 2022
 */
#include <string.h>
#include "static_list.h"

void createEmptyList (tList *L){
    L->lastPos=LNULL;
}

bool isEmptyList (tList L){
    return (L.lastPos == LNULL);
}

tPosL first (tList L){
    return 0;
}

tPosL  last (tList L){
    return L.lastPos;
}

tPosL next (tPosL p, tList L){
    if (p == last(L))
        return LNULL;
    else return ++p;
}

tPosL previous (tPosL p, tList L){
    return --p;
}

bool insertItem (tItemL d, tPosL p, tList *L){
    tPosL i;
    if (L->lastPos == MAX-1) { //El array está completo (No podemos insertar)
        return false; //Devolvemos falso
    } else {
        L->lastPos++; //
        if (p == LNULL) { //Si la posicion indicada es nula
            L->data[L->lastPos] = d; //Añade el elemento al final de la lista
        } else {
            for (i=L->lastPos; i>=p+1; i--) //
                L->data[i] = L->data[i-1]; //
            L->data[p] = d; //
        }
        return true; //Devolvemos verdadero
    }
}

void deleteAtPosition (tPosL p, tList *L) { //Borrar elementos. Moviendolos una posicion hacia arriba
    tPosL i;

    L->lastPos --;
    for (i=p; i<= L->lastPos; i++)
        L->data[i] = L->data[i+1];
}

tItemL getItem (tPosL p, tList L){
    return L.data[p]; //accedemos de la lista L (struct) al array data
}

void updateItem (tItemL d, tPosL p, tList *L){
    L->data[p] = d;
}

tPosL findItem  (tProductId d, tList L){
    tPosL p;

    if (L.lastPos == LNULL)
        return LNULL;
    else {
        for (p=0; p<L.lastPos &&  (strcmp(L.data[p].productId,d)!=0); p++); //p=0 equivale a first(L) y p++ equivale a next(p); Se puede poner solo p<L.lastPos porque es implementacion estatica
            if (strcmp (L.data[p].productId, d)==0) //Salio del bucle porque encontro el dato
                return p;
            else
                return LNULL; //Salio porque llego a lastPos y no lo encontró


    }
}