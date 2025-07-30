class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int maxSize = 0, size = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) {
                size++;
                maxSize = max(maxSize, size);
            } else {
                size = 0;
            }
        }
        return maxSize;
    }
};
