class Solution {
public:
    set<int> validDepths;
    long long dp[65][2][65];
    string num = "";

    set<int> computeValidPopcounts(int k) {
        set<int> valid;
        for (int c = 1; c <= 64; ++c) {
            int x = c, depth = 0;
            while (x > 1) {
                x = __builtin_popcount(x);
                ++depth;
            }
            if (depth == k - 1) {
                valid.insert(c);
            }
        }
        return valid;
    }

    void binary(long long n) {
        while (n > 0) {
            num += (n % 2) + '0';
            n /= 2;
        }
        reverse(num.begin(), num.end());
    }
    long long solve(int pos, bool tight, int countOf1s) {
        if (pos == num.size()) {
            return validDepths.count(countOf1s) ? 1 : 0;
        }

        if (dp[pos][tight][countOf1s] != -1)
            return dp[pos][tight][countOf1s];

        int limit = tight ? num[pos] - '0' : 1;
        long long ans = 0;

        for (int digit = 0; digit <= limit; ++digit) {
            int newTight = tight && (digit == limit);
            ans += solve(pos + 1, newTight, countOf1s + digit);
        }

        return dp[pos][tight][countOf1s] = ans;
    }

    long long popcountDepth(long long n, int k) {
        if (k == 0)
            return 1;

        validDepths = computeValidPopcounts(k);
        if (validDepths.empty())
            return 0;

        binary(n);

        memset(dp, -1, sizeof(dp));
        long long res = solve(0, true, 0);
        if (k == 1 && validDepths.count(1))
            res -= 1;
        return res;
    }
};
