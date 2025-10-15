class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2 || n==3) return 1;
        
        int prev =1 , curr=1 , maxCnt =1, index=1;
        while(index<n){
            if(nums[index]>nums[index-1]){
                curr++;
            }else{
                prev=curr;
                curr=1;
            }
            if(prev==curr){
                maxCnt = max(maxCnt,curr);
            }else{
                int currPrevMaxi = min(curr,prev);
                int splitMaxi = max(curr/2,prev/2);
                int maxi = max(currPrevMaxi,splitMaxi);
                maxCnt = max(maxCnt,maxi);
            }
            index++;
        }
        return maxCnt;
    }
};
