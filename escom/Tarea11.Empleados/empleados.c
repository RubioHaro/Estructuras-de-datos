#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"

struct ArbolBinario
{
    struct Nodo *raiz;
};

struct Nodo
{
    struct Nodo *padre;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
    struct Empleado *empleado;
};

struct Empleado
{
    char *nombre;
    int edad;
    float sueldo;
};
void iniciarArbol(struct ArbolBinario *arbol);
struct Nodo *crearNodo(struct Nodo *padre, struct Empleado *empleado);

void recorre_pre_orden(struct Nodo *nodo);
void recorre_orden(struct Nodo *nodo);
void recorre_post_orden(struct Nodo *nodo);
int agrega_nodo(struct ArbolBinario *arbol, struct Empleado *empleado);

int busca_orden(struct Nodo *nodo, char *nombre);
int busca_orden_con_padre(struct Nodo *nodo, struct Nodo *padre, char *nombre);
struct Nodo *busca_nodo_con_padre(struct ArbolBinario *arbol, struct Nodo *padre, char *nombre);

struct Empleado *crearEmpleado(char nombre[50], int edad, float sueldo);
void registrarEmpleado(struct ArbolBinario *arbol);
void buscarEmpleado(struct ArbolBinario *arbol);
void eliminarEmpleado(struct ArbolBinario *arbol);

void imprimirEmpleado(struct Empleado *empleado);
void printListElementEmpleados(struct Nodo *nodo);

void printfln(char *string);
void printferror(char *string);
void limpiar_pantalla();

int seleccionarOpcion();
void desplegarMenu();

int main()
{
    struct ArbolBinario arbol;
    iniciarArbol(&arbol);
    desplegarMenu(&arbol);
}

void desplegarMenu(struct ArbolBinario *arbol)
{

    int exit = 0;
    while (!exit)
    {
        printf(ANSI_COLOR_YELLOW);
        printfln("************************************");
        printfln("Sistema de Registro de empleados");
        printfln("************************************");
        printf(ANSI_COLOR_RESET);
        printfln("Menu de Opciones");
        printfln("1. Agregar Empleado");
        printfln("2. Buscar Empleado");
        printfln("3. Borrar Empleado");
        printfln("4. Desplegar Plantilla");
        printfln("5. Salir");
        switch (seleccionarOpcion())
        {
        case 1:
            limpiar_pantalla();
            registrarEmpleado(arbol);
            break;
        case 2:
            limpiar_pantalla();
            buscarEmpleado(arbol);
            break;
        case 3:
            limpiar_pantalla();
            eliminarEmpleado(arbol);
            break;
        case 4:
            limpiar_pantalla();
            printfln("Imprimiendo plantilla de Empleados");
            recorre_orden(arbol->raiz);
            break;
        case 5:
            exit = 1;
            limpiar_pantalla();
            printfln("Saliendo. Te esperamos de vuelta");
            break;

        default:
            printfln("No has ingresado una opcion valida. Vuelve a intentar");
            break;
        }
    }
}

int seleccionarOpcion()
{
    printf("Ingresa la opcion:" ANSI_COLOR_YELLOW);
    int opcion = 0;
    scanf("%d", &opcion);
    printf(ANSI_COLOR_RESET);
    return opcion;
}

void iniciarArbol(struct ArbolBinario *arbol)
{
    arbol->raiz = NULL;
}

struct Nodo *crearNodo(struct Nodo *padre, struct Empleado *empleado)
{
    struct Nodo *nodo;
    nodo = malloc(sizeof(struct Nodo));
    if (nodo)
    {
        nodo->padre = padre;
        nodo->empleado = empleado;
        return nodo;
    }
    return NULL;
}

void recorre_pre_orden(struct Nodo *nodo)
{
    imprimirEmpleado(nodo->empleado);
    if (nodo->izquierdo != NULL)
        recorre_pre_orden(nodo->izquierdo);
    if (nodo->derecho != NULL)
        recorre_pre_orden(nodo->derecho);
}
void recorre_orden(struct Nodo *nodo)
{
    if (nodo->izquierdo != NULL)
        recorre_orden(nodo->izquierdo);
    printListElementEmpleados(nodo);
    if (nodo->derecho != NULL)
        recorre_orden(nodo->derecho);
}

