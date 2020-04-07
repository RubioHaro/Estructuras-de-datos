#include <stdio.h>
int main()
{
    static int lista[3];
    for (int i = 0; i < sizeof(lista) / sizeof(typeof(lista[0])); i++)
        printf("%i\n", lista[i]);
    return 0;
}