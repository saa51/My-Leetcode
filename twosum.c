/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

typedef struct Tuple{
    int index;
    int value;
}Tuple;

int compare(const void* a, const void* b) {
    return ((Tuple *)a)->value - ((Tuple *)b)->value;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Tuple* arr = (Tuple*) malloc(sizeof(Tuple) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        arr[i].index = i;
        arr[i].value = nums[i];
    }
    qsort(arr, numsSize, sizeof(struct Tuple), compare);
    int i = 0, j = numsSize - 1;
    while (i < j) {
        if (arr[i].value + arr[j].value > target) j--;
        else if (arr[i].value + arr[j].value < target) i++;
        else if (arr[i].value + arr[j].value == target) break;
    }
   int* res = (int*)malloc(sizeof(int) * 2);
   i = arr[i].index;
   j = arr[j].index;
   free(arr);
   res[0] = (i < j) ? i : j;
   res[1] = (i > j) ? i : j;
   *returnSize = 2;
   return res;
}
