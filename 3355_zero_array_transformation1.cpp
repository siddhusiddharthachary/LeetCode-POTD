class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> preSum(n + 1);
        for (auto q : queries) {
            int l = q[0], r = q[1];
            preSum[l]--;
            preSum[r+1]++;
        }
        for (int i = 1; i < preSum.size(); i++) {
            preSum[i] += preSum[i - 1];
        }
        for (int i = 0; i < n; i++) {
            if ((nums[i] + preSum[i]) > 0)
                return false;
        }
        return true;
    }
};
