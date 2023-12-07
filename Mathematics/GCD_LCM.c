#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* 清屏 */
    system("cls");
    /* 函数声明 */
    int gcd(int x,int y);
    int lcm(int x,int y);
    int Recursion_gcd(int x,int y);
    int Recursion_lcm(int x,int y);
    /* 输入两个数，分别为x和y */
    int x,y;
    scanf("%d %d",&x,&y);
    /* 调用辗转相除法函数求最大公约数和最小公倍数 */
    printf("The Greatest common divisor is %d and Least common multiple is %d .\n",gcd(x,y),lcm(x,y));
    /* 调用递归函数去最大公约数和最小公倍数 */
    printf("The Greatest common divisor is %d and Least common multiple is %d .\n",Recursion_gcd(x,y),Recursion_lcm(x,y));
    /* 暂停程序，查看结果 */
    system("pause");
    /* 程序结束，返回0 */
    return 0;
}

/* 辗转相除法求最大公约数 */
int gcd(int x, int y) {
    /* x和y是输入的两个数 */

    /* 循环直到y为0时结束 */
    while (y != 0) { 
        int temp = x % y; /* 计算x除以y的余数 */
        x = y; /* 将y赋值给x */
        y = temp; /* 将temp 赋值给 y */
    }
    /* 返回 x ,即最大公约数 */
    return x;
}

/* 最小公倍数公式求最小公倍数 */
int lcm(int x,int y) {
    /* 返回由公式计算得出的最下公倍数 */
    return x * y / gcd(x,y);
}

/* 使用递归的方式求两个数的最大公约数 */
int Recursion_gcd(int x,int y) {
    if (y == 0) {
        return x;
    } else {
        return Recursion_gcd(y, x % y); 
    }
}

/* 最小公倍数公式求最小公倍数 */
int Recursion_lcm(int x,int y) {
    /* 返回由公式计算得出的最下公倍数 */
    return x * y / Recursion_gcd(x,y);
}