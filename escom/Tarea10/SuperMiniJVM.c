/*
	MiniJVM.c
	Codigo Base: Carlos Pineda G. 2020
    Adaptaciones: Rubio Haro Rodrigo R. 2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define N 30
struct Pila
{
    float arreglo[N];
    int sp;
};

struct Nodo *factor();
struct Nodo
{
    char *valor;
    struct Nodo *izq;
    struct Nodo *der;
};

//char *expresion[] = {"10", "+", "20.5", "+", "30", "*", "40", "/", "3", "+", "(", "1", "+", "2", ")", "/", "(", "2", "+", "3", ")", ";"};
//char *expresion[] = {"100", "/", "200", "*", "2", "-", "10", "+", "3", ";"};
//char *expresion[] = {"1", "/", "2", "/", "3", "/", "(", "4", "+", "5", ")", ";"};
char *expresion[] = {"1", "*", "2", "*", "3", "*", "4", "*", "5", ";"};

//    10+20.5+30*40/3+(1+2)/(2+3) =
//    100/200*2-10+3 = -6
//    1/2/3/(4+5) = 0.018519
//    1*2*3*4*5 = 120.0
int i = 0;

struct Nodo *crea_nodo(char *valor, struct Nodo *izq, struct Nodo *der)
{
    struct Nodo *p = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (p == NULL)
    {
        printf("Error en malloc");
        exit(1);
    }
    p->valor = valor;
    p->izq = izq;
    p->der = der;
    return p;
}

struct Nodo *termino()
{
    struct Nodo *a = factor();
    while (!strcmp(expresion[i], "*") || !strcmp(expresion[i], "/"))
    {
        char *operador = expresion[i];
        i++;
        struct Nodo *b = factor();
        a = crea_nodo(operador, a, b);
    }
    return a;
}

struct Nodo *expresion_aritmetica()
{
    struct Nodo *a = termino();
    struct Nodo *b;
    while (!strcmp(expresion[i], "+") || !strcmp(expresion[i], "-"))
    {
        char *operador = expresion[i];
        i++;
        b = termino();
        a = crea_nodo(operador, a, b);
    }
    return a;
}

int _xtras = 0;
struct Nodo *factor()
{
    struct Nodo *r;
    if (!strcmp(expresion[i], "("))
    {
        i++;
        r = expresion_aritmetica();
        if (strcmp(expresion[i], ")"))
        {
            fprintf(stderr, "Se espera )");
            exit(1);
        }
        i++;
        _xtras += 2;
    }
    else
    {
        r = crea_nodo(expresion[i], NULL, NULL);
        i++;
    }
    return r;
}

int posicionInstrucciones = 0;
void setValue(struct Nodo *nodo, char *instrucciones[])
{
    if (nodo)
    {
        if (nodo->valor)
        {
            char *caracter = nodo->valor;
            instrucciones[posicionInstrucciones] = nodo->valor;
        }
    }
    posicionInstrucciones++;
}

void recorre_post_orden(struct Nodo *nodo, char *instrucciones[])
{
    if (nodo)
    {
        if (nodo->izq != NULL)
            recorre_post_orden(nodo->izq, instrucciones);
        if (nodo->der != NULL)
            recorre_post_orden(nodo->der, instrucciones);
        setValue(nodo, instrucciones);
    }
}

int inicializa_pila(struct Pila *p)
{
    if (p == NULL)
        return -1;
    p->sp = N - 1;
    return 0;
}

int pila_vacia(struct Pila *p)
{
    return p->sp == N - 1;
}

int pila_llena(struct Pila *p)
{
    return p->sp == -1;
}

int push(struct Pila *p, float valor)
{
    if (p != NULL && !pila_llena(p))
    {
        p->arreglo[p->sp] = valor;
        (p->sp)--;
        return 0;
    }
    else
        return -1;
}

int pop(struct Pila *p, float *valor)
{
    if (p != NULL && !pila_vacia(p))
    {
        (p->sp)++;
        *valor = p->arreglo[p->sp];
        p->arreglo[p->sp] = 0;
        return 0;
    }
    else
        return -1;
}

void _push(struct Pila *p, float valor)
{
    if (push(p, valor) == -1)
    {
        printf("Error al ejecutar push");
        exit(1);
    }
}

float _pop(struct Pila *p)
{
    float valor;
    if (pop(p, &valor) == -1)
    {
        printf("Error al ejecutar pop");
        exit(1);
    }
    return valor;
}

int main()
{
    struct Pila p;
    inicializa_pila(&p);

    //printf("\nCalculadora de instrucciones infijas");
    char *comando[N];

    i = 0;
    struct Nodo *nodo = expresion_aritmetica();
    //printf("\nNodo Generado");

    if (strcmp(expresion[i], ";"))
    {
        fprintf(stderr, "Se espera ;");
        exit(1);
    }

    int longitud = i - _xtras;

    printf("\nExpresion generada: ");
    i = 0;
    recorre_post_orden(nodo, comando);
    char *instrucciones[longitud];
    if (comando)
        for (int h = 0; h < longitud; h++)
        {
            printf("%s ", comando[h]);
            instrucciones[h] = comando[h];
        }

    printf("= ");
    for (int i = 0; i < sizeof(instrucciones) / sizeof(char *); i++)
    {
        if (strcmp(instrucciones[i], "+") == 0)
        {
            float a = _pop(&p);
            float b = _pop(&p);
            _push(&p, b + a);
            continue;
        }
        if (strcmp(instrucciones[i], "-") == 0)
        {
            float a = _pop(&p);
            float b = _pop(&p);
            _push(&p, b - a);
            continue;
        }
        if (strcmp(instrucciones[i], "*") == 0)
        {
            float a = _pop(&p);
            float b = _pop(&p);
            _push(&p, b * a);
            continue;
        }
        if (strcmp(instrucciones[i], "/") == 0)
        {
            float a = _pop(&p);
            float b = _pop(&p);
            _push(&p, b / a);
            continue;
        }
        _push(&p, atof(instrucciones[i]));
    }
    printf("%f\n", p.arreglo[p.sp + 1]);
}
