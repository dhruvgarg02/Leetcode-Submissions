class Solution {
public:

    bool dfs(unordered_map<int, vector<int>>& adjList, int curr, vector<int>& visited, int parent) {
        
        if(find(visited.begin(), visited.end(), curr) != visited.end())
            return true;
        visited.push_back(curr);
        for (auto i : adjList[curr]) {
            if (i == parent) continue;
            if (dfs(adjList, i, visited, curr)) return true;
        }
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> adjList;
        vector<int> visited;
        
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
            
            if (dfs (adjList, u, visited, -1))
                return {u, v};
            
            visited.clear();
        }
        
        return {};
    }
};