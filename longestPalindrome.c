// This DP-based algorithm is O(n^2)
// string Hash can reduce it to O(nlogn)
// Manacher algorithm O(n)
// https://blog.csdn.net/qq_43851311/article/details/113928303
// https://cp-algorithms.com/string/manacher.html

#include<string.h>

char* longestPalindrome(char* s) {
    int len = strlen(s);
    char* isPalindrome = (char*)malloc(sizeof(char) * len * (len + 1));
    for (int i = 0; i < len; i++) {
        isPalindrome[i * (len + 1)] = 1;
        isPalindrome[i * (len + 1) + 1] = 1;
    }
    for (int j = 2; j <= len; j++)
        for (int i = 0; i <= len - j; i++) {
            isPalindrome[i * (len + 1) + j] = (char)(s[i] == s[i + j - 1]) & isPalindrome[(i + 1) * (len + 1) + j - 2];
        }

    char* res = NULL;
    for (int j = len; j > 0; j--)
        for (int i = 0; i <= len - j; i++) {
            if (isPalindrome[i * (len + 1) + j]) {
                res = (char*)malloc(sizeof(char) * (j + 1));
                strncpy(res, &s[i], j);
                res[j] = 0;
                free(isPalindrome);
                return res;
            }
        }
    free(isPalindrome);
    return res;
}