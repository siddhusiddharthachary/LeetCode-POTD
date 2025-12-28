class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<int> mini(n);
        mini[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mini[i] = min(nums[i], mini[i + 1]);
        }

        vector<long long> preSum(n);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            preSum[i] = preSum[i - 1] + nums[i];
        }

        long long maxScore = LLONG_MIN;
        for (int i = 0; i < n - 1; i++) {
            long long curr = preSum[i] - mini[i + 1];
            maxScore = max(maxScore, curr);
        }

        return maxScore;
    }
};
