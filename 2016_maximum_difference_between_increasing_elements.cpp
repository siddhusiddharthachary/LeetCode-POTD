class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[n - 1];
        int maxDiff = INT_MIN;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] != maxi) {
                maxDiff = max(maxDiff, maxi - nums[i]);
            }
            maxi = max(maxi, nums[i]);
        }
        return maxDiff < 0 ? -1 : maxDiff;
    }
};
