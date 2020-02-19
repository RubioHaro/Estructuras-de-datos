#include <stdio.h>
int main()
{
    struct
    {
        float latitud;
        float longitud;
    } p;
    p.latitud = 19.4326018;
    p.longitud = -99.1332049;
    printf("%f,%f\n", p.latitud, p.longitud);
    return 0;
}