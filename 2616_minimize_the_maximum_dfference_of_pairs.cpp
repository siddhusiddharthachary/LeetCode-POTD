class Solution {
public:
    typedef long long ll;
    int countPairs(vector<int> nums, int diff) {
        int i = 0, cnt = 0, n = nums.size();
        while (i < n-1) {
            if (nums[i+1] - nums[i] <= diff) {
                cnt++;
                i++; 
            }
            i++;
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0, high = (nums[n - 1] - nums[0]);
        int ans=0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = countPairs(nums, mid);
            if (cnt >= p) {
                high = mid-1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
