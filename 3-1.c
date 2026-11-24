#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/**
 * @brief Выводит приглашение и считывает с клавиатуры значение с плавающей точкой.
 * @param message - текст приглашения к вводу
 * @return Считанное значение
 */
double getValue(const char* message);
/**
 * @brief Проверяет, что шаг табулирования положительный.
 * @param step - шаг табулирования
 */
void checkStep(const double step);
/**
 * @brief Проверяет корректность отрезка
 * @param xbegin - начало отрезка
 * @param xend - конец отрезка
 */
void checkSegment(const double xbegin, const double xend);
/**
 * @brief Проверяет, определена ли функция в точке x
 * @param x - значение аргумента функции
 * @return true, если функция определена в точке x, иначе false
 */
bool isDefined(const double x);
/**
 * @brief Вычисляет значение функции
 * @param x - значение аргумента функции 
 * @return Рассчитанное значение функции
 */
double getY(const double x);
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    double xbegin = getValue("Enter segment start: ");
    double xend = getValue("Enter segment end: ");
    double step = getValue("Enter step: ");
    checkStep(step);
    checkSegment(xbegin, xend);
    
    int n = (int)floor((xend - xbegin) / step);

    for (int i = 0; i <= n; i++)
    {
        double x = xbegin + i * step;
        if (isDefined(x))
        {
            printf("x = %lf, y = %lf\n", x, getY(x));
        }
        else
        {
            printf("x = %lf, y is not defined\n", x);
        }
    }
    return 0;
}

double getValue(const char* message)
{
    if (message != NULL)
    {
        printf("%s\n", message);
    }
    double value = 0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Input error");
        exit(1);
    }
    return value;
}

void checkStep(const double step)
{
    if (step <= 0)
    {
        printf("Error, step have to be positive");
        exit(1);
    }
}

void checkSegment(const double xbegin, const double xend)
{
    if (xbegin > xend)
    {
        printf("Error, segment begin have to be less or equal segment end");
        exit(1);
    }
}

bool isDefined(const double x)
{
    return (1 - x) >= -FLT_EPSILON;
}

double getY(const double x)
{
    double t = sqrt(1 - x);
    return t - cos(t);
}
