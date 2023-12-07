#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* 清屏 */
    system("cls");
    /* 函数原型 */
    int isPrime(int n);
    int Enhanced_isPrime(int n);
    /* 定义一个变量x,x为需要进行判断的数 */
    int x;
    /* 输入你要判断的数值 */
    printf("Please input the number that need to be judged: ");
    scanf("%d",&x);

    /* 分别调用函数对x进行判断 */
    if (isPrime(x)) printf ("%d is a prime.\n",x);
    else printf("%d is not a prime.\n",x);

    if (Enhanced_isPrime(x)) printf("%d is a prime.\n",x);
    else printf("%d is not a prime.\n",x);

    /* 暂停程序查看结果 */
    system("pause");
    /* 程序结束 */
    return 0;
}

// 未经过优化的素数判断函数
int isPrime(int n)
{
    /* 判断输入的数是否小于或等于 1，如果是，则不是素数 */
    if (n <= 1) {
        return 0;
    }

    /* 从2开始，逐个检查输入的数是否可以被 2 到 n 之间的任何整数整除 */
    for (int i = 2;i * i <= n; i++) {
        // 如果可以被整除，则不是素数，直接返回0
        if (n % i == 0) {
            // 返回0
            return 0;
        }
    }
    
    /* 如果输入的数不能被任何整数整除，则是素数，返回 1 */
    return 1;
}

// 因为偶数都不是素数，可以先排除掉，这样可以将判断次数减少一半
int Enhanced_isPrime(int n)
{
    /* 判断输入的数是否小于或等于 1,如果是，则不是素数 */
    if (n <= 1) {
        return 0;
    }

    /* 判断输入的数是否是偶数，如果是，则不是素数 */
    if (n % 2 == 0) return 0;

    /* 从3开始，逐个检查输入的数是否可以被3 到 n之间的奇数整除 */
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    /* 该数为素数，返回 1 */
    return 1;
}