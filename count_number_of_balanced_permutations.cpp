class Solution {
public:
    constexpr static long long MOD = 1e9 + 7;

    vector<vector<long long>> computeCombinations(int max_n) {
        vector<vector<long long>> comb(max_n + 1,
                                       vector<long long>(max_n + 1, 0));
        for (int i = 0; i <= max_n; ++i) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
        return comb;
    }

    long long dfs(int pos, int currOddSum, int oddLeft, const vector<int>& freq,
                  const vector<int>& psum,
                  const vector<vector<long long>>& comb,
                  long long memo[10][1001][501], int targetSum) {

        if (oddLeft < 0 || psum[pos] < oddLeft || currOddSum > targetSum) {
            return 0;
        }
        if (pos > 9) {
            return (currOddSum == targetSum && oddLeft == 0) ? 1 : 0;
        }
        if (memo[pos][currOddSum][oddLeft] != -1) {
            return memo[pos][currOddSum][oddLeft];
        }

        int evenLeft = psum[pos] - oddLeft;
        long long res = 0;
        for (int k = max(0, freq[pos] - evenLeft); k <= min(freq[pos], oddLeft);
             ++k) {
            long long ways =
                comb[oddLeft][k] * comb[evenLeft][freq[pos] - k] % MOD;
            res = (res + ways * dfs(pos + 1, currOddSum + k * pos, oddLeft - k,
                                    freq, psum, comb, memo, targetSum)) %
                  MOD;
        }

        return memo[pos][currOddSum][oddLeft] = res;
    }

    int countBalancedPermutations(string num) {
        int n = num.size();
        vector<int> freq(10, 0);
        int totalSum = 0;

        for (char c : num) {
            int d = c - '0';
            freq[d]++;
            totalSum += d;
        }

        if (totalSum % 2 != 0) {
            return 0;
        }

        int targetSum = totalSum / 2;
        int maxOddPositions = (n + 1) / 2;

        vector<int> psum(11, 0);
        for (int i = 9; i >= 0; --i) {
            psum[i] = psum[i + 1] + freq[i];
        }

        auto comb = computeCombinations(maxOddPositions);

        long long memo[10][1001][501];
        memset(memo, -1, sizeof(memo));

        return dfs(0, 0, maxOddPositions, freq, psum, comb, memo, targetSum);
    }
};
