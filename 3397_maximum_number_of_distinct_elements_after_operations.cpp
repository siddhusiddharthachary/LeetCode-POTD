class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        vector<pair<long long, long long>> intervals;
        for(int x : nums){
            intervals.push_back({x-k, x+k});
        }
        sort(intervals.begin(), intervals.end());

        long long last = -9e18;
        int ans = 0;
        for(auto [L,R] : intervals){
            long long p = max(last+1, L);
            if(p<=R){
                ans++;
                last=p;
            }
        }
        return ans;
    }
};
