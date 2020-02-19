#include <stdio.h>
union entero_64_bits {
    long long n;
    unsigned char v[8];
};
int main()
{
    int i;
    union entero_64_bits x;
    x.n = 257;
    for (i = 0; i < 8; i++)
        printf("%i ", x.v[i]);
    printf("\n");
}