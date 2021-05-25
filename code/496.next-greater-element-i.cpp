class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        stack<int> s;
        for(int n: nums2){
            while(s.size() and s.top()<n){
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> res;
        for(int i: nums1){
            res.push_back(m.count(i) ? m[i] : -1);
        }
        return res;
    }
};