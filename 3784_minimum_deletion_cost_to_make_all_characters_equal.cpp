class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long total = accumulate(cost.begin(), cost.end(), 0LL);
        vector<long long> alph(26, 0);
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            alph[c - 'a'] += cost[i];
        }
        long long maxi = 0;
        for (int i = 0; i < alph.size(); i++) {
            maxi = max(maxi, alph[i]);
        }
        return total - maxi;
    }
};
