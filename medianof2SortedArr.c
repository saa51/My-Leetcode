// This algorithm of O(log^2(m+n))
// A better solution can be found in 
// https://blog.csdn.net/kduduuuw/article/details/134808026

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)

int smallerCount(int* arr, int len, int key) {
    int left = 0, right = len;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= key) right = mid;
        else left = mid + 1;
    }
    return right;
}

int largerCount(int* arr, int len, int key) {
    int left = 0, right = len;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > key) right = mid;
        else left = mid + 1;
    }
    return right;
}

int findKthSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    int* long_arr = (nums1Size > nums2Size) ? nums1 : nums2;
    int* short_arr = (nums1Size <= nums2Size) ? nums1 : nums2;
    int long_len = MAX(nums1Size, nums2Size), short_len = MIN(nums1Size, nums2Size);
    if (short_len == 0) return long_arr[k];
    int guess = long_arr[k * long_len / (long_len + short_len)];
    int short_small_cnt = smallerCount(short_arr, short_len, guess);
    int short_large_cnt = largerCount(short_arr, short_len, guess);
    int long_small_cnt = smallerCount(long_arr, long_len, guess);
    int long_large_cnt = largerCount(long_arr, long_len, guess);
    if (short_small_cnt + long_small_cnt <= k && short_large_cnt + long_large_cnt > k) 
        return guess;
    else if (short_small_cnt + long_small_cnt > k) 
        return findKthSortedArrays(long_arr, long_small_cnt, short_arr, short_small_cnt, k);
    else
        return findKthSortedArrays(long_arr + long_large_cnt, long_len - long_large_cnt, short_arr + short_large_cnt, short_len - short_large_cnt, k - long_large_cnt - short_large_cnt);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if ((nums1Size + nums2Size) % 2 == 1)
        return (double)findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2);
    else {
        double large = findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2);
        double small = findKthSortedArrays(nums1, nums1Size, nums2, nums2Size, (nums1Size + nums2Size) / 2 - 1);
        return (large + small) / 2;
    }
}