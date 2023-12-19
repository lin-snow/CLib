#include <stdio.h>
#include <stdlib.h>

int main()
{   
    /* 清屏 */
    system("cls");
    int number;
    printf("Please input a number: ");
    scanf("%d", &number);

    // Using Loop
    printf("%d using loop : %d", number,GetFactorialByLoop(number));
    // Using Recursion
    printf("\n%d using recursion : %d", number,GetFactorialByRecursion(number));
    // Using Static
    printf("\n%d Using static : %d", number,GetFactorialByStatic(number));
}
/* Get Factorial By Loop */
int GetFactorialByLoop(int n)
{
    int i ,result = 1;
    for (i = 1 ;i <= n; i++)
    {
        result *= i;
    }
    return result;
}

/* Get Factorial By Recursion */
int GetFactorialByRecursion(int n)
{
    if (n == 0)
    {
        return 1;
    }else {
        return (n * (GetFactorialByRecursion(n-1)));
    }
}

/* Get Factorial By Static */
int GetFactorialByStatic(int n)
{   
    static int static_result = 1;
    if (n > 1) {
        static_result *= n;
        GetFactorialByStatic(n - 1);
    }
    return static_result;
}