#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#endif

#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"

struct Empleado
{
    char *nombre;
    int edad;
    float sueldo;
};

struct ArbolAVL
{
    struct Nodo *raiz;
};

struct Nodo
{
    struct Empleado *empleado;
    int valor;              // valor que contiene el nodo
    int fe;                 // factor de equilibrio del nodo
    struct Nodo *padre;     // apunta al padre del nodo, o NULL si el nodo es la raíz del árbol
    struct Nodo *izquierdo; // apunta al hijo izquierdo
    struct Nodo *derecho;   // apunta al hijo derecho
};

struct Nodo *crea_nodo(int valor, struct Nodo *padre, struct Empleado *empleado);

void recorre_pre_orden(struct Nodo *nodo);
void recorre_orden(struct Nodo *nodo);
void recorre_post_orden(struct Nodo *nodo);

void inicializa_arbol(struct ArbolAVL *arbol);
void recorre_pre_orden(struct Nodo *nodo);
void recorre_orden(struct Nodo *nodo);
void recorre_post_orden(struct Nodo *nodo);
int agrega_nodo(struct ArbolAVL *arbol, int valor, struct Empleado *empleado);

int elimina_nodo(struct ArbolAVL *arbol, int valor);
struct Nodo *busca_nodo(struct ArbolAVL *arbol, int valor);
void actualiza_fe(struct ArbolAVL *arbol, struct Nodo *p, int incremento);

struct Empleado *crearEmpleado(char nombre[50], int edad, float sueldo);
void registrarEmpleado(struct ArbolAVL *arbol);
void buscarEmpleado(struct ArbolAVL *arbol);
void eliminarEmpleado(struct ArbolAVL *arbol);

void imprimirEmpleado(struct Empleado *empleado);
void printListElementEmpleados(struct Nodo *nodo);

void printfln(char *string);
void printferror(char *string);
void limpiar_pantalla();

int seleccionarOpcion();
void desplegarMenu();

int main(int argc, char const *argv[])
{
    struct ArbolAVL arbol;
    inicializa_arbol(&arbol);
    desplegarMenu(&arbol);
    return 0;
}

void desplegarMenu(struct ArbolAVL *arbol)
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

void inicializa_arbol(struct ArbolAVL *arbol)
{
    arbol->raiz = NULL;
}

struct Nodo *crea_nodo(int valor, struct Nodo *padre, struct Empleado *empleado)
{
    struct Nodo *p = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (p == NULL)
        return NULL;
    p->valor = valor;
    p->empleado = empleado;
    p->fe = 0;
    p->padre = padre;
    p->izquierdo = NULL;
    p->derecho = NULL;
    return p;
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
    printf("\n");
    printf("Datos del empleado:");
    printf("id de usuario: %d", nodo->valor);
    imprimirEmpleado(nodo->empleado);

    printf(ANSI_COLOR_BLUE);
    printfln("*******************************");
    printf(ANSI_COLOR_RESET);
}

/*
Función que realiza la rotación simple a la derecha.
(notar que la rotación implica solo la re-asignación de apuntadores):
*/
void RD(struct ArbolAVL *arbol, struct Nodo *x)
{
    struct Nodo *padre = x->padre;
    struct Nodo *y = x->izquierdo;
    struct Nodo *B = y->derecho;
    if (padre != NULL)
        if (x == padre->izquierdo)
            padre->izquierdo = y;
        else
            padre->derecho = y;
    else
        arbol->raiz = y;
    y->derecho = x;
    y->padre = padre;
    x->izquierdo = B;
    x->padre = y;
    if (B != NULL)
        B->padre = x;
    x->fe = 0; // el nodo X está equilibrado
    y->fe = 0; // el nodo Y está equilibrado
}

