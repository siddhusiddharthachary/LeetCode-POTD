class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);

        for (int i = 1; i < n; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                continue;
            }

            if (rightSum[i] == leftSum[i]) {
                cnt += 2;
            } else if (abs(rightSum[i] - leftSum[i]) == 1) {
                cnt += 1;
            }
        }
        return cnt;
    }
};
