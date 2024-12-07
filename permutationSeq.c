char* getPermutation(int n, int k) {
    int factorial[10];
    int avail = 0xffffffff;
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) 
        factorial[i] = factorial[i - 1] * i;
    k -= 1;
    char* res = (char*)malloc(sizeof(char) * (n + 1));
    for(int i = 0; i < n; i++) {
        int idx = k / factorial[n - 1 - i];
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (cnt == idx && (avail & (1 << j))) {
                res[i] = '0' + j;
                avail &= ~(1 << j);
                break;
            }
            if ((avail & (1 << j))) cnt++;
        }
        k %= factorial[n - 1 - i];
    }
    res[n] = 0;
    return res;
}
