class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        long long ans = 0LL;
        for (int i = 0; i < k; i++) {
            nums[i] -= i;
            ans += (nums[i] > 0 ? nums[i] : 0);
        }
        return ans;
    }
};
