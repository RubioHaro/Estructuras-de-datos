#include <stdio.h>
void f(int m[][2])
{
    m[0][0] = 100;
}
int main()
{
    int b[10][2];
    f(b);
    printf("%i\n", b[0][0]);
}