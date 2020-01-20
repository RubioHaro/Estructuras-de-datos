#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libro.h"

typedef struct Nodo
{
    Libro libro;
    struct Nodo* siguiente;
} Nodo;

typedef struct Lista
{   
    char propietario[50];
    Nodo* cabeza;
    int longitud;

} Lista; 

// Nodo* CrearNodo(Libro* librito);

// void DestruirNodo(Nodo* nodo);

// void InsertarPrincipio(Lista* lista, Libro* libro);

// void InsertarFinal(Lista* lista, Libro* libro);

// void InsertarLibro(int posicion, Lista* lista, Libro* libro);

// Libro* Obtener(int n, Lista* lista);

// int Contar(Lista* lista);

// int estaVacia(Lista* lista);

// void EliminarPrimer(Lista* lista);

// void EliminarUltimo(Lista* lista);

// void Eliminar(int posicionAEliminar,Lista* lista);

#endif /* lista_h */