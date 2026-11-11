#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
 * @brief Вычисляет значение заданной функции 
 * @param x - аргумент функции
 * @return Рассчитанное значение
 */
double y(const double x);

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Проверяет, что x допустим(ОДЗ)
 * @param x - считанное значение x
 */
void checkX(const double x);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Введите x: ");
    double x = getDouble();
    checkX(x);
    printf("y is %lf\n", y(x));
    return 0;
}

double y(const double x)
{
    const double A = 1.5;
    const double ax = A * x;
    if (ax < 1)
    {
        return ax - log10(ax);
    }
    else
    {
        return ax + log10(ax);
    }
}

double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Error: enter a number\n");
        exit(1);
    }
    return value;
}

void checkX(const double x)
{
    if (x <= 0 || !isfinite(x))
    {
        printf("Error: x must be a finite number greater than 0\n");
        exit(1);
    }
}
