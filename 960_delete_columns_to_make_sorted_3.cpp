class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int maxi = 0;
        int n = strs.size(), m = strs[0].size();
        vector<int> dp(m, 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                bool isValid = true;
                for (int k = 0; k < n; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        isValid = false;
                        break;
                    }
                }
                if (isValid) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return m - maxi;
    }
};
