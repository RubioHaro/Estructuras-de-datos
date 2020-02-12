#include <stdio.h>
struct vector
{
    double x;
    double y;
};
struct vector suma(struct vector a, struct vector b)
{
    struct vector r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    return r;
}
struct vector resta(struct vector a, struct vector b)
{
    struct vector r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

double producto_escalar(struct vector a, struct vector b)
{
    return a.x * b.x + a.y * b.y;
}
int main()
{
    struct vector a = {10.0, 20.0};
    struct vector b = {30.0, 40.0};
    struct vector c;

    c = suma(a, b);
    printf("suma: %f,%f\n", c.x, c.y);
    c = resta(a, b);
    printf("resta: %f,%f\n", c.x, c.y);
    printf("producto escalar: %f\n", producto_escalar(a, b));
}