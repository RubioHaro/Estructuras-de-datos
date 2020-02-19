#include <stdio.h>
int main()
{
    union {
        struct
        {
            int a : 3;
            int b : 3;
            int c : 2;
        } x;
        unsigned char y;
    } z;
    z.x.a = 6;
    z.x.b = 5;
    z.x.c = 2;
    printf("%i\n", z.y); // despliega 174 (en binario: 10101110)
}