#include <stdio.h>
int main()
{
    float lista[3];
    lista[0] = 100.0;
    lista[1] = 250.0;
    lista[2] = 150.0;
    for (int i = 0; i < sizeof(lista) / sizeof(typeof(lista[0])); i++)
        printf("%f\n", lista[i]);
    printf("%i\n", sizeof(lista));
    printf("%i\n", sizeof(typeof(lista[0])));
    return 0;
}