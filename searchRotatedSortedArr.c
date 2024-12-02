int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize;
    if (target == nums[0]) return 0;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (target > nums[0]) {
            if (nums[mid] < nums[0]) right = mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        else {
            if (nums[mid] > nums[0]) left = mid + 1;
            else if (nums[mid]> target) right = mid;
            else left = mid + 1;
        }
    }
    return -1;
}
