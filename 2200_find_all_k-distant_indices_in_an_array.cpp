class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keyIndices;
        for(int i=0;i<n;i++){
            if(nums[i]==key) keyIndices.push_back(i);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j : keyIndices){
                if(abs(i-j)<=k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
