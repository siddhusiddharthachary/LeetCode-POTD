class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), MOD = 1e9 + 7;
        vector<long long> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back(nums[i]);
        }
        for (auto q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            int idx = l;
            while (idx <= r) {
                arr[idx] = ((arr[idx] * v) % MOD);
                idx += k;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= (arr[i]) % MOD;
        }
        return ans;
    }
};
