class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for(int i : nums) {
            int n = res.size();
            for(int j = 0; j < n; j++) {
                res.push_back(res[j]);
                res.back().push_back(i);
            }
        }
        return res;
    }
};


