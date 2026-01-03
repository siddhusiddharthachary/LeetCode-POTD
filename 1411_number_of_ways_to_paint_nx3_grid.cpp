class Solution {
public:
    int numOfWays(int n) {
        int MOD = 1e9 + 7;
        vector<int> dp2(5001, 0);
        vector<int> dp3(5001, 0);
        dp2[1] = 6;
        dp3[1] = 6;
        for (int i = 2; i <= n; i++) {
            dp2[i] = ((3LL * dp2[i - 1]) + (2LL * dp3[i - 1])) % MOD;
            dp3[i] = ((2LL * dp2[i - 1]) + (2LL * dp3[i - 1])) % MOD;
        }
        return (dp2[n] + dp3[n])%MOD;
    }
};
