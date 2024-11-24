// There is a dynamic programming approach
// https://redquark.org/leetcode/0010-regular-expression-matching/
// Or memorize isMatch for substring s[idxs:], p[idxp:]
// I guess the time complexity is similar

inline bool isMatchChar(char s, char p) {
    return ((p == '.') && (s != 0)) || (s == p);
}

bool isMatch(char* s, char* p) {
    int idxs = 0, idxp = 0;
    //printf("%s %s\n", s, p);
    while (p[idxp]) {
        if (p[idxp + 1] == '*') { 
            do {
                if (isMatch(s + idxs, p + idxp + 2)) return true;
                if (!isMatchChar(s[idxs], p[idxp])) return false;
                idxs++;
            } while(true);
        }
        else if (!isMatchChar(s[idxs], p[idxp])) return false;
        else {
            idxs++;
            idxp++;
        }
    }
    if (s[idxs] == 0 && p[idxp] == 0) return true;
    else return false;
}
