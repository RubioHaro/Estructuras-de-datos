#include <stdio.h>
int main()
{
    char s[] = "hola";
    printf("%s\n", s);
    for (int i = 0; i < 5; i++)
        printf("%c %i\n", s[i], s[i]);
}