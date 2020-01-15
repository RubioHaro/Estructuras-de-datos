#include <stdio.h>
#include "lista.c"
#include "libro.c"

int main(int argc, char const *argv[])
{
    printf("Programa iniciado \n");

    Lista* biblioteca;
    Libro* libro1;
    Libro* libro2;

    // *libro1->autor = "Rodrigo Rubio Haro";
    // *libro1->titulo = "Estructuras de datos";
    // *libro1->isbn = "9780143440314";

    libro1 = crearLibro("Estructuras de datos", "Rodrigo Rubio Haro", "9780143440314");
    libro2 = crearLibro("Programación Orientada a Objetos", "Rodrigo Rubio Haro", "9788429772456");
    printLibro(libro1);
    printLibro(libro2);

    biblioteca = crearLista("Rodrigo R. Rubio Haro");

    InsertarPrincipio(biblioteca,libro1);
    InsertarPrincipio(biblioteca,libro2);

    printLibro(Obtener(0, biblioteca));
    printLibro(Obtener(1, biblioteca));
    printf("Biblioteca de %s \n", biblioteca->propietario);

    return 0;
}
