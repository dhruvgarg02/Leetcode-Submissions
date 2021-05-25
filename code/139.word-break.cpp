class Solution {
public:
    bool dictionaryContains(string word, vector<string> &B)
    {
    int size = B.size();
    for (int i = 0; i < size; i++)
        if (B[i].compare(word) == 0)
            return true;
    return false;
    }
    
    bool wordBreak(string s1, vector<string>& B) {
    int m = s1.size();
    if (m == 0)
        return 1;
    bool dp[m+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i <= m; i++)
    {
        for(int j=i-1;j>=0;j--)
          if(dp[j] && dictionaryContains(s1.substr(j,i-j), B))
            dp[i] = 1;
    }
    return dp[m];
    }
};