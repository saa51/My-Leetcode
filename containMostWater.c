#define MAX(a,b) ((a>b)?a:b)

int maxArea(int* height, int heightSize) {
    int h = 0, max_area = 0;
    int left = 0, right = heightSize - 1;
    while (left < right) {
        while (height[left] < h && left < right) left++;
        while (height[right] < h && left < right) right--;
        max_area = MAX(max_area, h * (right - left));
        h++;
    }
    return max_area;
}
