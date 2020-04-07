#include <stdio.h>
#define N 10000000
int main()
{
    static int m[N];
    for (int i = 0; i < N; i++)
        m[i] = 0;
    printf("exito\n");
    return 0;
}