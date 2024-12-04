#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)

int trap(int* height, int heightSize) {
    int* left_highest = (int*)malloc(sizeof(int) * heightSize);
    int* right_highest = (int*)malloc(sizeof(int)* heightSize);
    left_highest[0] = 0;
    right_highest[heightSize - 1] = 0;
    for (int i = 1; i < heightSize; i++) {
        left_highest[i] = MAX(height[i - 1], left_highest[i - 1]);
        right_highest[heightSize - 1 - i] = MAX(height[heightSize - i], right_highest[heightSize - i]);
    }
    int area = 0;
    for (int i = 0; i < heightSize; i++) area += MAX(0, MIN(left_highest[i], right_highest[i]) - height[i]);
    free(left_highest);
    free(right_highest);
    return area;
}
