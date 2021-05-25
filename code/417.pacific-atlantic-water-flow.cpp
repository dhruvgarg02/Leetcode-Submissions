class Solution {
    vector<int> directions {0, 1, 0, -1, 0};
    
private:
    void dfs(vector<vector<int>>& heights, int i, int j, int prev, vector<vector<bool>>& ocean) {
        if (i < 0 or i >= ocean.size() or j < 0 or j >= ocean[0].size()) return;
        if (ocean[i][j] or heights[i][j] < prev) return;
        
        ocean[i][j] = 1;
        
        for (int d = 0; d < 4; d++) {
            dfs (heights, i + directions[d], j + directions[d+1], heights[i][j], ocean);
        }
    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> res;
        
        vector<vector<bool>> pacific (n, vector<bool> (m, 0));
        vector<vector<bool>> atlantic (n, vector<bool> (m, 0));
        
        
        for (int i = 0; i < m; i++) {
            dfs (heights, 0, i, INT_MIN, pacific);
            dfs (heights, n-1, i, INT_MIN, atlantic);
        }
        
        for (int i = 0; i < n; i++) {
            dfs (heights, i, 0, INT_MIN, pacific);
            dfs (heights, i, m-1, INT_MIN, atlantic);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (pacific[i][j] and atlantic[i][j])
                    res.push_back({i, j});
        }
        
        return res;
    }
};