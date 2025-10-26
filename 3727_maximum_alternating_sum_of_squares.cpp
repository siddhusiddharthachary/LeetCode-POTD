class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i=0;i<nums.size();i++) {
            if (nums[i] < 0){
                nums[i] = -nums[i];
            }
        }
        multiset<int> s(nums.begin(), nums.end());
        long long ans = 0;

        while (s.size() > 1) {
            int mn = *s.begin();
            int mx = *prev(s.end());
            ans += ((mx * mx) - (mn * mn));
            s.erase(s.begin());
            s.erase(prev(s.end()));
        }
        if(!s.empty()){
            int x = *s.begin();
            ans+=(x*x);
        }
        return ans;
    }
};©leetcode
