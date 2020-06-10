#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    struct Nodo *padre;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
    int valor;
};

struct Nodo *crearNodo(struct Nodo *padre, int valor);
void agregarValor(struct Nodo *arbol, int valor);
struct Nodo *iniciarArbol();

int main()
{
    struct Nodo *arbol;
    arbol = iniciarArbol();
    agregarValor(arbol, 10);
    agregarValor(arbol, 20);
    agregarValor(arbol, 30);
}

struct Nodo *iniciarArbol()
{
    return crearNodo(NULL, 100);
}

struct Nodo *crearNodo(struct Nodo *padre, int valor)
{
    struct Nodo *nodo;
    nodo = calloc(sizeof(struct Nodo), 1);
    nodo->padre = padre;
    nodo->valor = valor;
    return nodo;
}

void agregarValor(struct Nodo *arbol, int valor)
{
    struct Nodo *temp, *pivote;
    int derecho = 0;
    if (arbol)
    {
        temp = arbol;
        while (temp != NULL)
        {
            pivote = temp;
            if (valor > temp->valor)
            {
                temp = temp->derecho;
                derecho = 1;
                //derecho
            }
            else
            {
                temp = temp->izquierdo;
                derecho = 0;
                //izquierdo
            }

            temp = crearNodo(pivote, valor);
            if (derecho)
            {
                printf("insertando %i del lado derecho de %i", valor, pivote->valor);
                pivote->derecho = temp;
            }
            else
            {
                printf("insertando %i del lado izquierdo de %i", valor, pivote->valor);
                pivote->izquierdo = temp;
            }
        }
    }
    else
    {
        printf("Error el arbol es NULL");
    }
}
