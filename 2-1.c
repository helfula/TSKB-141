#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Варианты увеличения значения A
 */
enum IncreaseType
{
    INCREASE_N = 1,  ///< увеличить A в N раз
    INCREASE_2N = 2, ///< увеличить A в 2N раз
    INCREASE_3N = 3  ///< увеличить A в 3N раз
};

/**
 * @brief Увеличивает значение A в зависимости от выбранной формулы
 * @param a - исходное значение A
 * @param n - число N
 * @param type - выбранный вариант увеличения (в N, 2N или 3N раз)
 * @return Увеличенное значение A
 */
double increase(const double a, const double n, const enum IncreaseType type);

/**
 * @brief Считывает с клавиатуры конечное значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Считывает с клавиатуры положительное значение (строго больше 0)
 * @return Считанное значение
 */
double getPositive();

/**
 * @brief Считывает с клавиатуры номер формулы и проверяет его
 * @return Выбранный вариант увеличения
 */
enum IncreaseType getChoice();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Введите значение A: ");
    double a = getDouble();
    printf("Введите число N (N > 0): ");
    double n = getPositive();

    printf("Во сколько раз увеличить A?\n");
    printf("%d - в N раз\n", INCREASE_N);
    printf("%d - в 2N раз\n", INCREASE_2N);
    printf("%d - в 3N раз\n", INCREASE_3N);
    printf("Ваш выбор: ");
    enum IncreaseType type = getChoice();

    printf("\nA до увеличения: %lf\n", a);
    printf("N = %lf\n", n);
    a = increase(a, n, type);
    printf("A после увеличения: %lf\n", a);
    return 0;
}

double increase(const double a, const double n, const enum IncreaseType type)
{
    switch (type)
    {
        case INCREASE_N:
            return a * n;
        case INCREASE_2N:
            return a * 2 * n;
        case INCREASE_3N:
            return a * 3 * n;
        default:
            printf("Ошибка: неизвестная формула\n");
            exit(1);
    }
}

double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1 || !isfinite(value))
    {
        printf("Ошибка: нужно ввести конечное число\n");
        exit(1);
    }
    return value;
}

double getPositive()
{
    double value = getDouble();
    if (value <= 0.0)
    {
        printf("Ошибка: число должно быть больше 0\n");
        exit(1);
    }
    return value;
}

enum IncreaseType getChoice()
{
    int value = 0;
    if (scanf("%d", &value) != 1 || value < INCREASE_N || value > INCREASE_3N)
    {
        printf("Ошибка: нужно ввести %d, %d или %d\n", INCREASE_N, INCREASE_2N, INCREASE_3N);
        exit(1);
    }
    return (enum IncreaseType)value;
}
