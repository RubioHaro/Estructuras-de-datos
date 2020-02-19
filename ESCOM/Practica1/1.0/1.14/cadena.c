#include <stdio.h>
#include <string.h>
int main()
{
    char s1[] = "abcdef";
    char s2[] = "ghijkl";
    printf("s1=%s s2=%s\n", s1, s2);
    strcpy(s1, s2);
    printf("s1=%s s2=%s\n", s1, s2);
}