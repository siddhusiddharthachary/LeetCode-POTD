class Solution {
public:
    int maxOr = 0;
    unordered_map<int,int> mp;
    void recur(int idx, vector<int> nums, int curr){
        if(idx>=nums.size()){
            maxOr = max(maxOr, curr);
            mp[curr]++;
            return;
        }
        recur(idx+1, nums, curr);
        curr|=nums[idx];
        recur(idx+1, nums, curr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        recur(0,nums, 0);
        return mp[maxOr];
    }
};
