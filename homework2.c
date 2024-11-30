#include <stdio.h>
#include <stdlib.h>
int bubble_sort(int *array, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return 0;
}

int input_data(int *parsel_count, int **parsel_mass_array, int *max_mass)
{
    // Считывание кол-ва посылок
    printf("Enter the count of parsels:\n");
    if (scanf("%d", parsel_count) != 1)
    {
        printf("error input");
        return 1;
    }

    if (*parsel_count <= 0)
    {
        printf("no parsels");
        return 2;
    }
  
    *parsel_mass_array = (int *)malloc(*parsel_count * sizeof(int)); // Выделяем массив весов посылок размером parsel_count * sizeof(int)
    // Считывание весов посылок

    for (int index = 0; index < *parsel_count; index++)
    {
        printf("Enter the weight of parsels:\n");
        if (scanf("%d", &((*parsel_mass_array)[index])) != 1 || (*parsel_mass_array)[index] < 0)
        {
            printf("error input, or mass cant be negative");
            return 1;
        }
    }

    // Считываем вместимость одного вагона
    printf("Enter the capacity of one vagon:\n");
    if (scanf("%d", max_mass) != 1 || max_mass < 0)
    {
        printf("error input, or mass cant be negative");
        return 1;
    }

    return 0;
}

int subtraction(int *vagons, int parsel_count, int *parsel_mass_array)
{
    // Реализуем вычитание
    /* В худшем случае у нас число вагонов = числу посылок.
    Соответственно, мы ввели массив для худшего случая.
    Дальше идем по отсортированным посылкам и пытаемся вычесть вес посылки из первого
    доступного для этого вагона. */
    for (int parsel_index = 0; parsel_index < parsel_count; parsel_index++)
    {
        for (int vagon_index = 0; vagon_index < parsel_count; vagon_index++)
        {
            // если можно вычесть по условию - то вычитаем(в теле условия)
            /* Пытаемся вычесть вес из первого ДОСТУПНОГО вагона
            (т.е. того, из которого результат разности больше или равен нуля) */
            if (vagons[vagon_index] - parsel_mass_array[parsel_index] >= 0) // если вместимость вагона - вес посылки >= 0
            {
                vagons[vagon_index] -= parsel_mass_array[parsel_index]; // то вычитаем из вагонов вес посылки
                break;                                                  // выходим из вложенного цикла
            }

            continue;
        }
    }
    return 0;
}

int main()
{
    int parsel_count = 0;
    int *parsel_mass_array = NULL;
    int max_mass = 0;
    int input_res = input_data(&parsel_count, &parsel_mass_array, &max_mass); // Готовую функцию необходимо присвоить в переменную

    // Выделим массив из вагонов
    // * ZeroMemory - https://learn.microsoft.com/ru-ru/previous-versions/windows/desktop/legacy/aa366920(v=vs.85)
    int *vagons = (int *)malloc(parsel_count * sizeof(int));

    for (int index = 0; index < parsel_count; index++)
    {
        vagons[index] = max_mass;
    }

    // Отсортируем массив посылок по убыванию

    if (bubble_sort(parsel_mass_array, parsel_count) != 0)
    {
        printf("No sort");
        free(parsel_mass_array);
        free(vagons);
        return 2;
    }
    int subtraction_res = subtraction(vagons, parsel_count, parsel_mass_array);
    // В итоге у нас будет цепочка из занятых вагонов в которые мы положили хотя бы одну посылку. Подсчитываем эти вагоны
    int vagon_count = 0;
    for (; (vagon_count < parsel_count) && (vagons[vagon_count] < max_mass); vagon_count++)
        ;
    // Выводим кол-во вагонов
    printf("The required number of vagons:\n");
    printf("%d", vagon_count);

    free(parsel_mass_array);
    free(vagons);
}
