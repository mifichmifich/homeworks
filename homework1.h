#include <stdio.h>

int get_fac(int a)
{
    int res = 1;
    for (int step = 1; step <= a; step++)
    {
        res *= step;
    }
    return res;
}

int main()
{
    int how_many_nums;
    printf("Enter the count of numbers: ");
    scanf("%d", &how_many_nums);

    for (int step = 0; step < how_many_nums; step++)
    {
        int number = 0;
        printf("Enter the number: ");
        scanf("%d", &number);
        printf("The factorial of number is: %d\n", get_fac(number));
    }
    return 0;
}
