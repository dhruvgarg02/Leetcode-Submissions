class Solution {
public:
    int subarraySum(vector<int>& v, int k) {
        int res = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
    int curr_sum = 0;
    for (int i = 0 ; i < v.size(); i++) {
        curr_sum += v[i];
        if (mp.find(curr_sum-k) != mp.end()) {
            res += mp[curr_sum-k];
        }
        mp[curr_sum]++;
    }
    return res;
    }
};