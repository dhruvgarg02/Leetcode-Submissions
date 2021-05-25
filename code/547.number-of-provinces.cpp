class Solution {
public:
    void dfs (vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = 1;
        for (int j = 0; j < isConnected.size(); j++)
            if (i != j and isConnected[i][j] and !visited[j])
                dfs(isConnected, visited, j);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited (isConnected.size(), 0);
        int count = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                count++;
                dfs (isConnected, visited, i);
            }
        }
        return count;
    }
};