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

void ShellSort(int *array, int width)
{
    int i, j;
    int flag = 0;
    int gap = 4;
    for(i = 0; i < width; i++) {
        for(j = 0; j < width-gap; j++) { //注意内循环次数要减一，否则最长长度加一以后就溢出了
            if(array[j] > array[j+gap]) {
                swap(&array[j], &array[j+gap]); //传递地址
            }
        }
        if(gap > 1)
            gap = gap / 2;
    }
    return ;
}

int main(int argc, char *argv[])
{
    int array[6] = {-1,0,1,2,-1,-4};
    int width = sizeof(array)/sizeof(int);

    ShellSort(array, width);//数组名传参，数组首（元素）地址
    PrintArray(array, width);
    return 0;
}