void printListElementEmpleados(struct Nodo *nodo)
{
    printf(ANSI_COLOR_BLUE);
    printfln("*******************************");
    printf(ANSI_COLOR_RESET);

    imprimirEmpleado(nodo->empleado);

    printf(ANSI_COLOR_BLUE);
    printfln("*******************************");
    printf(ANSI_COLOR_RESET);
}

int busca_orden(struct Nodo *nodo, char *nombre)
{
    int encontrado = 0;
    if (nodo)
    {
        if (strcmp(nodo->empleado->nombre, nombre) == 0)
        {
            //printf("\nEncontrado: %s = %s ", nodo->empleado->nombre, nombre);
            imprimirEmpleado(nodo->empleado);
            encontrado = 1;
        }
        else
        {
            if (nodo->izquierdo != NULL)
                busca_orden(nodo->izquierdo, nombre);
            if (nodo->derecho != NULL)
                busca_orden(nodo->derecho, nombre);
        }
    }
    else
        printferror("el nodo es null, es posible que el arbol no haya sido iniciado");
    return encontrado;
}

int busca_orden_con_padre(struct Nodo *nodo, struct Nodo *padre, char *nombre)
{
    int encontrado = 0;
    if (nodo)
    {
        if (strcmp(nodo->empleado->nombre, nombre) == 0)
        {
            printf("\nEncontrado: %s = %s ", nodo->empleado->nombre, nombre);
            imprimirEmpleado(nodo->empleado);
            encontrado = 1;
        }
        else
        {
            padre = nodo;
            if (nodo->izquierdo != NULL)
                busca_orden_con_padre(nodo->izquierdo, padre, nombre);
            if (nodo->derecho != NULL)
                busca_orden_con_padre(nodo->derecho, padre, nombre);
        }
    }
    else
        printferror("el nodo es null, es posible que el arbol no haya sido iniciado");
    return encontrado;
}

void recorre_post_orden(struct Nodo *nodo)
{
    if (nodo->izquierdo != NULL)
        recorre_post_orden(nodo->izquierdo);
    if (nodo->derecho != NULL)
        recorre_post_orden(nodo->derecho);
    imprimirEmpleado(nodo->empleado);
}

int agrega_nodo(struct ArbolBinario *arbol, struct Empleado *empleado)
{
    if (arbol->raiz != NULL)
    {
        struct Nodo *nodo = arbol->raiz;
        for (;;)
            if (empleado->sueldo < nodo->empleado->sueldo)
            {
                if (nodo->izquierdo == NULL)
                {
                    nodo->izquierdo = (struct Nodo *)malloc(sizeof(struct Nodo));
                    if (nodo->izquierdo == NULL)
                        return -1;
                    nodo->izquierdo->empleado = empleado;
                    nodo->izquierdo->izquierdo = NULL;
                    nodo->izquierdo->derecho = NULL;
                    break;
                }
                else
                    nodo = nodo->izquierdo;
            }
            else if (empleado->sueldo > nodo->empleado->sueldo)
            {
                if (nodo->derecho == NULL)
                {
                    nodo->derecho = (struct Nodo *)malloc(sizeof(struct Nodo));
                    if (nodo->derecho == NULL)
                        return -1;
                    nodo->derecho->empleado = empleado;
                    nodo->derecho->izquierdo = NULL;
                    nodo->derecho->derecho = NULL;
                    break;
                }
                else
                    nodo = nodo->derecho;
            }
            else
                return -2;
    }
    else
    {
        arbol->raiz = (struct Nodo *)malloc(sizeof(struct Nodo));
        arbol->raiz->empleado = empleado;
        arbol->raiz->izquierdo = NULL;
        arbol->raiz->derecho = NULL;
    }
    return 0;
}

