
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo {
    int valor;
    struct Nodo *siguiente;
    struct Nodo *anterior;
} Nodo;

typedef struct Lista {
    Nodo *cabeza;
    Nodo *ultimo;

} Lista;

Lista *iniciarLista(){
    Lista *listita = (Lista *)malloc(sizeof(Lista));
    printf("\n Creando lista...");
    listita->cabeza = NULL;
    listita->ultimo = NULL;
    printf(" Lista creada. \n");
    return listita;
}

int estaVacia(Lista *lista){
    return lista->cabeza == NULL;
}

Nodo *CrearNodo(int valor) {
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    if (nodo != NULL) {
        nodo->valor = valor;
        nodo->siguiente = NULL;
        nodo->anterior = NULL;
        return nodo;
    }
    else
        return NULL;
}

void DestruirNodo(Nodo *nodo) {
    free(nodo);
}

void ImprimirLista(Lista *lista) {
    Nodo *nodo = lista->cabeza;
    printf(" Imprimiendo Lista: \n");
    if (estaVacia(lista))
        printf("La lista esta vacia!. \n");
    else {
        do {
            printf(" %d ", nodo->valor);
            nodo = nodo->siguiente;
        } while (nodo != NULL);
        printf("\n La lista ha sido desplegada");
    }
}

void ImprimirListaInversa(Lista *lista)
{
    Nodo *ultimoNodo = lista->ultimo;
    Nodo *nodo = ultimoNodo;
    printf(" Imprimiendo Lista desde el ultimo nodo: \n");
    if (!estaVacia(lista)){
        do {
            printf(" %d ", nodo->valor);
            nodo = nodo->anterior;
        } while (nodo != NULL);
        printf("\n La lista ha sido desplegada");
    }
    else
        printf("La lista esta vacia!. \n");
}

//agrega
int InsertarPrincipio(Lista *lista, int valor){

    Nodo *nodo = CrearNodo(valor);
    if (nodo != NULL){
        nodo->siguiente = lista->cabeza;
        nodo->anterior = NULL;
        if (!estaVacia(lista))
            lista->cabeza->anterior = nodo;
        else
            lista->ultimo = nodo;
        lista->cabeza = nodo;
        printf("Digito guardado al principio: %d \n", nodo->valor);
        return 0;
    }
    else
        return -1;
}

//agrega_final
int InsertarFinal(Lista *lista, int valor){
    Nodo *nodo = CrearNodo(valor);
    if (nodo != NULL) {
        if (estaVacia(lista))
            lista->cabeza = nodo;
        else{
            //Lista no Vacia
            Nodo *puntero = lista->cabeza;
            while (puntero->siguiente)
                puntero = puntero->siguiente;
            nodo->anterior = puntero;
            puntero->siguiente = nodo;
            lista->ultimo = nodo;
        }
        printf("Digito guardado al final: %d \n", nodo->valor);
        return 0;
    }
    return -1;
}

//inserta
int InsertarDespues(Lista *lista, Nodo *nodo, int valor){
    Nodo *nuevoNodo = CrearNodo(valor);
    if (nuevoNodo != NULL){
        //Lista Vacia (no tendría por que estar vacia)
        if (estaVacia(lista))
            lista->cabeza = nuevoNodo;
        else{
            nuevoNodo->anterior = nodo;
            Nodo *temporal = nodo->siguiente;
            if (temporal != NULL){
                temporal->anterior = nuevoNodo;
                nuevoNodo->siguiente = temporal;
                if (temporal->siguiente == NULL)
                    lista->ultimo = temporal;
            }
            else{
                nuevoNodo->siguiente = NULL;
                lista->ultimo = nuevoNodo;
            }
            nodo->siguiente = nuevoNodo;
        }
        printf("\nDigito guardado despues del nodo dado: %d \n", nuevoNodo->valor);
        return 0;
    }
    return -1;
}

