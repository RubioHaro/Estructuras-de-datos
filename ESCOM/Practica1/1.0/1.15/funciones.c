#include <stdio.h>
int main(int argc, char *argv[])
{
    int i;
    printf("Número de argumentos: %i\n", argc);
    for (i = 0; i < argc; i++)
        printf("%s\n", argv[i]);
    return 0;
}