class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        long long MOD = 1e9+7;
        long long cnt = 0;
        if(k==0) return n;
        map<int, int> mp;

        for (int num : nums) {
            mp[num]++;
        }
        vector<pair<int, int>> v(mp.begin(), mp.end());
        int sz = v.size();
        long long remaining = v.back().second;
        for (int i = sz - 2; i >= 0; i--) {
            if (remaining >= k) {
                cnt= (cnt + v[i].second) % MOD;
            }
            remaining = (remaining + v[i].second) ;
        }
        return cnt;
    }
};