/*
Función que realiza la rotación simple a la izquierda.
(notar que la rotación implica solo la re-asignación de apuntadores):
*/
void RI(struct ArbolAVL *arbol, struct Nodo *y)
{
    struct Nodo *padre = y->padre;
    struct Nodo *x = y->derecho;
    struct Nodo *B = x->izquierdo;
    if (padre != NULL)
        if (y == padre->izquierdo)
            padre->izquierdo = x;
        else
            padre->derecho = x;
    else
        arbol->raiz = x;
    x->izquierdo = y;
    x->padre = padre;
    y->derecho = B;
    y->padre = x;
    if (B != NULL)
        B->padre = y;
    y->fe = 0; // el nodo Y está equilibrado
    x->fe = 0; // el nodo X está equilibrado
}

/*
Rotación doble a la derecha.
La rotación doble a la derecha se implementa como una rotación izquierda RI(Y) y una rotación derecha RD(X).

Los factores de equilibrio de los nodos X y Y del árbol resultante dependen del factor de equilibrio del nodo Z del árbol original. 
El factor de equilibrio del nodo Z en el árbol resultante es cero, ya que el árbol queda equilibrado:

*/

void RDD(struct ArbolAVL *arbol, struct Nodo *x)
{
    struct Nodo *y = x->izquierdo;
    struct Nodo *z = y->derecho;
    int fe = z->fe;
    RI(arbol, y);
    RD(arbol, x);
    if (fe == -1)
    {
        y->fe = 0;
        x->fe = 1;
    }
    else if (fe == 0)
    {
        y->fe = 0;
        x->fe = 0;
    }
    else if (fe == 1)
    {
        y->fe = -1;
        x->fe = 0;
    }
    z->fe = 0;
}

/*
Rotación doble a la izquierda.
La rotación doble a la izquierda se implementa como una rotación izquierda RD(Y) y una rotación derecha RI(X).

Los factores de equilibrio de los nodos X y Y del árbol resultante dependen del factor de equilibrio del nodo Z del árbol original. 
El factor de equilibrio del nodo Z en el árbol resultante es cero, ya que el árbol queda equilibrado:

*/

void RDI(struct ArbolAVL *arbol, struct Nodo *x)
{
    struct Nodo *y = x->derecho;
    struct Nodo *z = y->izquierdo;
    int fe = z->fe;
    RD(arbol, y);
    RI(arbol, x);
    if (fe == -1)
    {
        y->fe = 1;
        x->fe = 0;
    }
    else if (fe == 0)
    {
        y->fe = 0;
        x->fe = 0;
    }
    else if (fe == 1)
    {
        y->fe = 0;
        x->fe = -1;
    }
    z->fe = 0;
}

int agrega_nodo(struct ArbolAVL *arbol, int valor, struct Empleado *empleado)
{
    if (arbol->raiz != NULL)
    {
        struct Nodo *nodo = arbol->raiz;
        for (;;)
            if (valor < nodo->valor)
            {
                if (nodo->izquierdo == NULL)
                {
                    nodo->izquierdo = crea_nodo(valor, nodo, empleado);
                    if (nodo->izquierdo == NULL)
                        return -2;
                    // si p es hoja, entonces actualiza el FE hasta la raíz
                    // de otra manera actualiza el FE solo en el padre
                    if (nodo->derecho == NULL)
                        actualiza_fe(arbol, nodo->izquierdo, 1);
                    else
                        (nodo->fe)--;
                    break;
                }
                else
                    nodo = nodo->izquierdo;
            }
            else if (valor > nodo->valor)
            {
                if (nodo->derecho == NULL)
                {
                    nodo->derecho = crea_nodo(valor, nodo, empleado);
                    if (nodo->derecho == NULL)
                        return -2;
                    // si p es hoja, entonces actualiza el FE hasta la raíz
                    // de otra manera actualiza el FE solo en el padre
                    if (nodo->izquierdo == NULL)
                        actualiza_fe(arbol, nodo->derecho, 1);
                    else
                        (nodo->fe)++;
                    break;
                }
                else
                    nodo = nodo->derecho;
            }
            else
                return -1; // el valor ya existe
    }
    else
    {
        arbol->raiz = crea_nodo(valor, NULL, empleado);
        if (arbol->raiz == NULL)
            return -2;
    }
    return 0;
}

