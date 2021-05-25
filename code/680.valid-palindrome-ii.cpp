class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        for (int l = 0, r = n-1; l < r; l++, r--) {
            if (s[l] != s[r])
                return (ispalindrome(s, l+1, r) or ispalindrome(s, l, r-1));
        }
        return true;
    }
private:
    bool ispalindrome(string s, int l, int r) {
        for (int i = l, j = r; i < j; i++, j--)
            if (s[i] != s[j]) return false;
        return true;
    }
};