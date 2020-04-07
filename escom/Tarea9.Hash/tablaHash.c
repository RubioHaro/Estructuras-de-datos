#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define N 2024;

struct Nodo
{
    int llave;
    int valor;
    struct Nodo *sig;
};

struct TablaHash
{
    struct Nodo *tabla[2024];
};

int agregarElemento(struct TablaHash *tabla, int llave)
{
    
}

// unsigned int hash(unsigned char *llave,int longitud,unsigned int hash_anterior);
// int agrega(struct TablaHash *t,int llave,int dato);
// struct Nodo *busca(struct TablaHash *t,int llave);
//void inicializa

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
