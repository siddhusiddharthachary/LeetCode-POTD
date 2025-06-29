class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int cnt = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1, MOD = 1e9 + 7;
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                cnt = (cnt + power[r-l]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return cnt;
    }
};
