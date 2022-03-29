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

void createEmptyList (tList *L){ //Cabecera de la funcion. Recibe la lista como variable dinamica porque la va a modificar y queremos mantener los cambios que se hagan en la funcion
    L->lastPos=LNULL; //Inicializamos la lista vacia
}

bool isEmptyList (tList L){ //Cabecera de la funcion. Recibe la lista (solo la va a consultar, sin modificarla)
    return (L.lastPos == LNULL); //Devuelve true si la ultima posicion es nula (si la lista esta vacia) y false si no lo es
}

tPosL first (tList L){ //Cabecera de la funcion. Recibe la lista
    return 0; //Devuelve el primer elemento de la lista (Al ser un array, va desde 0 a n-1)
}

tPosL  last (tList L){ //Cabecera de la funcion. Recibe la lista
    return L.lastPos; //Devuelve la ultima posicion de la lista
}

tPosL next (tPosL p, tList L){ //Cabecera de la funcion. Recibe la posicion de la que queremos saber la siguiente y la lista donde se encuentra
    if (p == last(L)) //Si la posicion dada es la ultima
        return LNULL; //Devolvemos nulo (No hay siguiente a la ultima)
    else return ++p; //Si no es la ultima posicion, devolvemos la siguiente a la dada (++p porque estamos en el contexto del manejo de arrays)
}

tPosL previous (tPosL p, tList L){ //Cabecera de la funcion. Recibe la posicion del elemento del que queremos su siguiente y la lista donde buscarlo
    return --p; //Delvuelve el anterior (--p porque estamos manejando arrays)
}

bool insertItem (tItemL d, tPosL p, tList *L){ //Cabecera de la funcion. Recibe el item a insertar, la posicion donde insertarlo y la lista donde insertarlo (como variable dinamica, para que se mantengan los cambios)
    tPosL i; //Creamos una variable local tipo tPosL para recorrer el array
    if (L->lastPos == MAX-1) { //Si el array está completo (No podemos insertar)
        return false; //Devolvemos falso conforme no se pudo realizar la operacion
    } else { //Si la lista no esta completa:
        L->lastPos++; //
        if (p == LNULL) { //Si la posicion indicada es nula
            L->data[L->lastPos] = d; //Añade el elemento al final de la lista
        } else { //Si la posicion indicada no es nula, hay que añadir el elemento 
            for (i=L->lastPos; i>=p+1; i--) //Desde el ultimo elemento hasta 
                L->data[i] = L->data[i-1]; //Desplazamos los datos a su anterior (Para hacer espacio al nuevo)
            L->data[p] = d; //Insertamos el item
        }
        return true; //Devolvemos verdadero (Insertado correctamente)
    }
}

void deleteAtPosition (tPosL p, tList *L) { //Cabecera de la funcion. Recibe la posicion del elemento a borrar y la lista donde se encuentra el elemento (como variable dinamica, para que se mantengan los cambios). Los borra moviendolos una posicion hacia arriba (anterior)
    tPosL i; //Creamos una variable local para recorrer la lista

    L->lastPos --; //
    for (i=p; i<= L->lastPos; i++) //Desde la posicion p hasta que estemos en la ultima posicion
        L->data[i] = L->data[i+1]; //Desplazamos los datos 1 posicion
}

tItemL getItem (tPosL p, tList L){ //Cabecera de la funcion. Recibe la posicion del item requerido y la lista donde se encuentra
    return L.data[p]; //Accedemos de la lista L (struct) al array data, posicion p
}

void updateItem (tItemL d, tPosL p, tList *L){ //Cabecera de la funcion. Recibe el valor actualizado del elemento, la posicion del elemento a actualizar y la lista donde se encuentra (como variable dinamica, para que se mantengan los cambios)
    L->data[p] = d; //Cambia el valor actual del array data (posicion p) por el actualizado (d)
}

tPosL findItem  (tProductId d, tList L){ //Cabecera de la funcion. Recibe la y la lista donde buscar el elemento
    tPosL p; //Creamos una variable local para recorrer la lista

    if (L.lastPos == LNULL) //Si la ultima posicion es nula
        return LNULL; //Devolver nulo ()
    else { //Si no es nula
        for (p=0; p<L.lastPos &&  (strcmp(L.data[p].productId,d)!=0); p++);  //Recorrer la lista mientras p sea menor que la ultima posicion y el dato del elemento no coincida con el dado; p=0 equivale a first(L) y p++ equivale a next(p); Se puede poner solo p<L.lastPos porque es implementacion estatica
        if (strcmp (L.data[p].productId, d)==0) //Si salio del bucle porque encontro el dato
            return p; //Devolver la posicion donde se encuentra
        else //Si no salio del bucle porque ya lo encontro (salio porque no lo encontro)
            return LNULL; //Salio porque llego a lastPos y no lo encontró. Entonces devolvemos nulo

    }
}
