bool isValid(char* s) {
    int idx = 0, i = 0;
    char stack[10000];
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
            stack[idx++] = s[i];
        else {
            if (idx == 0) return false;
            if (s[i] - stack[idx - 1] - (s[i] != ')') != 1) return false;
            idx--;
        }
    }
    return (idx == 0);
}