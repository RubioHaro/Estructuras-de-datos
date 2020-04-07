#include <stdio.h>
struct coordenadas_gps
{
    float latitud;
    float longitud;
};
int main()
{
    struct coordenadas_gps p[] = {{19.432, -99.133},
                                  {19.420, -99.140},
                                  {19.410, -99.150}};
    for (int i = 0; i < sizeof(p) / sizeof(struct coordenadas_gps); i++)
        printf("%f,%f\n", p[i].latitud, p[i].longitud);
}