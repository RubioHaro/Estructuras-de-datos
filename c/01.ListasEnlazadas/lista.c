#include "lista.h"
#include <stdlib.h>
#include <string.h>

Lista* crearLista(char propietario[]){
    Lista* listita = (Lista*) malloc(sizeof (Lista));
    printf("\n Creando lista...");

    strncpy(listita->propietario, propietario, 50);
    listita->longitud = 0;
    printf(" Lista creada. \n");
    return listita;
}

Nodo* CrearNodo(Libro* librito){
    Nodo* nodo = (Nodo*) malloc(sizeof (Nodo));
    strncpy(nodo->libro.titulo, librito->titulo, 50);
    strncpy(nodo->libro.autor, librito->autor, 50);
    strncpy(nodo->libro.isbn, librito->isbn, 13);
    nodo->siguiente = 0;
    return nodo;
}

void DestruirNodo(Nodo* nodo){
    free(nodo);
}

void InsertarPrincipio(Lista* lista, Libro* libro){
    Nodo* nodo = CrearNodo(libro);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++; 
}

void InsertarFinal(Lista* lista, Libro* libro){
    Nodo* nodo = CrearNodo(libro);
    Nodo* puntero = lista->cabeza;

    if(lista->cabeza == 0){
        lista->cabeza = nodo;
    }else{
        Nodo* puntero = lista->cabeza;
        while (puntero->siguiente){
            puntero = puntero->siguiente;
        } 
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

void InsertarLibro(int posicion, Lista* lista, Libro* libro){
    Nodo* nodo = CrearNodo(libro);

    if(lista->cabeza == 0){
        lista->cabeza = nodo;
    } else {
        Nodo* puntero = lista->cabeza;
        int posicion = 0;

         while (posicion < posicion && puntero->siguiente)
        {
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    } 
    lista->longitud++;
}

Libro* Obtener(int n, Lista* lista){
    if(lista->cabeza == 0){
        return 0;
    }else{
        Nodo* puntero = lista->cabeza;
        int posicion = 0;

        while (posicion < n && puntero->siguiente)
        {
            puntero = puntero->siguiente;
            posicion++;
        }

        if(posicion != n){
            return 0;
        } else
        {
            return &puntero->libro;
        }
    }
}

int Contar(Lista* lista){
    return lista->longitud;
}

int estaVacia(Lista* lista){
    return lista->cabeza == 0;
}

void EliminarPrimer(Lista* lista){

    if(lista->cabeza){
        Nodo* eliminar = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(eliminar);
        lista->longitud--;
    }
}

void EliminarUltimo(Lista* lista){
    if(lista->cabeza){

        if(lista->cabeza->siguiente){
            Nodo* puntero = lista->cabeza;

            while (puntero->siguiente->siguiente)
            {
                puntero = puntero->siguiente;
                /* code */
            }
            Nodo* eliminar = puntero->siguiente;
            puntero->siguiente = 0;
            DestruirNodo(eliminar);
            lista->longitud--;

        } else
        {
            Nodo* eliminar = lista->cabeza;
            lista->cabeza = 0;
            DestruirNodo(eliminar);
            lista->longitud--;
        }   
    }
}

void Eliminar(int posicionAEliminar,Lista* lista){
    if(lista->cabeza) {
        if(posicionAEliminar==0){
            Nodo* eliminar = lista->cabeza;
            lista->cabeza = lista->cabeza->siguiente;
            DestruirNodo(eliminar);
            lista->longitud--;
        } else if(posicionAEliminar < lista->longitud){
            Nodo* puntero = lista->cabeza;
            int posicion = 0;
            while (posicion < (posicionAEliminar-1)) {
                puntero = puntero->siguiente;
                posicion++;
            }
            Nodo* eliminar = puntero->siguiente;
            puntero->siguiente = eliminar->siguiente;
            DestruirNodo(eliminar);
            lista->longitud--;
        }
    }
}