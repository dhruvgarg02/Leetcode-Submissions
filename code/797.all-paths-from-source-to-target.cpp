class Solution {
    
private:
    void dfs (int source, int destination, vector<int>& curr, vector<vector<int>>& res, vector<vector<int>>& graph) {
        if (source == destination) {
            res.push_back(curr);
            return;
        }
        
        for (auto i : graph[source]) {
            curr.push_back(i);
            dfs (i, destination, curr, res, graph);
            curr.pop_back();
        }
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> curr (1, 0);
        dfs (0, graph.size()-1, curr, res, graph);
        return res;
    }
};