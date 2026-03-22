class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            int left = 0, right = n-1;
            while(left<right){
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0;i<4;i++){
            rotate(mat);
            if(mat==target) return true;
        }
        return false;
    }
};
