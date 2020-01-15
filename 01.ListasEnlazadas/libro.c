#include "libro.h"
#include <stdlib.h>
#include <string.h>


Libro* crearLibro(char titulo[], char autor[], char isbn[]){
    Libro* librito = (Libro*) malloc(sizeof (Libro));
    printf("\n Creando libro...");

    strncpy(librito->titulo, titulo, 50);
    strncpy(librito->autor, autor, 50);
    strncpy(librito->isbn, isbn, 13);

    printf(" Libro creado. \n");
    return librito;
}

void printLibro(Libro* libro){
    printf("\n Author: %s", libro->autor);
    printf("\n Title: %s", libro->titulo);
    printf("\n ISBN: %s \n", libro->isbn);
}

// Nodo* CrearNodo(Libro* librito){
//     Nodo* nodo = (Nodo*) malloc(sizeof (Nodo));
//     strncpy(nodo->libro.titulo, librito->titulo, 50);
//     strncpy(nodo->libro.autor, librito->autor, 50);
//     strncpy(nodo->libro.isbn, librito->isbn, 13);
//     nodo->siguiente = 0;
//     return nodo;
// }