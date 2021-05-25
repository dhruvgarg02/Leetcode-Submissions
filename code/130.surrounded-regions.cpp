class Solution {
public:
    vector<int> directions {0, 1, 0, -1, 0};
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] != 'O') return;
        board[i][j] = '#';
        for (int k = 0; k < 4; k++)
            dfs (board, i + directions[k], j + directions[k+1]);
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfs (board, 0, i);
            if (board[n-1][i] == 'O')
                dfs (board, n-1, i);
        }
        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs (board, i, 0);
            if (board[i][m-1] == 'O')
                dfs (board, i, m-1);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }

    }
};