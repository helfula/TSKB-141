#include <stdio.h>
#include <math.h>

double A(const double x, const double y, const double z);

/**
 * @brief вычисляет значение функции по заданной формуле
 * @param x - значение переменной х
 * @param y - значение переменной y
 * @param z - значение переменной z
 * @return рассчитанное значение
 */
double B(const double x, const double y, const double z);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    const double x =0.5;
    const double y = 0.05;
    const double z =0.7;
    printf("A = %lf\n",A(x,y,z));
    printf("B = %lf",B(x,y,z));

    return 0;
}

double A(const double x, const double y, const double z)
{
    return (pow(x,2)*(x+1))/(y-pow(sin(x+z),2));
}

double B(const double x, const double y, const double z)
{
    return sqrt(x*y/z)+pow(cos((x+y)*(x+y)),2);
}