void actualiza_fe(struct ArbolAVL *arbol, struct Nodo *p, int incremento)
{
    // recorre el árbol en dirección al nodo raíz buscando un nodo con factor de equilibrio -2 o 2
    while (p != NULL && p->padre != NULL)
    {
        if (p == p->padre->izquierdo)
            p->padre->fe -= incremento;
        else
            p->padre->fe += incremento;

        p = p->padre; // "salta" al nodo padre

        // si el factor de equilibrio del nodo p es 2 o -2 balancea el sub-arbol p
        // después de balancear el sub-árbol p sale del ciclo
        if (p->fe == 0)
            break; // el árbol está balanceado, sale del ciclo
        else if (p->fe == -2 && p->izquierdo->fe == -1)
        {
            RD(arbol, p);
            break;
        }
        else if (p->fe == -2 && p->izquierdo->fe == 1)
        {
            RDD(arbol, p);
            break;
        }
        else if (p->fe == 2 && p->derecho->fe == 1)
        {
            RI(arbol, p);
            break;
        }
        else if (p->fe == 2 && p->derecho->fe == -1)
        {
            RDI(arbol, p);
            break;
        }
    }
}

int elimina_nodo(struct ArbolAVL *arbol, int valor)
{
    if (arbol)
    {
        struct Nodo *padre = NULL;
        struct Nodo *p = arbol->raiz;
        printferror("eliminando nodo");
        for (;;)
        {
            if (p != NULL)
            {
                // busca el nodo con el valor
                if (valor < p->valor)
                {
                    padre = p;
                    p = p->izquierdo;
                    continue;
                }
                else if (valor > p->valor)
                {
                    padre = p;
                    p = p->derecho;
                    continue;
                }
                else
                {
                    // se encontró el nodo p con el valor
                    if (p->izquierdo == NULL && p->derecho == NULL)
                    {
                        // p es hoja
                        if (padre == NULL)
                            arbol->raiz = NULL; // no hay padre, se elimina la raíz del árbol
                        else if (p == padre->izquierdo)
                        {
                            // el nodo a eliminar es el hijo izquierdo
                            padre->izquierdo = NULL;
                            // si p es hoja, entonces actualiza el FE hasta la raíz
                            // de otra manera actualiza el FE solo en el padre
                            if (p->derecho == NULL)
                                actualiza_fe(arbol, p->izquierdo, -1);
                            else
                                (p->fe)++;
                        }
                        else
                        {
                            // el nodo a eliminar es el hijo derecho
                            padre->derecho = NULL;
                            // si p es hoja, entonces actualiza el FE hasta la raíz
                            // de otra manera actualiza el FE solo en el padre
                            if (p->izquierdo == NULL)
                                actualiza_fe(arbol, p->derecho, -1);
                            else
                                (p->fe)--;
                        }
                        free(p);
                        return 0;
                    }
                    else
                    {
                        // p no es hoja
                        padre = p;
                        struct Nodo *q;
                        if (p->izquierdo != NULL)
                        {
                            // hay un árbol izquierdo
                            // en el árbol izquierdo se busca el nodo más a la derecha
                            q = p->izquierdo;
                            while (q->derecho != NULL)
                            {
                                padre = q;
                                q = q->derecho;
                            }
                        }
                        else
                        {
                            // no hay un árbol izquierdo
                            // en el árbol derecho se busca el nodo más a la izquierda
                            q = p->derecho;
                            while (q->izquierdo != NULL)
                            {
                                padre = q;
                                q = q->izquierdo;
                            }
                        }
                        // intercambia los valores de los nodos p y q
                        int x = p->valor;
                        p->valor = q->valor;
                        q->valor = x;
                        // ahora se va a borrar el nodo p
                        p = q;
                        continue;
                    }
                }
            }
            else
                break;
        }
        return -1; // no se encontró el nodo a eliminar
    }
}

void despliega_nodo(struct Nodo *p)
{
    printf("fe=%i valor=%i izq=%i der=%i\n", p->fe, p->valor, p->izquierdo != NULL ? p->izquierdo->valor : 0,
           p->derecho != NULL ? p->derecho->valor : 0);
    if (p->izquierdo != NULL)
        despliega_nodo(p->izquierdo);
    if (p->derecho != NULL)
        despliega_nodo(p->derecho);
}

