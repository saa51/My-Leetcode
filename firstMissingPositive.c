inline void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] <= numsSize && nums[i] >= 1 && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) 
            swap(nums, i, nums[i] - 1);
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != i + 1) return i + 1;
    }
    return numsSize + 1;
}
