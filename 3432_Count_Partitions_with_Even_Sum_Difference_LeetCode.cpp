class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        for (int i = 0; i < n - 1; i++) {
            int left = nums[i], right = nums[n - 1] - nums[i];
            if (abs(left - right) % 2 == 0)
                cnt++;
        }
        return cnt;
    }
};
