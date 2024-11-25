#include <math.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), compare);
    int closed = 0x3fffffff;
    for (int i = 0; i < numsSize - 2; i++) {
        int j = i + 1, k = numsSize - 1;
        int target_2 = target - nums[i];
        while (j < k) {
            closed = (abs(closed - target) < abs(nums[j] + nums[k] - target_2))? closed: nums[i] + nums[j] + nums[k];
            if (nums[j] + nums[k] < target_2) j++;
            else if (nums[j] + nums[k] > target_2) k--;
            else break;
        }
        if (closed == 0) break;
    }
    return closed;
}