
class Solution {
public:
    int strStr(string text, string word) {
        int d = 256;
        int p = 101;
    int m = word.length();
    int n = text.length();
    int i, j;
    int word_hash = 0, text_hash = 0;
    int h = 1;

    for (i = 0; i < m-1; i++) {
        h = (h*d) % p;
    }

    for (i = 0; i < m; i++) {
        word_hash = (d * word_hash + word[i]) % p;
        text_hash = (d * text_hash + text[i]) % p;
    }

    for (i = 0; i < n-m+1; i++) {
        if (word_hash == text_hash) {
            for (j = 0; j < m; j++) {
                if (word[j] != text[i+j]) break;
            }
            if (j == m) return i;
        }
        if (i < n-m) {
            text_hash = ((text_hash - text[i] * h) * d + text[i + m]) % p;
            if (text_hash < 0) text_hash += p;
        }
    }

    return -1;
    }
};