class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        int n = nums.size();
        
        for(int i = 0; i < n-2; i++) {
            int lo = i + 1;
            int hi = n - 1;
            int sum = -nums[i];
            if(i > 0 and nums[i] == nums[i-1]) continue;
            while(lo < hi){
                if(nums[lo] + nums[hi] == sum){
                    
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[lo]);
                    v.push_back(nums[hi]);
                    res.push_back(v);
                    
                    while(lo < hi and nums[lo] == nums[lo+1]) lo++;
                    while(lo < hi and nums[hi] == nums[hi-1]) hi--;
                    lo++; hi--;
                }
                else if(nums[lo] + nums[hi] < sum) lo++;
                else hi--;
            }
        }
        return res;
    }
};