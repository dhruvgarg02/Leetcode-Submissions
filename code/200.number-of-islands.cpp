class Solution {
    vector<int> dir {0, 1, 0, -1, 0}; 
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs (grid, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i >= 0 and j >= 0 and i < grid.size() and j < grid[0].size() and grid[i][j] == '1') {
            grid[i][j] = '0';
            for (int k = 0; k < 4; k++) {
                dfs(grid, i+dir[k], j+dir[k+1]);
            }
        }
    }
};