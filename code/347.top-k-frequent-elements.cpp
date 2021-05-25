class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        for(auto i : mp) {
            minHeap.push({i.second, i.first});
            if(minHeap.size() > k) minHeap.pop();
        }
        
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};