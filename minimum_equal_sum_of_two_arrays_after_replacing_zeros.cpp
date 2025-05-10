class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, zeroesInOne = 0, zeroesInTwo = 0;
        for(auto it : nums1){
            if(it==0){
                zeroesInOne++;
                sum1++;
            }
            sum1+=it;
        }
        for(auto it : nums2){
            if(it==0){
                zeroesInTwo++;
                sum2++;
            }
            sum2+=it;
        }
        if(zeroesInOne==0 && sum1<sum2) return -1;
        if(zeroesInTwo==0 && sum2<sum1) return -1;
        return max(sum1, sum2);
        return 0;
    }
};
