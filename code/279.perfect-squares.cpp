class Solution {
public:
    int numSquares(int n) {
    if(n<=3)
        return n;
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 4; i < n+1; i++)
    {
        dp[i] = i;
        for(int x = 1; x*x <= i; x++)
        {
            dp[i] = min(1 + dp[i-x*x], dp[i]);
        }
    }
    return dp[n];
    }
};