int elimina_nodo(struct ArbolBinario *arbol, char *nombre)
{
    struct Nodo *padre = NULL;
    struct Nodo *nodo = arbol->raiz;
    for (;;)
    {
        if (nodo != NULL)
        {
            nodo = busca_nodo_con_padre(arbol, padre, nombre);
            // se encontró el nodo con el nombre a eliminar
            if (nodo->izquierdo == NULL && nodo->derecho == NULL)
            {
                if (padre == NULL)
                    arbol->raiz = NULL;
                else if (nodo == padre->izquierdo)
                    padre->izquierdo = NULL;
                else
                    padre->derecho = NULL;
                free(nodo);
                return 0;
            }
            else
            {
                padre = nodo;
                struct Nodo *q;
                if (nodo->izquierdo != NULL)
                {
                    q = nodo->izquierdo;
                    while (q->derecho != NULL)
                    {
                        padre = q;
                        q = q->izquierdo;
                    }
                }
                else
                {
                    q = nodo->derecho;
                    while (q->izquierdo != NULL)
                    {
                        padre = q;
                        q = q->izquierdo;
                    }
                }
                struct Empleado *x = nodo->empleado;
                nodo->empleado = q->empleado;
                q->empleado = x;
                nodo = q;
                continue;
            }
        }
        else
            break;
    }
    return -1;
}

struct Nodo *busca_nodo(struct ArbolBinario *arbol, char *nombre)
{
    if (arbol && nombre)
    {
        struct Nodo *nodo = arbol->raiz;
        int encontrado = busca_orden(nodo, nombre);
        if (encontrado)
            return nodo;
        else
            printferror("No se ha encontrado ningun empleado con ese nombre");
    }
    return NULL;
}

struct Nodo *busca_nodo_con_padre(struct ArbolBinario *arbol, struct Nodo *padre, char *nombre)
{
    if (arbol && nombre)
    {
        struct Nodo *nodo = arbol->raiz;
        int encontrado = busca_orden_con_padre(nodo, padre, nombre);
        if (encontrado)
            return nodo;
        else
            printferror("No se ha encontrado ningun empleado con ese nombre");
    }
    return NULL;
}

struct Empleado *crearEmpleado(char *nombre, int edad, float sueldo)
{
    struct Empleado *empleado;
    empleado = malloc(sizeof(struct Empleado));
    if (empleado)
    {
        empleado->edad = edad;
        empleado->sueldo = sueldo;
        empleado->nombre = (char *)malloc(50);
        strcpy(empleado->nombre, nombre);
        return empleado;
    }
    return NULL;
}

void imprimirEmpleado(struct Empleado *empleado)
{
    printf("Datos del empleado:");
    printf("\n");
    printf("Nombre: %s ", empleado->nombre);
    printf("\n");
    printf("Edad: %d , sueldo %f", empleado->edad, empleado->sueldo);
    printf("\n");
}

void buscarEmpleado(struct ArbolBinario *arbol)
{
    if (arbol)
    {
        char nombre[50];
        printfln("Ingresa el nombre del empleado a buscar (tendra que ser exacto)");
        printf("nombre: ");
        scanf("%s", nombre);
        if (nombre)
            busca_nodo(arbol, nombre);
    }
    else
        printferror("El arbol de registros no ha sido iniciado");
}

void eliminarEmpleado(struct ArbolBinario *arbol)
{
    if (arbol)
    {
        char nombre[50];
        printfln("Ingresa el nombre del empleado a eliminar (tendra que ser exacto)");
        printf("nombre: ");
        scanf("%s", nombre);
        if (nombre)
            elimina_nodo(arbol, nombre);
    }
    else
        printferror("El arbol de registros no ha sido iniciado");
}

void registrarEmpleado(struct ArbolBinario *arbol)
{

    if (arbol)
    {
        struct Empleado *empleado;
        empleado = crearEmpleado("Juan", 18, 5000);

        char nombre[50];
        int edad;
        float salario;

        printfln("Ingresa el nombre del nuevo empleado:");
        scanf("%s", nombre);
        printf("Ingresa la edad de %s \n", nombre);
        scanf("%d", &edad);
        printf("Ingresa el salario de %s \n", nombre);
        scanf("%f", &salario);

        empleado = crearEmpleado(nombre, edad, salario);
        limpiar_pantalla();
        agrega_nodo(arbol, empleado);
        printfln("Empleado con los siguientes datos Registrado.");
        imprimirEmpleado(empleado);
    }
    else
        printferror("El arbol de registros no ha sido iniciado");
}

void limpiar_pantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printfln(char *string)
{
    printf("%s", string);
    printf("\n");
}

void printferror(char *string)
{
    printf(ANSI_COLOR_RED);
    printf("System: %s", string);
    printf(ANSI_COLOR_RESET);
    printf("\n");
}