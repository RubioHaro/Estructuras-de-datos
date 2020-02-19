#include <stdio.h>
struct coordenadas_gps
{
    float latitud;
    float longitud;
};
int main()
{
    struct coordenadas_gps p = {0, 0};
    printf("%f,%f\n", p.latitud, p.longitud);
    return 0;
}