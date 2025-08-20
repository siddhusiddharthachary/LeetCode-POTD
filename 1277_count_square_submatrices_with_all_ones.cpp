class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {        // rows
            for (int j = 0; j < matrix[0].size(); j++) { // cols
                if (matrix[i][j] && i && j) {
                    matrix[i][j] += min({matrix[i - 1][j - 1], matrix[i - 1][j],
                                         matrix[i][j - 1]});
                }
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};
