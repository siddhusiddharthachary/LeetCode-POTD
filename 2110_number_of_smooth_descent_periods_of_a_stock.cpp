class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> cnt(n + 1, 0);
        for (int i = 1; i < cnt.size(); i++) {
            cnt[i] = (cnt[i - 1] + i);
        }
        long long ans = 0;
        long long curr = 1;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1) {
                curr++;
            } else {
                ans += cnt[curr];
                curr = 1;
            }
        }
        ans += cnt[curr];
        return ans;
    }
};
