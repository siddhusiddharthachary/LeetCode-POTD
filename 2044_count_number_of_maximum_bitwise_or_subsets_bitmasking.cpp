class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int num : nums){
            maxOr |= num;
        }
        int totalSubsets = 1<<nums.size();
        int ans = 0;
        for(int mask = 0;mask<totalSubsets;mask++){
            int curr = 0;
            for(int i=0;i<nums.size();i++){
                if(((mask>>i)&1)==1){
                    curr|=nums[i];
                }
            }

            if(curr==maxOr){
                ans++;
            }
        }
        return ans;
    }
};
