#include <string.h>
#define MAX(a,b) ((a>b)?a:b)

int longestValidParentheses(char* s) {
    int len = strlen(s);
    if (len == 0) return 0;
    int* max_valid_idx = (int*)malloc(sizeof(int) * len);
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == ')' || i == len - 1) max_valid_idx[i] = -1;
        else if (s[i + 1] == ')') {
            if (i + 2 == len || max_valid_idx[i + 2] == -1) max_valid_idx[i] = i + 2;
            else max_valid_idx[i] = max_valid_idx[i + 2];
        }
        else {
            if (max_valid_idx[i + 1] == len || max_valid_idx[i + 1] == -1 || s[max_valid_idx[i + 1]] == '(') max_valid_idx[i] = -1;
            else {
                max_valid_idx[i] = max_valid_idx[i + 1] + 1;
                if (max_valid_idx[i] < len && max_valid_idx[i] >= 0) 
                    max_valid_idx[i] = MAX(max_valid_idx[i], max_valid_idx[max_valid_idx[i]]);
            }
        }
    }
    int max_len = 0;
    for (int i = 0; i < len; i++) max_len = MAX(max_len, max_valid_idx[i] - i);
    free(max_valid_idx);
    return max_len;
}
