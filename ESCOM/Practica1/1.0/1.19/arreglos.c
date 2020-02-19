#include <stdio.h>
void f(int v[])
{
    v[5] = 100;
}
int main()
{
    int a[10];
    f(a);
    printf("%i\n", a[5]);
    return 0;
}