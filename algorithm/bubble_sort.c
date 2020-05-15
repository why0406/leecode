#include <stdio.h>

void PrintArray(int *array, int width)
{
    int i;
    for(i = 0; i < width; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void BubbleSort(int *array, int width)
{
    int i, j;
    int flag = 0;
    for(i = 0; i < width; i++) {
        flag = 0;
        for(j = 0; j < width-i-1; j++) { //注意内循环次数要减一，否则最长长度加一以后就溢出了
            flag = 0;
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]); //传递地址
                flag = 1;
            }
        }
        if(flag == 0) //添加排序完成标志位
            break;
    }
    return ;
}

int main(int argc, char *argv[])
{
    int array[6] = {-1,0,1,2,-1,-4};
    int width = sizeof(array)/sizeof(int);

    BubbleSort(array, width);//数组名传参，数组首（元素）地址
    PrintArray(array, width);
    return 0;
}
