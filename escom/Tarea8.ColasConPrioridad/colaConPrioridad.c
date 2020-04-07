#include <stdio.h>
#include <malloc.h>
struct Nodo
{
    char nombre[20];           // nombre del empleado
    char apellido_paterno[20]; // apellido paterno del empleado
    float sueldo;              // sueldo del empleado
    char prioridad[40];        // apellido paterno concatenado con el nombre
    struct Nodo *sig;          //siguiente nodo
};
struct ColaPrioridad
{
    struct Nodo *cola;
};
int inicializa_cola(struct ColaPrioridad *q)
{
    if (q == NULL)
        return -1;
    q->cola = NULL;
    return 0;
}
int cola_vacia(struct ColaPrioridad *q)
{
    return q->cola == NULL;
}

int add_cola(struct ColaPrioridad *q, char *nombre, char *apellido_paterno, float sueldo, char *prioridad)
{
    if (q == NULL)
        return -1;
    struct Nodo *p = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (p == NULL)
        return -1;
    p->valor = valor;
    p->prioridad = prioridad;
    if (cola_vacia(q))
    {
        q->cola = p;
        p->sig = NULL;
    }
    else if (prioridad >= q->cola->prioridad)
    {
        p->sig = q->cola;
        q->cola = p;
    }
    else
        for (struct Nodo *r = q->cola;; r = r->sig)
            if (r->sig == NULL)
            {
                r->sig = p;
                p->sig = NULL;
                break;
            }
            else if (prioridad >= r->sig->prioridad)
            {
                p->sig = r->sig;
                r->sig = p;
                break;
            }
    return 0;
}

int remove_cola(struct ColaPrioridad *q, int *valor)
{
    if (q == NULL || cola_vacia(q))
        return -1;
    if (q->cola->sig == NULL)
    {
        *valor = q->cola->valor;
        q->cola = NULL;
    }
    else
    {
        struct Nodo *r;
        for (r = q->cola;; r = r->sig)
            if (r->sig->sig == NULL)
            {
                *valor = r->sig->valor;
                free(r->sig);
                r->sig = NULL;
                break;
            }
    }
    return 0;
}
int main()
{
    struct ColaPrioridad q;
    inicializa_cola(&q);
    printf("%i\n", add_cola(&q, 100, 2));
    printf("%i\n", add_cola(&q, 200, 2));
    printf("%i\n", add_cola(&q, 300, 0));
    printf("%i\n", add_cola(&q, 400, 1));
    printf("%i\n", add_cola(&q, 500, 3));
    printf("%i\n", add_cola(&q, 600, 2));
    printf("%i\n", add_cola(&q, 700, -1));
    int valor;
    printf("%i\n", remove_cola(&q, &valor));
    printf("%i\n", valor);
    printf("%i\n", remove_cola(&q, &valor));
    printf("%i\n", valor);
    printf("%i\n", remove_cola(&q, &valor));
    printf("%i\n", valor);
    printf("%i\n", remove_cola(&q, &valor));
    printf("%i\n", valor);
    printf("%i\n", remove_cola(&q, &valor));
    printf("%i\n", valor);
    printf("%i\n", remove_cola(&q, &valor));
    printf("%i\n", valor);
    printf("%i\n", remove_cola(&q, &valor));
    printf("%i\n", valor);
    printf("%i\n", remove_cola(&q, &valor));
}