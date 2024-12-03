/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXVAL 40
#define STACKDEPTH 80
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    bool isComb[30][42];
    memset(isComb, sizeof(bool) * 30 * 42, 0);
    for (int i = 0; i < candidatesSize; i++) {
        for (int v = 0; v <= MAXVAL; v++) {
            if (v == 0 || (i > 0 && isComb[i - 1][v]))
                for (int s = v; s <= MAXVAL; s += candidates[i]) isComb[i][s] = true;
        }
    }
    *returnSize = 0;
    if (!isComb[candidatesSize - 1][target]) 
        return NULL;
    int** res = (int**)malloc(sizeof(int*) * 150);
    memset(res, sizeof(int*) * 150, 0);
    int buffer[40];
    int stack_i[STACKDEPTH], stack_tar[STACKDEPTH], status[STACKDEPTH];
    int num = 0, pointer = 0;
    int curr_target = target, curr_i = candidatesSize - 1, curr_status = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 150);
    while (true) {
        if (curr_target == 0) {
            (*returnColumnSizes)[*returnSize] = num;
            res[*returnSize] = malloc(sizeof(int) * num);
            for (int i = 0; i < num; i++) res[*returnSize][i] = buffer[i];
            (*returnSize)++;
            // pop stack
            pointer--;
            curr_i = stack_i[pointer];
            curr_target = stack_tar[pointer];
            curr_status = status[pointer];
            num--;
            continue;
        }
        if (curr_status == 0 && curr_target >= candidates[curr_i] && isComb[curr_i][curr_target - candidates[curr_i]]) {
            buffer[num++] = candidates[curr_i];
            stack_i[pointer] = curr_i;
            stack_tar[pointer] = curr_target;
            status[pointer++] = 1;
            curr_target -= candidates[curr_i];
            curr_status = 0;
        }
        else if (curr_status <= 1 && curr_i > 0 && isComb[curr_i - 1][curr_target]) {
            stack_i[pointer] = curr_i;
            stack_tar[pointer] = curr_target;
            status[pointer++] = 2;
            curr_i--;
            curr_status = 0;
        }
        else {
            // pop stack
            pointer--;
            if (pointer < 0) break;
            if (curr_i == stack_i[pointer]) num--;
            curr_i = stack_i[pointer];
            curr_target = stack_tar[pointer];
            curr_status = status[pointer];
        }
    }
    return res;
}
