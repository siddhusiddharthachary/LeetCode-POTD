class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        heights.push_back(0); 

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }

        heights.pop_back();
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> mat(n, vector<int>(m + 1, 0));
        for (int col = 0; col < m; col++) {
            for (int row = 0; row < n; row++) {
                if (matrix[row][col] == '1') {
                    if (row - 1 >= 0)
                        mat[row][col] = (1 + (mat[row - 1][col]));
                    else
                        mat[row][col] = 1;
                }
            }
        }
        int maxArea = 0;
        for (int row = 0; row < n; row++) {
            maxArea = max(maxArea, largestRectangleArea(mat[row]));
        }

        return maxArea;
    }
};
