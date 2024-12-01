inline void reverse(int* nums, int start, int end) {
    int i = start, j = end - 1;
    while (i < j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    if (numsSize <= 1) return;
    int start = numsSize - 2;
    while (start >= 0) {
        if (nums[start] < nums[start + 1]) break;
        start--;
    }
    if (start == -1) {
        reverse(nums, 0, numsSize);
        return;
    }
    int next_start = numsSize - 1;
    while (next_start >= 0) {
        if (nums[start] < nums[next_start]) break;
        next_start--;
    }
}