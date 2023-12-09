#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* 清屏 */
    system("cls");
    /* 函数原型 */
    void SelectionSort(int * arr,int n);
    /* 定义一个数组 */
    int arr[] = {1, 5, 3, 2, 4};

    /* 打印原始数组 */
    printf("Original Array: \n");
    for (int i = 0;i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    /* 调用选择排序函数 */
    SelectionSort(arr, 5);

    /* 打印排序后的数组 */
    printf("After Selection Sort: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* 暂停程序，查看结果 */
    system("pause");
    return 0;
}

/* 函数定义 */
void SelectionSort(int * arr,int n)
{
    /* arr为传入的需要进行排序的数组地址，n为该数组的长度 */
    /* 循环 n-1 次，每次将最小元素放在未排序序列的第一个位置 */
    for(int i = 0;i < n-1;i++) {
        /* 初始化最小元素的索引 */
        int minIndex = i;

        /* 从 i+1 开始遍历未排序序列，找到最小元素 */
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        /* 将最小元素与未排序序列的第一个元素交换位置 */
        if (i != minIndex) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}