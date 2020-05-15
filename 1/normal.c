#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int main(int argc, char *argv[])
{
	int nums1[5] = {-1,-2,-3,-4,-5};
    int target1 = -8;

	int nums2[5] = {1,2,3,4,5};
    int target2 = 8;

    int returnSize = 0;
    int *rc;

	rc = twoSum(nums1, sizeof(nums1), target1, &returnSize);
	if(rc != NULL)
	{
		printf("returnSize=%d, rc[0]=%d, rc[1]=%d\n\n", returnSize, rc[0], rc[1]);
		free(rc);
	}
	else
		printf("return NULL.\n");

    returnSize = 0;
	rc = twoSum(nums2, sizeof(nums2), target2, &returnSize);
	if(rc != NULL)
	{
		printf("returnSize=%d, rc[0]=%d, rc[1]=%d\n\n", returnSize, rc[0], rc[1]);
		free(rc);
	}
	else
		printf("return NULL.\n");
	return 0;
	
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i,j;
    int *renums = (int *)malloc(sizeof(int) * 2);
	//for(i = 0; i < numsSize; i++) 没有考虑好临界条件
    for(i = 0; i < numsSize-1; i++)
    {
        //if(nums[i] <= target) 没有考虑负值的情况
        {
            for(j = i+1; j < numsSize; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    renums[0] = i;
                    renums[1] = j;
                    *returnSize = 2;
					printf("num[%d]=%d, num[%d]=%d, target=%d\n", i, nums[i], j, nums[j], target);
                    return renums;
                }
            }
        }
    }
    return NULL;
}
