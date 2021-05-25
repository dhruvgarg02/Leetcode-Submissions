class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        rec(nums, 0, temp, res);
        set<vector<int>> s;
        for(auto i : res) {
            sort(i.begin(), i.end());
            s.insert(i);
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }

private:
    void rec(vector<int>& nums, int index, vector<int>& temp, vector<vector<int>>& res){
        if (index == nums.size()) {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        rec(nums, index+1, temp, res);
        temp.pop_back();
        rec(nums, index+1, temp, res);
    }
};