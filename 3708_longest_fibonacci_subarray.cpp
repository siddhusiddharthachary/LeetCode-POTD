class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=2, ans = 2, curr = 2, n = nums.size();
        while(i<n){
            if(nums[i]==(nums[i-2]+nums[i-1])){
                curr++;
                ans= max(ans, curr);
            }else{
                curr = 2;
            }
            i++;
        }
        return ans;
    }
};
