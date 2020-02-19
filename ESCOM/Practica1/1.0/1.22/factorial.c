#include <stdio.h>
int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
int main()
{
    int n = 3;
    printf("El factorial de %i es %i\n", n, factorial(n));
}