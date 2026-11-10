#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Вычисляет третью сторону треугольника
 * @param a - сторона треугольника
 * @param b - сторона треугольника
 * @param x - угол между сторонами a и b в градусах
 * @return Рассчитанное значение
 */
double C(const double a, const double b, const double x);

/**
 * @brief Вычисляет площадь треугольника
 * @param a - сторона треугольника
 * @param b - сторона треугольника
 * @param x - угол между сторонами a и b в градусах
 * @return Рассчитанное значение
 */
double S(const double a, const double b, const double x);

/**
 * @brief Вычисляет радиус описанной окружности треугольника
 * @param st - сторона треугольника, лежащая напротив угла x
 * @param x - угол, лежащий напротив стороны st, в градусах
 * @return Рассчитанное значение
 */
double R(const double st, const double x);

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Считывает с клавиатуры длину стороны (должна быть больше 0)
 * @return Считанное значение
 */
double getSide();

/**
 * @brief Считывает с клавиатуры угол в градусах (строго между 0 и 180)
 * @return Считанное значение
 */
double getAngle();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Введите сторону треугольника a: ");
    double a = getSide();
    printf("Введите сторону треугольника b: ");
    double b = getSide();
    printf("Введите угол между сторонами a и b в градусах: ");
    double x = getAngle();
    double st = C(a, b, x);
    printf("side is %lf\n", st);
    printf("square is %lf\n", S(a, b, x));
    printf("radius is %lf\n", R(st, x));
    return 0;
}

double C(const double a, const double b, const double x)
{
    return sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(x * M_PI / 180.0));
}

double S(const double a, const double b, const double x)
{
    return 0.5 * a * b * sin(x * M_PI / 180.0);
}

double R(const double st, const double x)
{
    return st / (2 * sin(x * M_PI / 180.0));
}

double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Error\n");
        exit(1);
    }
    return value;
}

double getSide()
{
    double value = getDouble();
    if (value <= 0.0)
    {
        printf("Error: side must be greater than 0\n");
        exit(1);
    }
    return value;
}

double getAngle()
{
    double value = getDouble();
    if (value <= 0.0 || value >= 180.0)
    {
        printf("Error: angle must be between 0 and 180 degrees\n");
        exit(1);
    }
    return value;
}
