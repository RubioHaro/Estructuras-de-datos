
#include <stdio.h>
#include <string.h>
int main()
{
    char s1[] = "abcDEfg";
    char s2[] = "abcDefg";
    printf("%i\n", strcmp(s1, s2));
}