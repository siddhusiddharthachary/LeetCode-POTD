class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> heights(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i=0;i<m;i++){
            heights[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                heights[i][j] += matrix[i][j]!=0 ? (matrix[i][j] + heights[i-1][j]) : 0;
            }
        }
        
        int maxArea = 0;
        for(int i=0;i<heights.size();i++){
            vector<int> curr(heights[i].begin(), heights[i].end());
            sort(curr.begin(), curr.end(), greater<int>());
            for(int i=0;i<curr.size();i++){
                maxArea = max(maxArea, (curr[i] * (i + 1)));
            }
        }
        return maxArea;
    }
};
