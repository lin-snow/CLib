#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 清屏
    system("cls");
    int i,j,k,n;
    // 有一个乱序的数组，其中有n个数，n=10
    n=10;
    int arr[10] = {33,22,44,55,66,11,99,88,77,100};
    // 冒泡排序(从小到大)
    for (i=1;i<=n-1;i++)
        for (j=0;j<n-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    // 输出排序结果
    for(k=0;k<10;k++) printf("%2d ",arr[k]);
    //程序暂停运行
    system("pause");
    return 0;
}