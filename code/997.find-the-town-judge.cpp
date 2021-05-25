class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1) return 1;
        unordered_set<int> s;
        vector<int> v (n+1, 0);
        for (auto t : trust) {
            s.insert(t[0]);
            v[t[1]]++;
        }
        for (int i = 0; i < v.size(); i++) { 
            if (v[i] == n-1) {
                if (find(s.begin(), s.end(), i) != s.end()) continue;
                return i;
            }
        }
        return -1;
    }
};