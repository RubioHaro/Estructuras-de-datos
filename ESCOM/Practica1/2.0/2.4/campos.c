#include <stdio.h>
struct coordenadas_gps
{
    float latitud = 0;  // error, no se puede inicializar el campo aquí
    float longitud = 0; // error, no se puede inicializar el campo aquí
};
int main()
{
    struct coordenadas_gps p;
    printf("%f,%f\n", p.latitud, p.longitud);
}