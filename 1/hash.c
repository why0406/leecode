#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _hash_data{
    int value;
    int pos;
    struct _hash_data *next;
}HashData;

typedef struct _hash_table{
    HashData **data;
    int hashWidth;
}HashTable;

int hashInit(HashTable *table, int width)
{
    if(width <= 0)
        return -1;
    HashData **tmp = (HashData **)malloc(sizeof(HashData *) * width);
    if(tmp == NULL)
        return -1;
    
    memset(tmp, 0, sizeof(HashData *) * width);
    table->data = tmp;
    table->hashWidth = width;
    return 0;
}
int hashAddr(HashTable *table, int key)
{
    int addr = abs(key) % table->hashWidth;
    return addr;
}

HashData* hashFind(HashTable *table, int findValue)
{
    if(table == NULL)
        return NULL;
    int addr = hashAddr(table, findValue);
    //遍历数组的某个元素上的链表
    HashData *tmpHead = table->data[addr];
    while(tmpHead != NULL) {
        if(tmpHead->value == findValue) {
            return tmpHead;
        }
        tmpHead = tmpHead->next;
    }
    return NULL;
}

void hashInsert(HashTable *table, int insertValue, int pos)
{
    HashData *tmpData = (HashData *)malloc(sizeof(HashData));
    if(tmpData == NULL)
        return ;
    tmpData->value = insertValue;
    tmpData->pos = pos;
    tmpData->next = NULL;
    
    int addr = hashAddr(table, insertValue);
    HashData *tmpHead =  table->data[addr];
#if 1
    if(tmpHead == NULL) {
        table->data[addr] = tmpData;
    } else {
        tmpData->next = tmpHead;
        table->data[addr] = tmpData;
    }
#else
    if(tmpHead == NULL) {
        tmpHead = tmpData;
    } else {
        tmpData->next = tmpHead;
        tmpHead = tmpData;
    }
#endif
}

void hashFree(HashTable *table)
{
	int i;
	if(table != NULL){
		for(i = 0; i < table->hashWidth; i++) {
			HashData *tmphead = table->data[i];
			while(tmphead != NULL) {
				HashData *tmp = tmphead->next;
				free(tmphead);
				tmphead = tmp;
			}
		}
	}
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int findValue;
    int* resNums = (int *)malloc(sizeof(int) * 2);

    HashTable table;
    hashInit(&table, numsSize);

    for(i = 0; i < numsSize; i++) {
#if 0
        if(nums[i] == target) //可以存在有0的情况，例如8+0=8
            return NULL;
#endif

        findValue = target - nums[i];
        HashData *res = hashFind(&table, findValue);
        if(res != NULL) {
            resNums[0] = i;
            resNums[1] = res->pos;
            *returnSize = 2;
            break;
        }
        hashInsert(&table, nums[i], i);
    }
	hashFree(&table);
    return resNums;
}
int main(int argc, char *argv[])
{
	int nums[5] = {-1, -2, -3, -4, -5};
	int returnSize = 0;
	int target = -8;
	int *rc = NULL;

	rc = twoSum(nums, sizeof(nums)/sizeof(int), target, &returnSize);
	if(rc != NULL) {
		free(rc);
		printf("nums[%d] + num[%d] = %d\n", rc[0], rc[1], target);
	}
	return 0;
}
