class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i;
        int j;
        int temp;
        int n = matrix.size();
        for(i = 0; i < n/2; i++){
            for(j = 0; j < n; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[n-i-1][j];
                matrix[n-i-1][j] = temp;
            }
        }
        for(i = 0; i < n; i++){
            for(j = i; j < n; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};