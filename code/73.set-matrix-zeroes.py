class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        m = len(matrix[0])
        row = [1]*m
        column = [1]*n
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    row[j] = 0
                    column[i] = 0
                    
        for i in range(n):
            for j in range(m):
                matrix[i][j] *= row[j]
                matrix[i][j] *= column[i]
    