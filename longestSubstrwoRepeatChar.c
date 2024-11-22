#include<string.h>
#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int* max_lens = (int*)malloc(sizeof(int) * len);
    for (int i = 0; s[i]; i++) {
        max_lens[i] = i + 1;
        for (int j = i - 1; j >= 0; j--) {
            if (i - j >= max_lens[i]) break;
            if (s[i] != s[j]) max_lens[i] = MIN(max_lens[i], max_lens[j] + i - j);
            else {
                max_lens[i] = i - j;
                break;
            }
        }
    }

    int max_length = 0;
    for(int i = 0; i < len; i++) max_length = MAX(max_length, max_lens[i]);
    return max_length;
}
