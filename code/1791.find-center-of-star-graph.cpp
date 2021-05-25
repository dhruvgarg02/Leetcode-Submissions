typedef pair<int, int> pii;
class Solution {
    
private:
    bool dfs (int i, int j, int mid, int n, int m, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        
        if (i == n-1 and j == m-1) return true; // reached bottom-right cell
        
        visited[i][j] = 1;
        bool option = 0;
        
        if (i > 0 and visited[i-1][j] == 0 and abs (heights[i][j] - heights[i-1][j]) <= mid)
            option = option or dfs (i-1, j, mid, n, m, heights, visited);
        if (j > 0 and visited[i][j-1] == 0 and abs (heights[i][j] - heights[i][j-1]) <= mid)
            option = option or dfs (i, j-1, mid, n, m, heights, visited);
        if (i < n-1 and visited[i+1][j] == 0 and abs (heights[i][j] - heights[i+1][j]) <= mid)
            option = option or dfs (i+1, j, mid, n, m, heights, visited);
        if (j < m-1 and visited[i][j+1] == 0 and abs (heights[i][j] - heights[i][j+1]) <= mid)
            option = option or dfs (i, j+1, mid, n, m, heights, visited);
        
        return option;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int start = 0, end = INT_MAX, ans = INT_MAX, n = heights.size(), m = heights[0].size();
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            vector<vector<bool>> visited (n, vector<bool> (m, 0));
            
            if (dfs (0, 0, mid, n, m, heights, visited)) {
                ans = min (ans, mid);
                end = mid - 1;
            }
            
            else start = mid + 1;
        }
        
        return ans;
    }
};