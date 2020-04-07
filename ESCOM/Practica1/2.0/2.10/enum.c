#include <stdio.h>
enum dia_semana
{
    lunes,
    martes,
    miercoles,
    jueves,
    viernes,
    sabado,
    domingo
};
int main()
{
    enum dia_semana hoy = miercoles;
    switch (hoy)
    {
    case lunes:
        printf("Hoy es lunes\n");
        break;
    case martes:
        printf("Hoy es martes\n");
        break;
    case miercoles:
        printf("Hoy es miercoles\n");
        break;
    case jueves:
        printf("Hoy es jueves\n");
        break;
    case viernes:
        printf("Hoy es viernes\n");
        break;
    case sabado:
        printf("Hoy es sabado\n");
        break;
    case domingo:
        printf("Hoy es domingo\n");
        break;
    }
    for (int dia = lunes; dia <= domingo; dia++)
        printf("%i ", dia);
    printf("\n");
}