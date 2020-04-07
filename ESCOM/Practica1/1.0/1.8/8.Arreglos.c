#include <stdio.h>
int main()
{
    char s[5];
    s[0] = 'h';
    s[1] = 'o';
    s[2] = 'l';
    s[3] = 'a';
    s[4] = 0; // fin de cadena
    printf("%s\n", s);
    for (int i = 0; i < 5; i++)
        printf("%c %i\n", s[i], s[i]);
}