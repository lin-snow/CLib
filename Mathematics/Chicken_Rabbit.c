#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* 清屏 */
    system("cls");
    /* 函数原型 */
    void calculateChickenRabbit(int totalAnimals, int totalLegs);
    /* 鸡和兔子的总数，腿的总数 */
    int totalAnimals, totalLegs;
    /* 输入鸡和兔子的总数 */
    printf("Enter the total number of animals: ");
    scanf("%d",&totalAnimals);

    /* 输入腿的腿的总数 */
    printf("\nEnter the total number of legs: ");
    scanf("%d", &totalLegs);
    /* 调用函数计算鸡和兔子的数量 */
    calculateChickenRabbit(totalAnimals, totalLegs);
    /* 暂停程序，查看结果 */
    system("pause");
    /* 程序结束，返回0 */
    return 0;
}

void calculateChickenRabbit(int totalAnimals, int totalLegs)
{
    /* 定义变量，鸡的数量和兔子的数量 */
    int numChickens, numRabbits;
    /* 计算兔子的数量 */
    numRabbits = (totalLegs - 2 * totalAnimals) / 2;

    /* 计算鸡的数量 */
    numChickens = totalAnimals - numRabbits;

    /* 检查是否有效 */
    if (numChickens >= 0 && numRabbits >= 0 && (2 * numChickens + 4 * numRabbits == totalLegs)) {
        /* 输出结果 */
        printf("Number of chickens: %d\n", numChickens);
        printf("Number of rabbits: %d\n", numRabbits);
    } else {
        /* 输出错误信息 */
        printf("Invalid input. No solution found.\n");
    }
}

