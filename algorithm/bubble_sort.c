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
    for(i = 0; i < width; i++) {
<<<<<<< 8724d5824f5127f2657e0b153becda3ee20338b6
        for(j = 0; j < width-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
=======
        for(j = 0; j < width-i-1; j++) { //注意内循环次数要减一，否则最长长度加一以后就溢出了
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]); //传递地址
>>>>>>> add bubble_sort.c
            }
        }
    }
    return ;
}

int main(int argc, char *argv[])
{
    int array[6] = {-1,0,1,2,-1,-4};
    int width = sizeof(array)/sizeof(int);

<<<<<<< 8724d5824f5127f2657e0b153becda3ee20338b6
    BubbleSort(array, width);
=======
    BubbleSort(array, width);//数组名传参，数组首（元素）地址
>>>>>>> add bubble_sort.c
    PrintArray(array, width);
    return 0;
}
