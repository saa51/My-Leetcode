/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    char*** res = (char***)malloc(sizeof(char**) * n * n * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n * n * n);
    int row = 0, pos[9];
    for (int i = 0; i < 9; i++) pos[i] = 0;
    unsigned int mask = (1 << (n * 3)) - 1;
    unsigned int col = mask, l_diag = mask, r_diag = mask;
    while (pos[0] != n) {
        if (row == n) {
            res[*returnSize] = (char**)malloc(sizeof(char*) * n);
            for (int i = 0; i < n; i++) {
                res[*returnSize][i] = (char*)malloc(sizeof(char) * (n + 1));
                for (int j = 0; j < n; j++) res[*returnSize][i][j] = (pos[i] == j)?'Q':'.';
                res[*returnSize][i][n] = 0;
            }
            (*returnColumnSizes)[(*returnSize)++] = n;

            unsigned int bit = 1 << (pos[row - 1] + n);
            col |= bit;
            l_diag = (l_diag << 1) | 1;
            r_diag = (r_diag >> 1) |  (1 << (3 * n - 1));
            l_diag |= bit;
            r_diag |= bit;
            pos[--row]++;
        }
        else if (pos[row] == n) {
            unsigned int bit = 1 << (pos[row - 1] + n);
            col |= bit;
            l_diag = (l_diag << 1) | 1;
            r_diag = (r_diag >> 1) |  (1 << (3 * n - 1));
            l_diag |= bit;
            r_diag |= bit;
            pos[row] = 0;
            pos[--row]++;
        }
        else {
            unsigned int bit = (1 << (pos[row] + n));
            if ((bit & col) && (bit & l_diag) && (bit & r_diag)) {
                // next row
                col &= ~bit;
                l_diag &= ~bit;
                r_diag &= ~bit;
                l_diag = (l_diag >> 1) | (1 << (3 * n - 1));
                r_diag = (r_diag << 1) | 1;
                row++;
            }
            else pos[row]++;
        }
    }
    return res;
}
