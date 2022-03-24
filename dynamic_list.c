/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Ruben Seoane Iglesias LOGIN 1: r.seoane.iglesias
 * AUTHOR 2: Anton Lopez Nunez LOGIN 2: anton.lopez.nunez
 * GROUP: *2.4*
 * DATE: 04 / 03 / 2022
 */
#include <string.h>
#include "dynamic_list.h"

void createEmptyList (tList *L){
    *L = LNULL; //
}

bool isEmptyList (tList L){
    return (L == LNULL); //Si el primer elemento es nulo (La lista está vacía), devuelve verdadero. Si no, falso
}

tPosL first (tList L){
    return L; //Posicion del primer elemento
}

tPosL next (tPosL p, tList L){
    return p->next;
}

tPosL last (tList L){
    tPosL p;
    for (p = L; p->next != NULL; p=p->next); //p=L equivale a first(L). Y p=p->next equivale a next (p,L)
    return p;
}

tPosL previous (tPosL p, tList L){
    tPosL q;
    if (L==p) {
        return LNULL;
    }else{
        q=L;
        while (q->next != p)
            q = q->next;
        return q;
        /*for(q=L; q->next != p; q=q->next);
        return q;*/
    }
}

bool createNode (tPosL *p){
    *p= malloc(sizeof(**p));
    return *p != LNULL;
}

bool insertItem (tItemL d, tPosL p, tList *L) {
    tPosL q, r;
    if (!createNode(&q))
        return false;
    else {
        q->data = d;
        q->next = LNULL;
        if (*L == LNULL)
            *L = q;
        else if (p == LNULL) {
            r = *L;
            while (r->next != LNULL) {
                r = r->next;
            }
            r->next = q;
        } else if (p == *L) {
            q->next = *L;
            *L = q;
        } else {
            q->data = p->data;
            p->data = d;
            q->next = p->next;
            p->next = q;
        }
    }
    return true;
}

void deleteAtPosition (tPosL p, tList *L){
    tPosL q;
    if(*L==p){ //Si p=primer valor de la lista
        *L = p->next; //Asigna a L el valor del que le sucede en la lista
    }else if(p->next == LNULL){ //Si el siguiente es nulo, p nulo (Estamos insertando el elemento al final) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        for(q=*L; q->next != p; q=q->next); //desde el primer elemento hasta que el siguiente de q sea igual a p, sigue
        q->next = LNULL;
    }else {
        q = p->next; //q=siguiente de p
        p->data = q->data; //Asignamos a p el item al que apunta q
        p->next = q->next; //Asignamos a p el siguiente de q
        p = q;
    }
    free(p); //Liberamos la memoria ocupada por p
}

tItemL getItem (tPosL p, tList L){
    return p->data;
}

void updateItem (tItemL d, tPosL p, tList *L){
    p->data = d;
}

tPosL findItem (tProductId d, tList L){
    tPosL p;
    for (p=L; (p!=LNULL) && (strcmp(p->data.productId,d)!=0);p=p->next);
    return p;
}