Nodo *Buscar(int valor, Lista *lista){
    if (!estaVacia(lista)){
        Nodo *nodo = lista->cabeza;
        do{
            if (valor == nodo->valor)
                return nodo;
            else
                nodo = nodo->siguiente;

        } while (nodo != NULL);
    }
    return NULL;
}

//eliminar
int eliminarNodo(Lista *lista, Nodo *nodo){
    int valor = nodo->valor;
    //Lista Vacia (no tendría por que estar vacia)
    if (estaVacia(lista))
        return -1;
    else{
        Nodo *temporal = nodo->siguiente;
        if (temporal != NULL){
            temporal->anterior = nodo->anterior;

            if (nodo->anterior == NULL){
                lista->cabeza = nodo->siguiente;
                lista->ultimo = nodo->siguiente;
            }
            else
                nodo->anterior->siguiente = temporal;
            if (temporal->siguiente == NULL)
                lista->ultimo = temporal;
        }
        else{
            if (nodo->anterior != NULL){
                nodo->anterior->siguiente = NULL;
                lista->ultimo = nodo->anterior;
            }
            else{
                lista->cabeza = NULL;
                lista->ultimo = NULL;
            }
        }
        DestruirNodo(nodo);
    }
    printf("\nNodo dado eliminado, valor: %d \n", valor);
    return 0;
}

void EliminarPrimer(Lista *lista){

    if (estaVacia(lista)){
        Nodo *eliminar = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(eliminar);
    }
}

void EliminarUltimo(Lista *lista){
    if (!estaVacia(lista)){
        if (lista->cabeza->siguiente){
            Nodo *puntero = lista->cabeza;

            while (puntero->siguiente->siguiente)
                puntero = puntero->siguiente;
            Nodo *eliminar = puntero->siguiente;
            puntero->siguiente = NULL;
            lista->ultimo = eliminar->anterior;
            DestruirNodo(eliminar);
        }
        else{
            Nodo *eliminar = lista->cabeza;
            lista->cabeza = NULL;
            lista->ultimo = NULL;
            DestruirNodo(eliminar);
        }
    }
}

void imprimirNodo(Nodo *nodo){
    if (nodo != NULL)
        printf("\n Tenemos el numero: %d", nodo->valor);
    else
        printf("\n no se ha encontrado ningun valor");
}

int main(int argc, char const *argv[]){
    Lista *lista;
    lista = iniciarLista();

    // InsertarPrincipio(lista, 5);
    // InsertarPrincipio(lista, 4);
    // InsertarPrincipio(lista, 3);
    // InsertarPrincipio(lista, 2);
    // InsertarPrincipio(lista, 1);
    // InsertarFinal(lista, 6);
    // InsertarFinal(lista, 7);
    // InsertarFinal(lista, 8);
    // InsertarFinal(lista, 9);
    // InsertarFinal(lista, 10);

    //ImprimirLista(lista);
    //ImprimirListaInversa(lista);

    // Nodo *nodo;
    // nodo = Buscar(1, lista);
    // InsertarDespues(lista, nodo, 88);
    // nodo = Buscar(10, lista);
    // imprimirNodo(nodo);
    // InsertarDespues(lista, nodo, 77);

    // ImprimirLista(lista);
    // ImprimirListaInversa(lista);

    //nodo = Buscar(5, lista);
    //imprimirNodo(nodo);

    //printf("\nbuscando el 11");
    //nodo = Buscar(11, lista);
    //imprimirNodo(nodo);

    // nodo = Buscar(77, lista);
    // imprimirNodo(nodo);
    // eliminarNodo(lista, nodo);
    // ImprimirLista(lista);

    // InsertarPrincipio(lista, 10);
    // InsertarPrincipio(lista, 5);
    // ImprimirLista(lista);
    // ImprimirListaInversa(lista);
    // Nodo *nodo;
    // nodo = Buscar(10, lista);
    // if (nodo != NULL)
    //     eliminarNodo(lista, nodo);
    // ImprimirLista(lista);
    // ImprimirListaInversa(lista);

    return 0;
}
