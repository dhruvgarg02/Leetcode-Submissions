class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0;
        int r = 0;
        int res = 0;
        int n = s.length();
        int maxCharCount = 0;
        for(r = 0; r < n; r++) {
            count[s[r] - 'A']++;
            maxCharCount = max(maxCharCount, count[s[r]-'A']);
            while(r-l-maxCharCount+1 > k) {
                count[s[l] - 'A']--;
                l++;
                for(int i = 0; i < 26; i++)
                    maxCharCount = max(maxCharCount, count[i]);
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};