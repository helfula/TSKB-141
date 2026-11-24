#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
 * @brief Выводит приглашение и считывает с клавиатуры целое число
 * @param message - текст приглашения к вводу
 * @return Считанное значение
 */
int getInt(const char* message);
/**
 * @brief Выводит приглашение и считывает с клавиатуры значение с плавающей точкой
 * @param message - текст приглашения к вводу
 * @return Считанное значение
 */
double getValue(const char* message);
/**
 * @brief Проверяет, что количество членов последовательности положительно.
 * @param n - количество членов последовательности
 */
void checkPositive(const int n);
/**
 * @brief Проверяет, что точность e больше DBL_EPSILON
 * @param e - точность, с которой отбираются члены последовательности
 */
void checkEpsilon(const double e);
/**
 * @brief Вычисляет сумму первых n членов последовательности
 * @param n - количество суммируемых членов (n > 0)
 * @return Рассчитанное значение суммы
 */
double sumN(const int n);
/**
 * @brief Вычисляет сумму всех членов последовательности, по модулю не меньших e
 * @param e - заданное число, с которым сравниваются модули членов (e > 0)
 * @return Рассчитанное значение суммы
 */
double sumE(const double e);
/**
 * @brief Вычисляет рекуррентный коэффициент
 * @param k - номер текущего члена последовательности (k >= 1)
 * @return Рассчитанное значение коэффициента
 */
double getCoef(const int k);
/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    int n = getInt("Enter n: ");
    checkPositive(n);
    double e = getValue("Enter e: ");
    checkEpsilon(e);
    printf("Sum of first %d elements is: %lf\n", n, sumN(n));
    printf("Sum of elements with abs value not less than %lf is: %lf\n", e, sumE(e));
    return 0;
}

int getInt(const char* message)
{
    if (message != NULL)
    {
        printf("%s\n", message);
    }
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Input error");
        exit(1);
    }
    return value;
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

void checkPositive(const int n)
{
    if (n <= 0)
    {
        printf("Error, n have to be positive\n");
        exit(1);
    }
}

void checkEpsilon(const double e)
{
    if (e <= DBL_EPSILON)
    {
        printf("Error, e have to be greater than %g\n", DBL_EPSILON);
        exit(1);
    }
}

double sumN(const int n)
{
    double a = -1.0 / 2;
    double result = 0;
    for (int k = 1; k <= n; k++)
    {
        result += a;
        a *= getCoef(k);
    }
    return result;
}

double sumE(const double e)
{
    double a = -1.0 / 2;
    double result = 0;
    for (int k = 1; fabs(a) >= e - DBL_EPSILON; k++)
    {
        result += a;
        a *= getCoef(k);
    }
    return result;
}

double getCoef(const int k)
{
    return -(k + 1.0) / (k * (k + 2.0));
}
