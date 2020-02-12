#include <stdio.h>
#include <string.h>
int main()
{
    char s1[20] = "hola";
    char s2[20] = "mundo";
    strcat(s1, " ");
    strcat(s1, s2);
    printf("%s\n", s1);
}