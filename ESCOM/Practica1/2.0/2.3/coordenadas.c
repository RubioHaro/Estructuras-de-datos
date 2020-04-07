#include <stdio.h>
struct coordenadas_gps
{
    float latitud;
    float longitud;
} p;
int main()
{
    p.latitud = 19.4326018;
    p.longitud = -99.1332049;
    printf("%f,%f\n", p.latitud, p.longitud);
}