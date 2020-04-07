#include <stdio.h>
int main()
{
    int n = 3;
    int factorial = 1;
    for (int i = 1; i <= n; i++)
        factorial = factorial * i;
    printf("El factorial de %i es %i\n", n, factorial);
}