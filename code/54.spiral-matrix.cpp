class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int r = matrix.size();
        int c = matrix[0].size();
        int i, j;
        int cnt = 0;
        int max_row = r-1;
        int max_col = c-1;
        int min_row = 0;
        int min_col = 0;
        while(cnt < r*c){
            for(i = min_col; i <= max_col and cnt < r*c; i++){
                v.push_back(matrix[min_row][i]);
                cnt++;
            }
            min_row++;
            for(i = min_row; i <= max_row and cnt < r*c; i++){
                v.push_back(matrix[i][max_col]);
                                cnt++;
            }
            max_col--;
            for(i = max_col; i >= min_col and cnt < r*c; i--){
                v.push_back(matrix[max_row][i]);
                                cnt++;
            }
            max_row--;
            for(i = max_row; i >= min_row and cnt < r*c; i--){
                v.push_back(matrix[i][min_col]);
                                cnt++;
            }
            min_col++;
        }
        return v;
    }
};