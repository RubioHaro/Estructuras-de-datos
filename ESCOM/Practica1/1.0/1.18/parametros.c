#include <stdio.h>
int suma(int a, int b);
int main()
{
    int s = suma(10, 20 + 30 - 10);
    int x = 1;
    int y = 2;
    printf("%i\n", s);
    printf("%i\n", suma(x, y));
    printf("%i\n", suma(1, 2));
    suma(100, 200);
}
int suma(int a, int b)
{
    int c = a + b;
    return c;
}