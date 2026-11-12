#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/**
 * @brief Определяет, является ли положительной сумма каких-либо из трёх чисел
 * @param a - первое число
 * @param b - второе число
 * @param c - третье число
 * @return true, если хотя бы одна из таких сумм больше 0, иначе false
 */
bool hasPositiveSum(const double a, const double b, const double c);

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Проверяет, что введено конечное число
 * @param value - считанное значение
 */
void checkNumber(const double value);

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Enter a: ");
    double a = getDouble();
    checkNumber(a);
    printf("Enter b: ");
    double b = getDouble();
    checkNumber(b);
    printf("Enter c: ");
    double c = getDouble();
    checkNumber(c);

    printf("a + b is %lf\n", a + b);
    printf("a + c is %lf\n", a + c);
    printf("b + c is %lf\n", b + c);
    printf("a + b + c is %lf\n", a + b + c);

    if (hasPositiveSum(a, b, c))
    {
        printf("Yes, there is a positive sum\n");
    }
    else
    {
        printf("No, there is no positive sum\n");
    }
    return 0;
}

bool hasPositiveSum(const double a, const double b, const double c)
{
    return (a + b) > 0 || (a + c) > 0 || (b + c) > 0 || (a + b + c) > 0;
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

void checkNumber(const double value)
{
    if (!isfinite(value))
    {
        printf("Error: enter a finite number\n");
        exit(1);
    }
}
