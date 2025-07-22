class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0, r = 0, maxSum = INT_MIN, n = nums.size(), sum = 0;
        set<int> st;
        while (r < n) {
            while (st.find(nums[r]) != st.end()) {
                st.erase(nums[l]);
                sum -= nums[l];
                l++;
            }
            sum += nums[r];
            st.insert(nums[r]);
            r++;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
