#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Увеличивает значение A в k*N раз
 * @param a - исходное значение A
 * @param n - число N
 * @param k - множитель при N (1, 2 или 3)
 * @return Увеличенное значение A
 */
double increase(const double a, const double n, const int k);


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
 * @brief Считывает с клавиатуры номер формулы (1, 2 или 3)
 * @return Считанное значение
 */
int getChoice();

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
    printf("1 - в N раз\n");
    printf("2 - в 2N раз\n");
    printf("3 - в 3N раз\n");
    printf("Ваш выбор: ");
    int k = getChoice();

    printf("\nA до увеличения: %lf\n", a);
    printf("N = %lf\n", n);
    printf("Множитель %d*N = %lf\n", k, k * n);
    a = increase(a, n, k);
    printf("A после увеличения: %lf\n", a);
    return 0;
}

double increase(const double a, const double n, const int k)
{
    return a * k * n;
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

int getChoice()
{
    int value = 0;
    if (scanf("%d", &value) != 1 || value < 1 || value > 3)
    {
        printf("Ошибка: нужно ввести 1, 2 или 3\n");
        exit(1);
    }
    return value;
}
