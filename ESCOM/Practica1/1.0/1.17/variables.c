#include <stdio.h>
int main()
{
    int x = 10;
    {
        int x = 20;
        int y = 100;
        {
            int z = 200;
            printf("x=%i\n", x);
            printf("y=%i\n", y);
            printf("z=%i\n", z);
        }
    }
}