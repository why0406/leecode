#include <stdio.h>
void PrintArray(int *array, int width)
{
	int i;
	for(i = 0; i < width; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
void SelectSort(int *array, int width)
{
	int i, j;
	int minIndex;
	int temp;
	for(i = 0; i < width; i++) {
		minIndex = i;
		for(j = i+1; j < width; j++) {
			if(array[minIndex] > array[j]) {
				minIndex = j;
			}
		}
		temp = array[minIndex];
		array[minIndex] = array[i];
		array[i] = temp;
		PrintArray(array, width);
	}	
}
int main(int argc, char *argv[])
{
	int array[5] = {7, 8, 9, 10, 6};
	SelectSort(array, sizeof(array)/sizeof(int));
	PrintArray(array, sizeof(array)/sizeof(int));
	return 0;
}
