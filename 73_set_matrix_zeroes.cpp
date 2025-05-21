class Solution {
public:
    void setRowZero(vector<vector<int>>& matrix, int row) {
        int i = row, j = 0, n = matrix[0].size();
        for (j; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    void setColZero(vector<vector<int>>& matrix, int col) {
        int i = 0, j = col, m = matrix.size();
        for (i; i < m; i++) {
            matrix[i][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> rows, cols;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for (auto row : rows) {
            setRowZero(matrix, row);
        }
        for (auto col : cols) {
            setColZero(matrix, col);
        }
    }
};
