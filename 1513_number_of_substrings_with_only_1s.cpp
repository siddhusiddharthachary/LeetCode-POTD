class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int ans = 0, MOD = 1e9 + 7;
        vector<long long> total(n + 1, 0);
        for (long long i = 1; i <= n; i++) {
            total[i] = (i + total[i - 1]) %MOD;
        }
        int ones = 0;
        for (char c : s) {
            if (c == '1') {
                ones++;
            } else {
                ans = (ans + total[ones]) % MOD;
                ones = 0;
            }
        }
        ans = (ans + total[ones]) % MOD;
        return ans;
    }
};
