#include <stdio.h>
struct Empleado
{
    struct
    {
        char *nombre;
        char *apellidos;
    } nombre_emp;
    int edad;
    struct
    {
        char *calle;
        char *colonia;
        char cp[5];
    } direccion;
    float sueldo;
};
int main()
{
    struct Empleado e = {{"Juan", "López"}, 30, {"Av. Revolución", "Central", "12345"}, 10000.0F};
    printf("%s %s %i %s %s %s %f\n", e.nombre_emp.nombre, e.nombre_emp.apellidos, e.edad, e.direccion.calle, e.direccion.colonia, e.direccion.cp, e.sueldo);
    return 0;
}