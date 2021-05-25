class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n == 1 || n==0)
    {
        return 0;
    }
    int profit[n];
    profit[0] = 0;
    int i;
    int minp = prices.front();
    int maxp = prices.back();
    for(i=1; i<n; i++)
    {
        if(minp > prices[i])
        {
            minp = prices[i];
        }
        profit[i] = max(profit[i-1], prices[i] - minp);
    }
    for(i=n-2; i>=0; i--)
    {
        if(maxp < prices[i])
        {
            // right = max(max - price[i])
            maxp = prices[i];
        }
        profit[i] = max(profit[i+1], profit[i] + maxp - prices[i]);
    }
    int result = profit[0];
    return result;
    }
};