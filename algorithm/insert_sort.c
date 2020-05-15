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

void InsertSort(int *array, int width)
{
    int i, j;
    for(i = 1; i < width; i++) { //从第一个元素a[1]开始
        for(j = i; j > 0; j--) { //和它前面所有的元素一次比较，找到合适的位置插入
            if(array[j] < array[j-1]) {
                swap(&array[j], &array[j-1]);
            }
        }
    }
    return ;
}

int main(int argc, char *argv[])
{
    int array[6] = {-1,0,1,2,-1,-4};
    int width = sizeof(array)/sizeof(int);

    InsertSort(array, width);//数组名传参，数组首（元素）地址
    PrintArray(array, width);
    return 0;
}
