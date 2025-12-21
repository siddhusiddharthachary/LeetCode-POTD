class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        vector<bool> sorted(n - 1, false);
        int dels = 0;
        for (int col = 0; col < m; col++) {
            bool needDel = false;

            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    needDel = true;
                    break;
                }
            }
            if (needDel) {
                dels++;
                continue;
            }

            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] < strs[row + 1][col]) {
                    sorted[row] = true;
                }
            }
        }

        return dels;
    }
};
