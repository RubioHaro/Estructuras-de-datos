#include <string.h>
#include <stdio.h>

int main()
{
    char s[] = "1234567890";
    printf("%s\n", strchr(s, '5'));
    return 0;
}