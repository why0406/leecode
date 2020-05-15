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
        for(j = 0; j < width-i-1; j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
    return ;
}

int main(int argc, char *argv[])
{
    int array[6] = {-1,0,1,2,-1,-4};
    int width = sizeof(array)/sizeof(int);

    BubbleSort(array, width);
    PrintArray(array, width);
    return 0;
}
