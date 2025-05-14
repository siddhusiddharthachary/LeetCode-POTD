class Solution {
public:

    const int MOD = 1e9 + 7;

    vector<vector<long long>> multiply(vector<vector<long long>>& a,
                                       vector<vector<long long>>& b) {
        int n = a.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    vector<vector<long long>> matrix_pow(vector<vector<long long>>& mat,
                                         int power) {
        int n = mat.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            res[i][i] = 1; 
        }
        while (power > 0) {
            if (power % 2 == 1) {
                res = multiply(res, mat);
            }
            mat = multiply(mat, mat);
            power /= 2;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        vector<vector<long long>> mat(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            int k = nums[i];
            for (int j = 1; j <= k; ++j) {
                int next_char = (i + j) % 26;
                mat[next_char][i]++;
            }
        }

        vector<vector<long long>> resMatrix = matrix_pow(mat, t);

        vector<long long> ans(26, 0);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                ans[i] = (ans[i] + resMatrix[i][j] * cnt[j]) % MOD;
            }
        }

        long long total = 0;
        for (long long num : ans) {
            total = (total + num) % MOD;
        }

        return total;
    }
};
