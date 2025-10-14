class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> incStart(n, 1);
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i+1] > nums[i]) incStart[i] = incStart[i+1] + 1;
            else incStart[i] = 1;
        }
        for (int i = 0; i + 2*k - 1 < n; ++i) {
            if (incStart[i] >= k && incStart[i + k] >= k) return true;
        }
        return false;
    }
};
