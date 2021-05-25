class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end());
                vector<int> check = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(check[1] >= intervals[i][0]){
                check[1] = max(check[1], intervals[i][1]);
            }
            else if(check[1] < intervals[i][0]){
                merged.push_back(check);
                check = intervals[i];
            }
        }
        merged.push_back(check);
        return merged;
    }
};