struct Nodo *busca_nodo(struct ArbolAVL *arbol, int valor)
{
    if (arbol)
    {
        //printferror("buscando nodo");
        struct Nodo *p = arbol->raiz;
        for (;;)
            if (valor < p->valor)
            {
                if (p->izquierdo == NULL)
                    break;
                else
                    p = p->izquierdo;
            }
            else if (valor > p->valor)
            {
                if (p->derecho == NULL)
                    break;
                else
                    p = p->derecho;
            }
            else
                return p;
        return NULL;
    }
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
    printf("\n");
    printf("Nombre: %s ", empleado->nombre);
    printf("\n");
    printf("Edad: %d , sueldo %f", empleado->edad, empleado->sueldo);
    printf("\n");
}

void buscarEmpleado(struct ArbolAVL *arbol)
{
    if (arbol)
    {
        int valor = 0;
        struct Nodo *nodo;
        printfln("Ingresa el id del empleado a buscar (tendra que ser exacto)");
        printf("id: ");
        scanf("%d", &valor);
        if (valor)
            nodo = busca_nodo(arbol, valor);
        if (nodo)
            imprimirEmpleado(nodo->empleado);
        else
            printferror("No se ha podido encontrar el empleado solicitado");
    }
    else
        printferror("El arbol de registros no ha sido iniciado");
}

void eliminarEmpleado(struct ArbolAVL *arbol)
{
    if (arbol)
    {
        int valor = -1;
        printfln("Ingresa el id del empleado a eliminar (tendra que ser exacto)");
        printf("id: ");
        scanf("%d", &valor);
        if (valor)
            valor = elimina_nodo(arbol, valor);
        if (valor == 0)
        {
            printfln("Se ha eliminado el empleado solicitado");
        }
        else
        {
            printferror("ha ocurrido un error al eliminar el empleado");
        }
    }
    else
        printferror("El arbol de registros no ha sido iniciado");
}

void registrarEmpleado(struct ArbolAVL *arbol)
{

    if (arbol)
    {
        struct Empleado *empleado;
        empleado = crearEmpleado("Juan", 18, 5000);

        char nombre[50];
        int edad;
        float salario;
        int numero;

        printfln("Ingresa el nombre del nuevo empleado:");
        scanf("%s", nombre);
        printf("Ingresa la edad de %s \n", nombre);
        scanf("%d", &edad);
        printf("Ingresa el salario de %s \n", nombre);
        scanf("%f", &salario);
        printf("Ingresa el numero de usuario de %s \n", nombre);
        scanf("%d", &numero);

        empleado = crearEmpleado(nombre, edad, salario);
        limpiar_pantalla();
        agrega_nodo(arbol, numero, empleado);
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

// int main(int argc, char const *argv[])
// {
//     struct ArbolAVL arbol;
//     inicializa_arbol(&arbol);

//     agrega_nodo(&arbol, 50);
//     agrega_nodo(&arbol, 30);
//     agrega_nodo(&arbol, 51);
//     agrega_nodo(&arbol, 11);
//     agrega_nodo(&arbol, 40);
//     agrega_nodo(&arbol, 25);
//     agrega_nodo(&arbol, 10);
//     agrega_nodo(&arbol, 20);
//     agrega_nodo(&arbol, 15);
//     agrega_nodo(&arbol, 18);
//     agrega_nodo(&arbol, 60);
//     agrega_nodo(&arbol, 70);
//     agrega_nodo(&arbol, 16);
//     agrega_nodo(&arbol, 5);
//     agrega_nodo(&arbol, 2);
//     agrega_nodo(&arbol, 45);
//     agrega_nodo(&arbol, 35);

//     elimina_nodo(&arbol, 30);
//     despliega_nodo(arbol.raiz);
//     printf("arbol iniciado\n");
//     struct Nodo *nodo = busca_nodo(&arbol, 100);

//     if (nodo)
//         printf("nodo encontrado: %d", nodo->valor);
//     else
//         printf("nodo no encontrado");
//     return 0;
// }
