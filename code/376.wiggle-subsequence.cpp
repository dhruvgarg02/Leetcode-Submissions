class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int i;
        if (nums.size() == 0)
        {
            return 0;
        }
        int inc = 1;
        int dec = 1;
        for (i = 1; i < nums.size(); i++)
        {   
            if (nums[i] > nums[i-1])
            {
                inc = dec + 1;
            }
            else if (nums[i] < nums[i-1])
            {
                dec = inc + 1;
            }
        }
        return max(inc, dec);
    }
};