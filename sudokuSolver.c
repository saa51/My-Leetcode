bool isValidCell(char** board, int i, int j) {
    for (int k = 0; k < 9; k++) {
        if (j != k && board[i][j] == board[i][k]) return false;
        if (i != k && board[i][j] == board[k][j]) return false;
        if ((k / 3 != i % 3 || k % 3 != j % 3) && board[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3] == board[i][j]) return false;
    }
    return true;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    int stack[81];
    int pointer = 0;
    int idx = 0;
    while (idx < 81) {
        if (board[idx / 9][idx % 9] == '.') break;
        idx++;
    }
    while (idx < 81) {
        int i = idx / 9, j = idx % 9;
        char trial = (board[i][j] == '.') ? '1': (board[i][j] + 1);
        for (; trial <= '9'; trial++) {
            board[i][j] = trial;
            if (isValidCell(board, i, j)) break;
        }
        if (trial > '9') {
            idx = stack[--pointer];
            board[i][j] = '.';
        }
        else {
            stack[pointer++] = idx;
            while (idx < 81) {
                if (board[idx / 9][idx % 9] == '.') break;
                idx++;
            }
        }
    }
}