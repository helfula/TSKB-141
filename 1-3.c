#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Вычисляет сопротивление провода
 * @param l - длина провода в метрах
 * @param s - площадь поперечного сечения провода в мм^2
 * @return Рассчитанное значение в омах
 */
double R(const double l, const double s);

/**
 * @brief Считывает с клавиатуры значение с плавающей точкой
 * @return Считанное значение
 */
double getDouble();

/**
 * @brief Считывает с клавиатуры положительное значение (строго больше 0)
 * @return Считанное значение
 */
double getPositive();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Введите длину провода l в метрах: ");
    double l = getPositive();
    printf("Введите площадь поперечного сечения S в мм^2: ");
    double s = getPositive();
    printf("Сопротивление провода: %lf Ом\n", R(l, s));
    return 0;
}

double R(const double l, const double s)
{
    /// Удельное сопротивление алюминия, Ом * мм^2 / м
    const double RHO_ALUMINIUM = 0.028;
    return RHO_ALUMINIUM * l / s;
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

double getPositive()
{
    double value = getDouble();
    if (value <= 0.0)
    {
        printf("Error: value must be greater than 0\n");
        exit(1);
    }
    return value;
}
