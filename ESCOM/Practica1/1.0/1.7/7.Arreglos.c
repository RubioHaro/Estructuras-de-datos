#include <stdio.h>
int main()
{
    int a[3][4] = {{1, 2, 3, 4}, {7, 6, 5, 2}, {6, 3, 7, 8}};
    int b[4][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    int c[3][2];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 4; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            printf("c[%i,%i]=%i\n", i, j, c[i][j]);
    return 0;
}